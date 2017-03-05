#include <string.h>				// for strcmp, strstr
#include <stdio.h>
#include <stdarg.h>

#include "microrl.h"
#include "microrl_func.h"
#include "stm32f1xx_hal.h"
#include "usb_device.h"
#include "usbd_cdc_if.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "semphr.h"
#include "cmsis_os.h"


//Define this macros with correct write/read terminal functions
//#define microrl_getChar			USB_GetChar
//#define microrl_sendString		USB_SendString

/* Таблица команд консоли */
typedef struct _console_cmd_t
{
	char * name;				/* Имя команды */
	void   (*console_cmd)(); 	/* Указатель на функцию команды консоли */
} console_cmd_t;

static const console_cmd_t cmd_keyworld[] =
{
	{ "help",		&cmdHelp 			},
//	{ "status",		&cmdStatus 			},
//	{ "os",			&cmdOs	 			},
//	{ "reboot",		&cmdReboot			},
//	{ "mode",		&mlMode				},
//	{ "telemetry",	&mlTelemetryStat	},
//	{ "modem",		&modemStat			},
//	{ "rc",			&rcChannelCmd		},
//	{ "engine",		&engineCmd			},
//	{ "config",		&cmdConfig			},
//	{ "setting",	&cmdSetting			},
//	{ "default",	&cmdDefaults		},
//	{ "mixer",		&cmdMixer			},
//	{ "save",		&cmdSave			},
//	{ "load",		&cmdLoad			},
//	{ "beep",		&cmdBeep			},
//	{ "imu",		&canImuTrim			},
//	{ "can",		&canStatsPrint		},
//	{ "objects",	&objectsPrint		},
//	{ "interval",	&telemetryInterval	},
//	{ "dir",		&fatDir				},
//	{ "echo",		&fatEcho			},
//	{ "rm",			&fatDelete			},
//	{ "wp",			&wpPrint			},
//	{ "wind",		&windCmd			},
//	{ "mission",	&missionPrint		},
//	{ "df",			&flashCmd			},
//	{ "ftest",		&fatTest			},
//	{ "sync",		&cmdSync			},
//	{ "sensor",		&cmdSensor			},
//	{ "version",	&devVersion			},
//	{ "bpuss",		&cmdBpuss			},
};

// 'engine' subcommand argements
static const char * engine_key[] =
{
	"ignition",
	"pump",
	"rpm",
	"choke",
	"throttle",
	"start",
	"stop",
};

#define _NUM_OF_CMD 	(sizeof(cmd_keyworld) / sizeof(cmd_keyworld[0]))
#define _NUM_OF_ENGINE_SCMD (sizeof(engine_key) / sizeof(engine_key[0]))

// array for comletion
char * compl_world [_NUM_OF_CMD + 1];

// print to stream callback
void print (const char * str)
{
//	VCP_DataTx((uint8_t *)str, strlen(str));
	CDC_Transmit_FS((uint8_t *)str, strlen(str));
	vTaskDelay(1);
}

int fc_printf(const char * fmt, ...)
{
	int n = 0;
    va_list va;

    va_start(va, fmt);

//	if (dev == CONSOLE_STDOUT)
		n = vprintf(fmt, va);
//	if (dev == CONSOLE_MAVLINK)
//		n = trmPrintf(fmt, va);

    va_end(va);

    return n;
}

int consoleExecute(int argc, const char * const * argv)
{
	int i;

	for(i = 0; i < _NUM_OF_CMD; i++)
	{
		if (strcasecmp(argv[0], cmd_keyworld[i].name) == 0)		// Сравниваем имя команды
		{
			if (cmd_keyworld[i].console_cmd)
				cmd_keyworld[i].console_cmd(argc, argv);	// Вызываем функцию команды
			return 0;
		}
	}
//	HAL_GPIO_WritePin(LED_STAT_GPIO_Port, LED_STAT_Pin, GPIO_PIN_SET);
//	fc_printf("Unknown command '%s'\n\r", argv[0]);
//	microrl_printString(const char *str);
//	microrl_printStringWithEndl("Unknown command");
	fc_printf("Unknown command '%s'\n\r", argv[0]);
	return 0;
}

//*****************************************************************************
// execute callback for microrl library
// do what you want here, but don't write to argv!!! read only!!
int execute (int argc, const char * const * argv)
{
	return consoleExecute(argc, argv);
}

terminalFunc_t terminalFuncArray[microrlNUM_OF_TERMINAL_FUNC];
int terminalFuncArrayIndex = 0;

/* The queue used to store command line. */
static xQueueHandle xQueueCmdBuffer = NULL;
microrl_t rl;					// Main terminal object
microrl_t * prl = &rl;

static void prv_registerBasicTerminalFuncs();
static int prv_getFuncArrayIndex(const char * name);
static void prv_printMainHelp();
static void prv_printTerminalFuncHelp(const char *name);
void microrl_sendString (const char * str);

static int prv_execute(int argc, const char * const * argv);
#ifdef _USE_COMPLETE
static char ** prv_complet (int argc, const char * const * argv);
#endif
#ifdef _USE_CTLR_C
static void prv_sigint (void);
#endif

//Базовые терминальные функции
//static int prv_TerminalFunc_about(int argc, const char * const * argv);
//static int prv_TerminalFunc_help(int argc, const char * const * argv);
//static int prv_TerminalFunc_clear(int argc, const char * const * argv);

void consoleInit(void)
{
	xQueueCmdBuffer = xQueueCreate(16, sizeof(char));
}


void microrl_terminalProcess()
{
	uint8_t ch;

	if (xQueueCmdBuffer)
	{
		xQueueReceive(xQueueCmdBuffer, &ch, portMAX_DELAY);
		microrl_insert_char (prl, (int)ch);
	}
}

//void microrl_registerExecuteFunc(int (*func)(int, const char* const*), const char* name, const char* help)
//{
//	assert_param(terminalFuncArrayIndex < microrlNUM_OF_TERMINAL_FUNC);
//
//	terminalFuncArray[terminalFuncArrayIndex].func = func;
//	terminalFuncArray[terminalFuncArrayIndex].name = name;
//	terminalFuncArray[terminalFuncArrayIndex].help = help;
//
//	terminalFuncArrayIndex++;
//}

void microrl_printString(const char *str)
{
	microrl_sendString(str);
}

void microrl_printStringWithEndl(const char *str)
{
	microrl_sendString(str);
	microrl_sendString(ENDL);
}

void microrl_printEndl()
{
	microrl_sendString(ENDL);
}

//static void prv_registerBasicTerminalFuncs()
//{
//	microrl_registerExecuteFunc(prv_TerminalFunc_about, "about", NULL);
//	microrl_registerExecuteFunc(prv_TerminalFunc_help, "help", "This function allows to view the available options and their descriptions.");
//	microrl_registerExecuteFunc(prv_TerminalFunc_clear, "clear", "This function clears the screen.");
//}
//
//static int prv_getFuncArrayIndex(const char * name)
//{
//	int i;
//	for (i = 0; i < terminalFuncArrayIndex; ++i) {
//		if (strcmp(name, terminalFuncArray[i].name) == 0)	{
//			return i;
//		}
//	}
//	return (-1);
//}

//static int prv_execute(int argc, const char * const * argv)
//{
//	int funcIndex;
//
//	funcIndex = prv_getFuncArrayIndex(argv[0]);
//	if (funcIndex == (-1))	{
//		microrl_printStringWithEndl("Unknown command. Type \"help\" to see available commands");
//		return (-1);
//	}
//	return terminalFuncArray[funcIndex].func(--argc, ++argv);
//}

#ifdef _USE_COMPLETE
//TODO simplify this. Quite difficult.
//static char ** prv_complet (int argc, const char * const * argv)
//{
//	static char * compl_world [microrlNUM_OF_TERMINAL_FUNC + 1];
//	int j = 0, i;
//	compl_world[0] = NULL;
//	if (argc == 1)	{
//		char * bit = (char*)argv [argc-1];
//		for (i = 0; i < terminalFuncArrayIndex; i++) {
//			if (strstr(terminalFuncArray[i].name, bit) == terminalFuncArray[i].name) {
//				compl_world [j++] = (char*)(terminalFuncArray[i].name);
//			}
//		}
//	}
//	compl_world [j] = NULL;
//	return compl_world;
//}
//*****************************************************************************
// completion callback for microrl library
char ** complet (int argc, const char * const * argv)
{
	int j = 0;

	compl_world [0] = NULL;

	// if there is token in cmdline
	if (argc == 1) {
		// get last entered token
		char * bit = (char*)argv [argc-1];
		// iterate through our available token and match it
		for (int i = 0; i < _NUM_OF_CMD; i++) {
			// if token is matched (text is part of our token starting from 0 char)
			if (strstr(cmd_keyworld[i].name, bit) == cmd_keyworld[i].name) {
				// add it to completion set
				compl_world [j++] = cmd_keyworld[i].name;
			}
		}
	}	else if ((argc > 1) && ((strcmp (argv[0], "engine") == 0))) { // if command needs subcommands
		// iterate through subcommand
		for (int i = 0; i < _NUM_OF_ENGINE_SCMD; i++) {
			if (strstr (engine_key [i], argv [argc-1]) == engine_key [i]) {
				compl_world [j++] = engine_key [i];
			}
		}
	} else { // if there is no token in cmdline, just printf all available token
		for (; j < _NUM_OF_CMD; j++) {
			compl_world[j] = cmd_keyworld[j].name;
		}
	}

	// note! last ptr in array always must be NULL!!!
	compl_world [j] = NULL;
	// return set of variants
	return compl_world;
}
#endif

#ifdef _USE_CTLR_C
static void prv_sigint (void)
{
	NVIC_SystemReset();
}
#endif

//static int prv_TerminalFunc_about(int argc, const char * const * argv)
//{
//	microrl_printString("Microrl based terminal. Ver. ");
//	microrl_printStringWithEndl(MICRORL_LIB_VER);
//	return 0;
//}

//static int prv_TerminalFunc_help(int argc, const char * const * argv)
//{
//	switch (argc)
//	{
//	case 0:
//		prv_printMainHelp();
//		break;
//	case 1:
//		prv_printTerminalFuncHelp(argv[0]);
//		break;
//	default:
//		microrl_printStringWithEndl("Help is available only for high-level commands. It isn't available for subcommands.");
//		break;
//	}
//	return 0;
//}

//static void prv_printMainHelp()
//{
//	microrl_printStringWithEndl("type \"help\" <command> for more details.");
//	microrl_printEndl();
//	microrl_printStringWithEndl("Available commands:");
//	int i;
//	for (i = 0; i < terminalFuncArrayIndex; ++i) {
//		microrl_printString(terminalFuncArray[i].name);
//		microrl_printString(" ");
//	}
//	microrl_printEndl();
//}

//static void prv_printTerminalFuncHelp(const char *name)
//{
//	int funcIndex = prv_getFuncArrayIndex(name);
//	if (funcIndex == (-1))	{
//		microrl_printStringWithEndl("Command not found.");
//		return;
//	}
//	if (terminalFuncArray[funcIndex].help != NULL)	{
//		microrl_printStringWithEndl(terminalFuncArray[funcIndex].help);
//	}
//	else	{
//		microrl_printStringWithEndl("Help is not available for this command.");
//	}
//}

static int prv_TerminalFunc_clear(int argc, const char * const * argv)
{
	microrl_printString ("\033[2J");    // ESC seq for clear entire screen
	microrl_printString ("\033[H");     // ESC seq for move cursor at left-top corner
	return 0;
}

//int consoleExecute(int dev, int argc, const char * const * argv)
//{
//	int i;
//
//	for(i = 0; i < _NUM_OF_CMD; i++)
//	{
//		if (strcasecmp(argv[0], cmd_keyworld[i].name) == 0)		// Сравниваем имя команды
//		{
//			if (cmd_keyworld[i].console_cmd)
//				cmd_keyworld[i].console_cmd(dev, argc, argv);	// Вызываем функцию команды
//			return 0;
//		}
//	}

//	microrl_printString(dev, "Unknown command '%s'\n\r", argv[0]);
//	return 0;
//}

//*****************************************************************************
//	Обработчик прерывания по приходу данных по USB
void ConsoleInput(uint8_t* Buf, uint32_t Len)
{
	uint32_t i;
	portBASE_TYPE xHigherPriorityTaskWoken;

	/* We have not woken a task at the start of the ISR. */
	xHigherPriorityTaskWoken = pdFALSE;

	if (xQueueCmdBuffer)
	{
		for (i = 0; i < Len; i++)
		{
			xQueueSendFromISR(xQueueCmdBuffer, &Buf[i], &xHigherPriorityTaskWoken);
//			xQueueSend(xQueueCmdBuffer, &Buf[i], 0U);

		}
	}

//	HAL_GPIO_TogglePin(LED_ERR_GPIO_Port, LED_ERR_Pin);
	/* Now the buffer is empty we can switch context if necessary. */
	portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

// print to stream callback
void microrl_sendString (const char * str)
{
	CDC_Transmit_FS((uint8_t *)str, strlen(str));
	vTaskDelay(1);
}

void microrl_terminalInit()
{
//	prv_registerBasicTerminalFuncs();

	microrl_init(prl, print);
	microrl_set_execute_callback (prl, execute);

	#ifdef _USE_COMPLETE
	microrl_set_complete_callback (prl, complet);
	#endif

	#ifdef _USE_CTLR_C
//	microrl_set_sigint_callback (prl, prv_sigint);
	#endif
}

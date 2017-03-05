/*
 * console_cmd.c
 *
 *  Created on: 05.11.2013
 *      Author: Alex
 */
//#include "console.h"
#include "microrl_func.h"
#include "microrl.h"
//#include "mavlink.h"
//#include "aerob/version.h"
//#include "flash.h"
//#include "sensors.h"

//*****************************************************************************
void cmdHelp(int argc, const char * const * argv)
{
//    fc_printf(dev, "Aerob UAV Flight Controller v %u.%u.%u.%u " __DATE__ "/" __TIME__ NEW_LINE,
//    		(DEVICE_SW_VERSION >> 24) & 0xFF,
//    		(DEVICE_SW_VERSION >> 16) & 0xFF,
//    		(DEVICE_SW_VERSION >>  8) & 0xFF,
//    		(DEVICE_SW_VERSION >>  0) & 0xFF
//    		);
//	microrl_printStringWithEndl("RTBot");
	fc_printf("test help");

	microrl_printEndl();


//	fc_printf(dev, "Config command:\r\n");
//	fc_printf(dev, "\tdefault              - Reset to factory configuration\r\n");
//	fc_printf(dev, "\tconfig [NAME=VALUE]  - Set configuration parameter. Blank or MASK for list\r\n");
//	fc_printf(dev, "\tsetting [NAME=VALUE] - Set configuration parameter. Blank or MASK for list\r\n");
//	fc_printf(dev, "\timu [imu# x y z]     - IMU reference vector (degrees)\r\n");
//	fc_printf(dev, "\tinterval             - Telemetry message intervals\r\n");
//	fc_printf(dev, "\tmixer                - Mixer management\r\n");
//	fc_printf(dev, "\tsave [t] [FILENAME]  - Save config to flash or SD card\r\n");
//	fc_printf(dev, "\tload [t] [FILENAME]  - Load config from flash or SD card\r\n");
//
//	fc_printf(dev, "Other command:\r\n");
//	fc_printf(dev, "\tcan                  - CAN statistics\r\n");
//	fc_printf(dev, "\tobjects              - UAV objects value\r\n");
//	fc_printf(dev, "\tengine               - Engine management\r\n");
//	fc_printf(dev, "\ttelemetry            - Telemetry statistics\r\n");
//	fc_printf(dev, "\tmodem                - Modem statictics\r\n");
//	fc_printf(dev, "\twp                   - WP list\r\n");
//	fc_printf(dev, "\tmission              - Sequencer info\r\n");
//	fc_printf(dev, "\twind                 - Wind parameters\r\n");
//
//	fc_printf(dev, "Files command:\r\n");
//	fc_printf(dev, "\tdir                  - Directory list\r\n");
//	fc_printf(dev, "\techo FILENAME        - File content\r\n");
//	fc_printf(dev, "\trm FILENAME          - Delete file\r\n");
//
//	fc_printf(dev, "Service command:\r\n");
//	fc_printf(dev, "\tmode                 - Autopilot mode\r\n");
//	fc_printf(dev, "\trc                   - RC channel inputs\r\n");
//	fc_printf(dev, "\tvol, ftest           - sdcard info $ test\r\n");
//	fc_printf(dev, "\tbeep 1A_B_2C#        - Play sound. Note: A-G, #, b. Duration: 1-8. _ - pause\r\n");
}

//*****************************************************************************
/*
void cmdStatus(int dev, int argc, const char * const * argv)
{
	updateAnalogSensor();
    fc_printf(dev, "Software version   %u.%u.%u.%u " __DATE__ "/" __TIME__ NEW_LINE,
    		(DEVICE_SW_VERSION >> 24) & 0xFF,
    		(DEVICE_SW_VERSION >> 16) & 0xFF,
    		(DEVICE_SW_VERSION >>  8) & 0xFF,
    		(DEVICE_SW_VERSION >>  0) & 0xFF
    		);
    fc_printf(dev, "Mavlink library    %s\r\n", MAVLINK_BUILD_DATE);
    fc_printf(dev, "Board HW version   %d\r\n", power_sensor.hwVersion);
    fc_printf(dev, "System name        A%03u\r\n", cfg.mavlink_sysid);
    fc_printf(dev, "System Uptime      %lu seconds\r\n", (uint32_t) (millis() / 1000));
    fc_printf(dev, "BUS Voltage        %.1f V\r\n", power_sensor.busVoltage);
	fc_printf(dev, "USB Voltage        %.1f V\r\n", power_sensor.usbVoltage);
    fc_printf(dev, "Servo Voltage      %.1f V\r\n", power_sensor.srvVoltage);
    fc_printf(dev, "Modem RSSI         %d\r\n", power_sensor.rssi);
    fc_printf(dev, "MCU clock          %u MHz\r\n", (uint16_t) (SystemCoreClock / 1000000));
	fc_printf(dev, "MCU Temp           %.1f deg C\r\n", power_sensor.cpuTempetature);
	fc_printf(dev, "Alternator Temp    %.1f deg C\r\n", power_sensor.alternatorTempetature);

	uint16_t sz;
	sz = *(__IO uint16_t*)(0x1FFF7A10 + 0x12);
	fc_printf(dev, "MCU flash size     %u kB\r\n", sz);

	uint32_t ds0, ds1, ds2;
	ds0 = *(__IO uint32_t*)(0x1FFF7A10);
	ds1 = *(__IO uint32_t*)(0x1FFF7A10 + 4);
	ds2 = *(__IO uint32_t*)(0x1FFF7A10 + 8);
	fc_printf(dev, "MCU unique ID      %08lX%08lX%08lX\r\n", ds0, ds1, ds2);

	fc_printf(dev, "microSD size/free  ");
	if (sdcard.present)
		fc_printf(dev, "%u/%u Mb\r\n", sdcard.size, sdcard.free);
	else
		fc_printf(dev, "Not present\r\n");

	fc_printf(dev, "Config version     %u\r\n", cfg.version);
	fc_printf(dev, "Config size        %u Byte\r\n", sizeof(config_t));

	rtc_struct datetime;

	rtcGetTime(&datetime);

	fc_printf(dev, "RTC                %02u/%02u/%02u %02u:%02u:%02u %s\r\n",
		datetime.day,
		datetime.month,
		datetime.year,
		datetime.hour,
		datetime.minute,
		datetime.second,
		(datetime.syncFlag == RTC_SYNC ? "(SYNC)" : "(NOTSYNC)")
	);

	fc_printf(dev, "Waypoints          %u\r\n", cntWpListSize());
	fc_printf(dev, "Flight ID          %lu\r\n", cntFlightId());

	failuresPrint(dev);
}
*/
//*****************************************************************************
/*
void cmdOs(int dev, int argc, const char * const * argv)
{
	char WriteBuffer[512];

	fc_printf(dev, "Operating system status\r\n");
	fc_printf(dev, "\r\nTask\t\tState\tPrio\tStack\tNum\r\n");

	vTaskList(WriteBuffer);
	fc_printf(dev, "%s", WriteBuffer);

#if (configGENERATE_RUN_TIME_STATS == 1)
	fc_printf(dev, "\r\nTask\t\tAbs time\t%% Time\r\n");
	vTaskGetRunTimeStats(WriteBuffer);
	fc_printf(dev, "%s", WriteBuffer);

	// Выводим объем доступной для выделения свободной памяти кучи
	fc_printf(dev, "\r\n\r\nFree Heap Size: %u Bytes\r\n", xPortGetFreeHeapSize());

#endif
}
*/
//*****************************************************************************
/*
void cmdReboot(int dev, int argc, const char * const * argv)
{
	fc_printf(dev, "\r\n");
	fc_printf(dev, "Rebooting...\r\n");
	fc_printf(dev, "You have to close the terminal for 3 seconds\r\n");
	vTaskDelay(3000 / portTICK_RATE_MS);	// Delay on 3 seconds
	systemReset(false);
}
*/
//*****************************************************************************
/*
void cmdDefaults(int dev, int argc, const char * const * argv)
{
	fc_printf(dev, "Resetting to defaults...\r\n");
	configReset();
	if (configWriteFlash())
	{
		buzzerPlay("5F_F_F");
		fc_printf(dev, "\r\nError save configuration\r\n");
	}
	else
	{
		fc_printf(dev, "\r\nConfiguration saved\r\n");
	}
}
*/
//*****************************************************************************
// Print out information on every file in the subdirectory "subdir".
/*
void cmdDir(int dev, int argc, const char * const * argv)
{
	fatDir(dev, argc, argv);
}
*/
//*****************************************************************************
// Выводим на консоль содержимое файла filename
//
/*
void cmdEcho(int dev, int argc, const char * const * argv)
{
	fatEcho(dev, argc, argv);
}
*/
//*****************************************************************************
// Выводим на консоль содержимое файла filename
//
/*
void cmdRm(int dev, int argc, const char * const * argv)
{
	fatDelete(dev, argc, argv);
}
*/
//*****************************************************************************
// Печать/изменение конфигурационных параметров
//
/*
static void configPrint(int dev, const config_value_t *var, uint32_t full)
{
    int32_t value = 0;

    switch (var->type) {
        case MAVLINK_TYPE_UINT8_T:
            value = *(uint8_t *)var->ptr;
            break;

        case MAVLINK_TYPE_INT8_T:
            value = *(int8_t *)var->ptr;
            break;

        case MAVLINK_TYPE_UINT16_T:
            value = *(uint16_t *)var->ptr;
            break;

        case MAVLINK_TYPE_INT16_T:
            value = *(int16_t *)var->ptr;
            break;

        case MAVLINK_TYPE_UINT32_T:
            value = *(uint32_t *)var->ptr;
            break;

        case MAVLINK_TYPE_FLOAT:
            fc_printf(dev, "%10.3f", *(float *)var->ptr);
            if (full)
            {
                fc_printf(dev, " %10.3f", (float)var->min);
                fc_printf(dev, " %10.3f", (float)var->max);
            }
            return; // return from case for float only
    }
    fc_printf(dev, "%10ld", value);
    if (full)
        fc_printf(dev, " %10ld %10ld", var->min, var->max);
}

static void configSet(const config_value_t *var, const int32_t value)
{
    switch (var->type) {
        case MAVLINK_TYPE_UINT8_T:
        case MAVLINK_TYPE_INT8_T:
            *(char *)var->ptr = (char)value;
            break;

        case MAVLINK_TYPE_UINT16_T:
        case MAVLINK_TYPE_INT16_T:
            *(short *)var->ptr = (short)value;
            break;

        case MAVLINK_TYPE_UINT32_T:
            *(int *)var->ptr = (int)value;
            break;

        case MAVLINK_TYPE_FLOAT:
            *(float *)var->ptr = *(float *)&value;
            break;
    }
}

void cmdConfig(int dev, int argc, const char * const * argv)
{
    uint32_t i;
    uint32_t len;
    const config_value_t *val;
    char *eqptr = NULL;
    int32_t value = 0;
    float valuef = 0;

    len = strlen(argv[1]);

    if (argc == 1 || (argc == 2 && argv[1][0] == '*'))
    {
        fc_printf(dev, "Current configuration: \r\n");
        for (i = 0; i < configTableCount; i++)
        {
            val = &configTable[i];
            fc_printf(dev, "%-16s = ", configTable[i].name);
            configPrint(dev, val, argc - 1); // when argc is 2 (when * is passed as argument), it will print min/max values as well, for gui
            fc_printf(dev, NEW_LINE);
            vTaskDelay(1);
        }
    }
    else if ((eqptr = strstr(argv[1], "=")))
    {
        // has equal, set var
        eqptr++;
        value = atoi(eqptr);
        valuef = atof(eqptr);
        for (i = 0; i < configTableCount; i++)
        {
            val = &configTable[i];
            if (strncasecmp(argv[1], configTable[i].name, strlen(configTable[i].name)) == 0)
            {
            	// here we compare the float value since... it should work, RIGHT?
                if (valuef >= configTable[i].min && valuef <= configTable[i].max)
                {
                    configSet(val, configTable[i].type == MAVLINK_TYPE_FLOAT ? *(uint32_t *)&valuef : value);
                    fc_printf(dev, "%s set to ", configTable[i].name);
                    configPrint(dev, val, 0);
                    fc_printf(dev, NEW_LINE);
                }
                else
                {
                    fc_printf(dev, "ERR: Value assignment out of range\r\n");
                }
                return;
            }
        }
        fc_printf(dev, "ERR: Unknown variable name\r\n");
    }
    else
    {
    	// Рассматриваем аргумент команды как маску для названия параметров
    	for (i = 0; i < configTableCount; i++)
		{
			val = &configTable[i];
			if (strncasecmp(argv[1], configTable[i].name, len) == 0)
			{
	            fc_printf(dev, "%-16s = ", configTable[i].name);
	            configPrint(dev, val, 0);
	            fc_printf(dev, NEW_LINE);
			}
		}
    }
}

void cmdSetting(int dev, int argc, const char * const * argv)
{
    uint32_t i;
    uint32_t len;
    const config_value_t *val;
    char *eqptr = NULL;
    int32_t value = 0;
    float valuef = 0;

    len = strlen(argv[1]);

    if (argc == 1 || (argc == 2 && argv[1][0] == '*'))
    {
        fc_printf(dev, "Current settings: \r\n");
        for (i = 0; i < settingTableCount; i++)
        {
            val = &settingTable[i];
            fc_printf(dev, "%-16s = ", settingTable[i].name);
            configPrint(dev, val, argc - 1); // when argc is 2 (when * is passed as argument), it will print min/max values as well, for gui
            fc_printf(dev, NEW_LINE);
            vTaskDelay(1);
        }
    }
    else if ((eqptr = strstr(argv[1], "=")))
    {
        // has equal, set var
        eqptr++;
        value = atoi(eqptr);
        valuef = atof(eqptr);
        for (i = 0; i < settingTableCount; i++)
        {
            val = &settingTable[i];
            if (strncasecmp(argv[1], settingTable[i].name, strlen(settingTable[i].name)) == 0)
            {
            	// here we compare the float value since... it should work, RIGHT?
                if (valuef >= settingTable[i].min && valuef <= settingTable[i].max)
                {
                    configSet(val, settingTable[i].type == MAVLINK_TYPE_FLOAT ? *(uint32_t *)&valuef : value);
                    fc_printf(dev, "%s set to ", settingTable[i].name);
                    configPrint(dev, val, 0);
                    fc_printf(dev, NEW_LINE);
                }
                else
                {
                    fc_printf(dev, "ERR: Value assignment out of range\r\n");
                }
                return;
            }
        }
        fc_printf(dev, "ERR: Unknown variable name\r\n");
    }
    else
    {
    	// Рассматриваем аргумент команды как маску для названия параметров
    	for (i = 0; i < settingTableCount; i++)
		{
			val = &settingTable[i];
			if (strncasecmp(argv[1], settingTable[i].name, len) == 0)
			{
	            fc_printf(dev, "%-16s = ", settingTable[i].name);
	            configPrint(dev, val, 0);
	            fc_printf(dev, NEW_LINE);
			}
		}
    }
}

extern uint8_t			mixer_num_channel;
extern uint8_t			mixer_num_servo;
*/
//*****************************************************************************
// Вывод / изменение параметров микшера
//
/*
void cmdMixer(int dev, int argc, const char * const * argv)
{
	uint8_t i;

	if (argc == 1)	// Только команда
	{
		fc_printf(dev, "Mixer servo settings:\r\n");
		fc_printf(dev, " #   Roll  Pitch    Yaw    Thr   AUX1   AUX2   AUX3   AUX4  Min  Mid  Max Exp Spe\r\n");
		for (i = 0; i < mixer_num_channel; i++)
		{
			if (i == mixer_num_servo)
				fc_printf(dev, "Mixer motor settings:\r\n");

			fc_printf(dev, "%2d %6.3f %6.3f %6.3f %6.3f %6.3f %6.3f %6.3f %6.3f %4d %4d %4d %3d %3d\r\n", i,
					cfg.servo[i].roll,
					cfg.servo[i].pitch,
					cfg.servo[i].yaw,
					cfg.servo[i].throttle,
					cfg.servo[i].aux1,
					cfg.servo[i].aux2,
					cfg.servo[i].aux3,
					cfg.servo[i].aux4,
					cfg.servo[i].minimum,
					cfg.servo[i].middle,
					cfg.servo[i].maximum,
					cfg.servo[i].expo,
					cfg.servo[i].speed
			);
		}
	}
	else if (argc == 4)	// Команда и 3 параметра
	{
		float v;
		uint8_t p;

		i = atoi(argv[1]);
		p = atoi(argv[2]);
		v = atof(argv[3]);

		switch (p)
		{
		case 1:
			cfg.servo[i].roll = v;
			break;
		case 2:
			cfg.servo[i].pitch = v;
			break;
		case 3:
			cfg.servo[i].yaw = v;
			break;
		case 4:
			cfg.servo[i].throttle = v;
			break;
		case 5:
			cfg.servo[i].aux1 = v;
			break;
		case 6:
			cfg.servo[i].aux2 = v;
			break;
		case 7:
			cfg.servo[i].aux3 = v;
			break;
		case 8:
			cfg.servo[i].aux4 = v;
			break;
		case 9:
			cfg.servo[i].minimum = v;
			break;
		case 10:
			cfg.servo[i].middle = v;
			break;
		case 11:
			cfg.servo[i].maximum = v;
			break;
		case 12:
			cfg.servo[i].expo = v;
			break;
		case 13:
			cfg.servo[i].speed = v;
			break;
		}
	}
}
*/
//*****************************************************************************
// Печать/изменение конфигурационных параметров
//
/*
static void configFileSave(FIL* fp, const config_value_t *var)
{
    int32_t value = 0;
    char buf[16];

    switch (var->type) {
        case MAVLINK_TYPE_UINT8_T:
            value = *(uint8_t *)var->ptr;
            break;

        case MAVLINK_TYPE_INT8_T:
            value = *(int8_t *)var->ptr;
            break;

        case MAVLINK_TYPE_UINT16_T:
            value = *(uint16_t *)var->ptr;
            break;

        case MAVLINK_TYPE_INT16_T:
            value = *(int16_t *)var->ptr;
            break;

        case MAVLINK_TYPE_UINT32_T:
            value = *(uint32_t *)var->ptr;
            break;

        case MAVLINK_TYPE_FLOAT:
        sprintf(buf, "%f", *(float *)var->ptr);
        f_puts(buf, fp);
            return; // return from case for float only
    }
    f_printf(fp, "%ld", value);
}
*/
/*
 * Сохрание параметров конфигурации
 * 	команда без параметров сохраняем во flash
 * 	команда с одним параметром (имя_файла) на SD карту в бинарном формате
 * 	команда с двумя параметром (t имя_файла) на SD карту в текстовом формате
 */

//void cmdSave(int dev, int argc, const char * const * argv)
//{
//	if (argc == 1)	// Только команда
//	{
//		if (configWriteFlash())
//		{
//			buzzerPlay("5F_F_F");
//			fc_printf(dev, "\r\nError save configuration\r\n");
//		}
//		else
//		{
//			fc_printf(dev, "\r\nConfiguration saved to internal flash\r\n");
//		}
//	}
//	else if (argc == 2)
//	{
//		uint8_t result = 0; /* OK */
//		uint8_t crc = 0;
//		const uint8_t *p;
//
//		// Recalculate checksum before writing
//		cfg.crc = 0;
//		for (p = (const uint8_t *) &cfg; p < ((const uint8_t *) &cfg + sizeof(config_t)); p++)
//			crc ^= *p;
//
//		cfg.crc = crc;
//
//		result = fatFileWrite((char *)argv[1], &cfg, sizeof(config_t));
//
//		if (result)
//		{
//			buzzerPlay("5F_F_F");
//			fc_printf(dev, "\r\nError save configuration\r\n");
//		}
//		else
//			fc_printf(dev, "\r\nConfiguration saved to SD card. Filename: %s. Size: %d\r\n", (char *)argv[1], sizeof(config_t));
//	}
//	else if (argc == 3 && argv[1][0] == 't')
//	{
//		uint16_t i;
//		const config_value_t *val;
//		FIL 	file;		/* File object for log file */
//		FRESULT rc;			/* Result code */
//		rtc_struct datetime;
//
//		rtcGetTime(&datetime);
//
//		rc = f_open(&file, argv[2], FA_WRITE | FA_CREATE_ALWAYS);
//
//		if (rc != FR_OK)
//		{
//			fc_printf(dev, "Error open file [%d]\r\n", rc);
//			return;
//		}
//
//		f_printf(&file, "# System time: %02u/%02u/%02u %02u:%02u:%02u %s\r\n",
//				datetime.day,
//				datetime.month,
//				datetime.year,
//				datetime.hour,
//				datetime.minute,
//				datetime.second,
//				(datetime.syncFlag == RTC_SYNC ? "(SYNC)" : "(NOTSYNC)"));
//
//		f_printf(&file, "# Software version   %u.%u.%u.%u " __DATE__ "/" __TIME__ NEW_LINE,
//		    		(DEVICE_SW_VERSION >> 24) & 0xFF,
//		    		(DEVICE_SW_VERSION >> 16) & 0xFF,
//		    		(DEVICE_SW_VERSION >>  8) & 0xFF,
//		    		(DEVICE_SW_VERSION >>  0) & 0xFF
//		    		);
//
//		f_printf(&file, "# Config version     %u\r\n", cfg.version);
//
//		f_printf(&file, "# Configuration:\r\n");
//        for (i = 0; i < configTableCount; i++)
//        {
//            val = &configTable[i];
//            f_printf(&file, "%s=", configTable[i].name);
//            configFileSave(&file, val);
//            f_printf(&file, NEW_LINE);
//        }
//
//        f_printf(&file, "# Settings:\r\n");
//        for (i = 0; i < settingTableCount; i++)
//        {
//            val = &settingTable[i];
//            f_printf(&file, "%s=", settingTable[i].name);
//            configFileSave(&file, val);
//            f_printf(&file, NEW_LINE);
//        }
//
//        f_close(&file);
//		fc_printf(dev, "\r\nConfiguration in text mode saved to SD card. Filename: %s\r\n", (char *)argv[2]);
//	}
//	fc_printf(dev, NEW_LINE);
//}
/*
static void paramSetValue(const config_value_t *var, float value)
{
    switch (var->type)
    {
    case MAVLINK_TYPE_UINT8_T:
        *(uint8_t *) var->ptr = value;
        break;

    case MAVLINK_TYPE_INT8_T:
        *(int8_t *) var->ptr = value;
        break;

    case MAVLINK_TYPE_UINT16_T:
        *(uint16_t *) var->ptr = value;
        break;

    case MAVLINK_TYPE_INT16_T:
        *(int16_t *) var->ptr = value;
        break;

    case MAVLINK_TYPE_UINT32_T:
        *(uint32_t *) var->ptr = value;
        break;

    case MAVLINK_TYPE_FLOAT:
		// Only write and emit changes if there is actually a difference
		// AND only write if new value is NOT "not-a-number"
		// AND is NOT infinity
		if (*(float *)var->ptr != value && !isnan(value) && !isinf(value))
		{
			*(float *) var->ptr = value;
		}
        break;
    }
}
*/
/*
 * Загружаем параметры
 * 	команда без параметров загружаем из flash
 * 	команда с одним параметром (имя_файла) с SD карты в бинарном формате
 * 	команда с двумя параметром (t имя_файла) с SD карты в текстовом формате
 */

//void cmdLoad(int dev, int argc, const char * const * argv)
//{
//	if (argc == 1)
//	{
//		if (flashFileRead(SECTOR_CONF, (uint8_t *)&cfg, sizeof(config_t)))
//		{
//			buzzerPlay("5F_F");		// Ошибка чтения конфигурации
//			fc_printf(dev, "Error read configuration\r\n");
//			return;
//		}
//
//		if (!configValid())
//		{
//			buzzerPlay("5F_F_F");	// Ошибка целостности конфигурации
//			fc_printf(dev, "Configuration integrity failed\r\n");
//			return;
//		}
//	}
//	else if (argc == 2)
//	{
//		FRESULT rc;
//
//		rc = fatFileRead((char *)argv[1], &cfg, sizeof(config_t));
//
//		if (rc != FR_OK)
//		{
//			buzzerPlay("5F_F");		// Ошибка чтения конфигурации
//			fc_printf(dev, "Error read configuration\r\n");
//			return;
//		}
//	}
//	else if (argc == 3  && argv[1][0] == 't')
//	{
//		float	val;
//		FIL 	file;		/* File object for log file */
//		FRESULT rc;			/* Result code */
//		char cfg_line[64];
//		int16_t	count = 0;	// Счетчик загруженных параметров
//
//		rc = f_open(&file, argv[2], FA_READ);
//
//		if (rc != FR_OK)
//		{
//			fc_printf(dev, "Error open file [%d]\r\n", rc);
//			return;
//		}
//
//		for (;;)
//		{
//			if (f_gets(cfg_line, sizeof(cfg_line), &file) == 0)
//				break;
//
//			if (cfg_line[0] == '#')	// Коментарий
//				continue;
//
//			// Parse text file
//			for (uint16_t i = 0; i < configTableCount; i++)
//			{
//				bool match = true;
//
//				for (uint8_t j = 0; j < MAVLINK_MSG_PARAM_SET_FIELD_PARAM_ID_LEN; j++)
//				{
//					// Compare
//					if (((char) (configTable[i].name[j])) != (char) (cfg_line[j]))
//					{
//						match = false;
//						break;
//					}
//
//					// End matching if null termination is reached
//					if (((char) configTable[i].name[j]) == '\0')
//					{
//						break;
//					}
//				}
//
//				// Check if matched
//				if (match)
//				{
//					char * param = strchr(cfg_line, '=');
//
//					if (param)
//					{
//						val = atof(param++);
//						paramSetValue(&configTable[i], val);
//						count++;
//					}
//				}
//			}
//
//			for (uint16_t i = 0; i < settingTableCount; i++)
//			{
//				bool match = true;
//
//				for (uint8_t j = 0; j < MAVLINK_MSG_PARAM_SET_FIELD_PARAM_ID_LEN; j++)
//				{
//					// Compare
//					if (((char) (settingTable[i].name[j])) != (char) (cfg_line[j]))
//					{
//						match = false;
//						break;
//					}
//
//					// End matching if null termination is reached
//					if (((char) settingTable[i].name[j]) == '\0')
//					{
//						break;
//					}
//				}
//
//				// Check if matched
//				if (match)
//				{
//					char * param = strchr(cfg_line, '=');
//
//					if (param)
//					{
//						val = atof(param++);
//						paramSetValue(&settingTable[i], val);
//						count++;
//					}
//				}
//			}
//		}
//
//        f_close(&file);
//		fc_printf(dev, "Configuration in text mode loaded from SD card. Filename: %s. Params: %u\r\n", (char *)argv[2], count);
//	}
//}

//void cmdBeep(int dev, int argc, const char * const * argv)
//{
//	if (argc == 2)
//		buzzerPlay((char *)argv[1]);
//}

//extern mavlink_aerob_gcs_environment_t home_position;
//
//void cmdSync(int dev, int argc, const char * const * argv)
//{
//	// 946728000 in sec = Sat, 01 Jan 2000 12:00:00 GMT
//	if (home_position.gcs_time_ms > 946728000000)
//		rtcSetTimeLong(home_position.gcs_time_ms);
//	else
//		rtcSetTime(12, 00, 00, 26, 11, 14);
//
//	rtc_struct datetime;
//
//	rtcGetTime(&datetime);
//
//	fc_printf(dev, "RTC time:  %02u/%02u/%02u %02u:%02u:%02u %s\r\n",
//		datetime.day,
//		datetime.month,
//		datetime.year,
//		datetime.hour,
//		datetime.minute,
//		datetime.second,
//		(datetime.syncFlag == RTC_SYNC ? "(SYNC)" : "(NOTSYNC)")
//	);
//
//	fc_printf(dev, NEW_LINE);
//}

#if 0
void cmdHash(int dev, int argc, const char * const * argv)
{
#define INPUT_TAB_SIZE    ((uint32_t) 261)

	const uint8_t Input[INPUT_TAB_SIZE] =
		{0x54,0x68,0x65,0x20,0x68,0x61,0x73,0x68,
		 0x20,0x70,0x72,0x6f,0x63,0x65,0x73,0x73,
		 0x6f,0x72,0x20,0x69,0x73,0x20,0x61,0x20,
		 0x66,0x75,0x6c,0x6c,0x79,0x20,0x63,0x6f,
		 0x6d,0x70,0x6c,0x69,0x61,0x6e,0x74,0x20,
		 0x69,0x6d,0x70,0x6c,0x65,0x6d,0x65,0x6e,
		 0x74,0x61,0x74,0x69,0x6f,0x6e,0x20,0x6f,
		 0x66,0x20,0x74,0x68,0x65,0x20,0x73,0x65,
		 0x63,0x75,0x72,0x65,0x20,0x68,0x61,0x73,
		 0x68,0x20,0x61,0x6c,0x67,0x6f,0x72,0x69,
		 0x74,0x68,0x6d,0x20,0x28,0x53,0x48,0x41,
		 0x2d,0x31,0x29,0x2c,0x20,0x74,0x68,0x65,
		 0x20,0x4d,0x44,0x35,0x20,0x28,0x6d,0x65,
		 0x73,0x73,0x61,0x67,0x65,0x2d,0x64,0x69,
		 0x67,0x65,0x73,0x74,0x20,0x61,0x6c,0x67,
		 0x6f,0x72,0x69,0x74,0x68,0x6d,0x20,0x35,
		 0x29,0x20,0x68,0x61,0x73,0x68,0x20,0x61,
		 0x6c,0x67,0x6f,0x72,0x69,0x74,0x68,0x6d,
		 0x20,0x61,0x6e,0x64,0x20,0x74,0x68,0x65,
		 0x20,0x48,0x4d,0x41,0x43,0x20,0x28,0x6b,
		 0x65,0x79,0x65,0x64,0x2d,0x68,0x61,0x73,
		 0x68,0x20,0x6d,0x65,0x73,0x73,0x61,0x67,
		 0x65,0x20,0x61,0x75,0x74,0x68,0x65,0x6e,
		 0x74,0x69,0x63,0x61,0x74,0x69,0x6f,0x6e,
		 0x20,0x63,0x6f,0x64,0x65,0x29,0x20,0x61,
		 0x6c,0x67,0x6f,0x72,0x69,0x74,0x68,0x6d,
		 0x20,0x73,0x75,0x69,0x74,0x61,0x62,0x6c,
		 0x65,0x20,0x66,0x6f,0x72,0x20,0x61,0x20,
		 0x76,0x61,0x72,0x69,0x65,0x74,0x79,0x20,
		 0x6f,0x66,0x20,0x61,0x70,0x70,0x6c,0x69,
		 0x63,0x61,0x74,0x69,0x6f,0x6e,0x73,0x2e,
		 0x2a,0x2a,0x2a,0x20,0x53,0x54,0x4d,0x33,
		 0x32,0x20,0x2a,0x2a,0x2a};

	uint8_t Md5output[16];
	uint8_t Sha1output[20];
	uint8_t	i;
	ErrorStatus status;

	/* Enable HASH clock */
	RCC_AHB2PeriphClockCmd(RCC_AHB2Periph_HASH, ENABLE);

	/* SHA-1 Digest Computation */
	status = HASH_SHA1((uint8_t *)Input, INPUT_TAB_SIZE, Sha1output);

	printf("SHA1: [%d] ", status);

	for (i = 0; i < sizeof(Sha1output); i ++)
	{
	  printf("%02X", Sha1output[i]);
	}

	/*  MD5 Digest Computation */
	status = HASH_MD5((uint8_t *)Input, INPUT_TAB_SIZE, Md5output);

	printf("\r\nMD5: [%d] ", status);

	for (i = 0; i < sizeof(Md5output); i ++)
	{
	  printf("%02X", Md5output[i]);
	}

	printf(NEW_LINE);
}
#endif

// Выводит значения сенсоров
/*
void cmdSensor(int dev, int argc, const char * const * argv)
{
	uint8_t id = 0;
	uint8_t num = 0;
	float value;
	uint32_t counter;
	uint16_t sensor_id;
	uint8_t rc = 0;

	fc_printf(dev, " ID Sensor name          Value        Cnt\r\n");

	while (1)
	{
		rc = sensorGet(id, num, &value, &counter, &sensor_id);

		if (rc != 0)
			break;

		num++;

		fc_printf(dev, "%3u %-15s %10.2f %10lu\r\n", sensor_id, sensorGetName(sensor_id), value, counter);
	}

	fc_printf(dev, NEW_LINE);
}
*/
// Выводит значения сенсоров BPUSS
/*
void cmdBpuss(int dev, int argc, const char * const * argv)
{
	bpuss_sensor_t * bpuss = getBpuss();

	fc_printf(dev, "BPUSS test\r\n");

	if (argc == 1)
	{
		fc_printf(dev, "SW ver:      %%08lX V\r\n", bpuss->sw_version);
		fc_printf(dev, "VBUS:        %2.1f V\r\n", (float) bpuss->vbus / 1000.0);
		fc_printf(dev, "VGEN:        %2.1f V\r\n", (float) bpuss->vgen / 1000.0);
		fc_printf(dev, "BAT1:        %2.1f V\r\n", (float) bpuss->vbat1 / 1000.0);
		fc_printf(dev, "BAT2:        %2.1f V\r\n", (float) bpuss->vbat2 / 1000.0);
		fc_printf(dev, "PL current:  %2.3f A\r\n", (float) bpuss->payload_cur / 1000.0);
		fc_printf(dev, "Sys current: %2.3f A\r\n", (float) bpuss->system_cur / 1000.0);
		fc_printf(dev, "Gen. temp:   %2.1f °C\r\n", (float) bpuss->temp_gen / 1000.0);
	}
	else
	{
		fc_printf(dev, "Use command without arguments\r\n");
	}

	fc_printf(dev, NEW_LINE);
}
*/

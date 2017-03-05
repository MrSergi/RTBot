﻿#ifndef MICRORL_FUNC_H_
#define MICRORL_FUNC_H_

#include <stdint.h>

#define microrlNUM_OF_TERMINAL_FUNC	10

typedef struct {
	const char * name;
	const char * help;
	int (*func)(int, const char* const*);
} terminalFunc_t;

void microrl_terminalInit();
void microrl_terminalProcess();
void consoleInit(void);
void ConsoleInput(uint8_t* Buf, uint32_t Len);
void microrl_registerExecuteFunc(int (*func)(int, const char* const*), const char* name, const char* help);

int fc_printf(const char * fmt, ...);

void cmdHelp(int argc, const char * const * argv);

void microrl_printString(const char *str);
void microrl_printStringWithEndl(const char *str);
void microrl_printEndl();

#endif

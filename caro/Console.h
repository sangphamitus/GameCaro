#pragma once
#ifndef __CONSOLE_H__
#define __CONSOLE_H__
#include <windows.h>
#define CO_THEME 7
#define WIDTH 1400
#define HEIGHT 750
void createconsole();
void console();
void gotoxy(int x, int y);
void SetColor(int color);

#endif

#include "Console.h"

void createconsole()
{
	HWND console = GetConsoleWindow();
	RECT r;
	HANDLE hconsole;

	hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hconsole, CO_THEME);
	GetWindowRect(console, &r);
	MoveWindow(console, 0, 0, WIDTH, HEIGHT, TRUE);
}
void console()
{
	HWND console = GetConsoleWindow();
	LONG style = GetWindowLong(console, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(console, GWL_STYLE, style);
}
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void SetColor(int color)
{
	HANDLE hconsole;
	hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hconsole, color);
}
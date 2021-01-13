#include "main.h"
#include "Graphic.h"
#include "Console.h"
#include "Game.h"

void Ve(int t)
{
	for (int i = 1; i <= t; i++) cout << char(219);
}
void kVe(int t)
{
	for (int i = 1; i <= t; i++) cout << " ";
}
int VeSo(int n, int x, int y)
{
	if (n == 0)
	{
		gotoxy(x, y); Ve(7);
		gotoxy(x, y + 1); Ve(2), kVe(3), Ve(2);
		gotoxy(x, y + 2); Ve(2), kVe(3), Ve(2);
		gotoxy(x, y + 3); Ve(2), kVe(3), Ve(2);
		gotoxy(x, y + 4); Ve(7);
		return 0;
	}
	else if (n == 1)
	{
		gotoxy(x, y); Ve(5), kVe(2);
		gotoxy(x, y + 1); kVe(3), Ve(2), kVe(2);
		gotoxy(x, y + 2); kVe(3), Ve(2), kVe(2);
		gotoxy(x, y + 3); kVe(3), Ve(2), kVe(2);
		gotoxy(x, y + 4); Ve(7);
		return 1;
	}
	else if (n == 2)
	{
		gotoxy(x, y); Ve(7);
		gotoxy(x, y + 1); kVe(5), Ve(2);
		gotoxy(x, y + 2); Ve(7);
		gotoxy(x, y + 3); Ve(2), kVe(5);
		gotoxy(x, y + 4); Ve(7);
		return 2;
	}
	else if (n == 3)
	{
		gotoxy(x, y); Ve(7);
		gotoxy(x, y + 1); kVe(5), Ve(2);
		gotoxy(x, y + 2); kVe(2), Ve(5);
		gotoxy(x, y + 3); kVe(5), Ve(2);
		gotoxy(x, y + 4); Ve(7);
		return(3);
	}
	else if (n == 4)
	{
		gotoxy(x, y); kVe(2), Ve(2), kVe(1), Ve(2);
		gotoxy(x, y + 1); kVe(1), Ve(2), kVe(2), Ve(2);
		gotoxy(x, y + 2); Ve(7);
		gotoxy(x, y + 3); kVe(5), Ve(2);
		gotoxy(x, y + 4); kVe(5), Ve(2);
		return 4;
	}
	else if (n == 5)
	{
		gotoxy(x, y); Ve(7);
		gotoxy(x, y + 1); Ve(2), kVe(5);
		gotoxy(x, y + 2); Ve(7);
		gotoxy(x, y + 3); kVe(5), Ve(2);
		gotoxy(x, y + 4); Ve(7);
		return 5;
	}
	else if (n == 6)
	{
		gotoxy(x, y); Ve(7);
		gotoxy(x, y + 1); Ve(2), kVe(5);
		gotoxy(x, y + 2); Ve(7);
		gotoxy(x, y + 3); Ve(2), kVe(3), Ve(2);
		gotoxy(x, y + 4); Ve(7);
		return 6;
	}
	else if (n == 7)
	{
		gotoxy(x, y); Ve(7);
		gotoxy(x, y + 1); kVe(4), Ve(3);
		gotoxy(x, y + 2); kVe(3), Ve(3), kVe(1);
		gotoxy(x, y + 3); kVe(2), Ve(3), kVe(2);
		gotoxy(x, y + 4); kVe(1), Ve(3), kVe(3);
		return 7;
	}
	else if (n == 8)
	{
		gotoxy(x, y); Ve(7);
		gotoxy(x, y + 1); Ve(2), kVe(3), Ve(2);
		gotoxy(x, y + 2); Ve(7);
		gotoxy(x, y + 3); Ve(2), kVe(3), Ve(2);
		gotoxy(x, y + 4); Ve(7);
		return 8;
	}
	else if (n == 9)
	{
		gotoxy(x, y); Ve(7);
		gotoxy(x, y + 1); Ve(2), kVe(3), Ve(2);
		gotoxy(x, y + 2); Ve(7);
		gotoxy(x, y + 3); kVe(5), Ve(2);
		gotoxy(x, y + 4); Ve(7);
		return 9;
	}
}
void MainCaro()
{
	system("color 74");
	int mid = 54;
	gotoxy(mid, 5);
	kVe(5), Ve(8);
	cout << endl;
	gotoxy(mid, 6);
	kVe(4), Ve(3), kVe(5), Ve(2);
	cout << endl;
	gotoxy(mid, 7);
	kVe(3), Ve(3), kVe(7), Ve(2);
	cout << endl;
	gotoxy(mid, 8);
	kVe(2), Ve(3), kVe(7), Ve(2), kVe(3);
	cout << endl;
	gotoxy(mid, 9);
	kVe(1), Ve(3), kVe(14), Ve(5), kVe(1), Ve(2), kVe(2), Ve(6), kVe(5), Ve(5);
	cout << endl;
	gotoxy(mid, 10);
	kVe(1), Ve(3), kVe(12), Ve(3), kVe(3), Ve(3), kVe(4), Ve(2), kVe(2), Ve(2), kVe(3), Ve(2), kVe(3), Ve(2);
	cout << endl;
	gotoxy(mid, 11);
	kVe(2), Ve(3), kVe(10), Ve(2), kVe(5), Ve(2), kVe(4), Ve(2), kVe(3), Ve(2), kVe(2), Ve(2), kVe(3), Ve(2);
	cout << endl;
	gotoxy(mid, 12);
	kVe(3), Ve(3), kVe(7), Ve(4), kVe(4), Ve(2), kVe(2), Ve(1), kVe(1), Ve(2), kVe(2), Ve(3), kVe(2), Ve(2), kVe(3), Ve(2);
	cout << endl;
	gotoxy(mid, 13);
	kVe(4), Ve(10), kVe(2), Ve(5), kVe(1), Ve(3), kVe(1), Ve(2), kVe(5), Ve(3), kVe(1), Ve(5);
	cout << endl;
	gotoxy(mid, 14);
	for (int i = 1; i <= 6; i++) cout << " ";
	for (int i = 1; i <= 6; i++) cout << char(223);
}
void MainMenu()
{
	Board(30, 9, 60, 23, DELAY);
	Sleep(100);
	SetColor(GREEN_LYE);
	gotoxy(gox + 1, goy); cout << "NEW GAME";
	gotoxy(gox + 1, goy + 1); cout << "LOAD GAME";
	gotoxy(gox + 1, goy + 2); cout << "HELP";
	gotoxy(gox + 1, goy + 3); cout << "ABOUT";
	gotoxy(gox + 1, goy + 4); cout << "EXIT";
}
void BoardGraphics()
{
	int right = 92;
	SetColor(GREY_W);
	gotoxy(right, 1);  cout << "********************************   ********************************";
	gotoxy(right, 2);  cout << "*                              *   *                              *";
	gotoxy(right, 3);  cout << "*   ***                  ***   *   *          **********          *";
	gotoxy(right, 4);  cout << "*     ***              ***     *   *       ****        ****       *";
	gotoxy(right, 5);  cout << "*       ***          ***       *   *     ***              ***     *";
	gotoxy(right, 6);  cout << "*         ***      ***         *   *    **                  **    *";
	gotoxy(right, 7);  cout << "*           ***  ***           *   *   **                    **   *";
	gotoxy(right, 8);  cout << "*             ****             *   *   **                    **   *";
	gotoxy(right, 9);  cout << "*           ***  ***           *   *   **                    **   *";
	gotoxy(right, 10); cout << "*         ***      ***         *   *    **                  **    *";
	gotoxy(right, 11); cout << "*       ***          ***       *   *     ***              ***     *";
	gotoxy(right, 12); cout << "*     ***              ***     *   *       ****        ****       *";
	gotoxy(right, 13); cout << "*   ***                  ***   *   *          **********          *";
	gotoxy(right, 14); cout << "*                              *   *                              *";
	gotoxy(right, 15); cout << "********************************   ********************************";
	//
}
void XTurnGraph()
{
	int x = 92;
	SetColor(RED_W);
	gotoxy(x, 1); Ve(32);
	gotoxy(x, 2); Ve(2), kVe(28), Ve(2);
	gotoxy(x, 3); Ve(2), kVe(2), Ve(3), kVe(18), Ve(3), kVe(2), Ve(2);
	gotoxy(x, 4); Ve(2), kVe(4), Ve(3), kVe(14), Ve(3), kVe(4), Ve(2);
	gotoxy(x, 5); Ve(2), kVe(6), Ve(3), kVe(10), Ve(3), kVe(6), Ve(2);
	gotoxy(x, 6); Ve(2), kVe(8), Ve(3), kVe(6), Ve(3), kVe(8), Ve(2);
	gotoxy(x, 7); Ve(2), kVe(10), Ve(3), kVe(2), Ve(3), kVe(10), Ve(2);
	gotoxy(x, 8); Ve(2), kVe(12), Ve(4), kVe(12), Ve(2);
	gotoxy(x, 14); Ve(2), kVe(28), Ve(2);
	gotoxy(x, 13); Ve(2), kVe(2), Ve(3), kVe(18), Ve(3), kVe(2), Ve(2);
	gotoxy(x, 12); Ve(2), kVe(4), Ve(3), kVe(14), Ve(3), kVe(4), Ve(2);
	gotoxy(x, 11); Ve(2), kVe(6), Ve(3), kVe(10), Ve(3), kVe(6), Ve(2);
	gotoxy(x, 10); Ve(2), kVe(8), Ve(3), kVe(6), Ve(3), kVe(8), Ve(2);
	gotoxy(x, 9); Ve(2), kVe(10), Ve(3), kVe(2), Ve(3), kVe(10), Ve(2);
	gotoxy(x, 15); Ve(32);
}
void OTurnGraph()
{
	int o = 127;
	SetColor(CYAN_W);
	gotoxy(o, 1); Ve(32);
	gotoxy(o, 2); Ve(2), kVe(28), Ve(2);
	gotoxy(o, 3); Ve(2), kVe(9), Ve(10), kVe(9), Ve(2);
	gotoxy(o, 4); Ve(2), kVe(6), Ve(4), kVe(8), Ve(4), kVe(6), Ve(2);
	gotoxy(o, 5); Ve(2), kVe(4), Ve(3), kVe(14), Ve(3), kVe(4), Ve(2);
	gotoxy(o, 6); Ve(2), kVe(3), Ve(2), kVe(18), Ve(2), kVe(3), Ve(2);
	gotoxy(o, 7); Ve(2), kVe(2), Ve(2), kVe(20), Ve(2), kVe(2), Ve(2);
	gotoxy(o, 8); Ve(2), kVe(2), Ve(2), kVe(20), Ve(2), kVe(2), Ve(2);
	gotoxy(o, 9); Ve(2), kVe(2), Ve(2), kVe(20), Ve(2), kVe(2), Ve(2);
	gotoxy(o, 15); Ve(32);
	gotoxy(o, 14); Ve(2), kVe(28), Ve(2);
	gotoxy(o, 13); Ve(2), kVe(9), Ve(10), kVe(9), Ve(2);
	gotoxy(o, 12); Ve(2), kVe(6), Ve(4), kVe(8), Ve(4), kVe(6), Ve(2);
	gotoxy(o, 11); Ve(2), kVe(4), Ve(3), kVe(14), Ve(3), kVe(4), Ve(2);
	gotoxy(o, 10); Ve(2), kVe(3), Ve(2), kVe(18), Ve(2), kVe(3), Ve(2);
}
void Board(int dai, int rong, int x, int y, int delay)
{
	SetColor(GREEN_W);
	gotoxy(x, y - 1);
	for (int i = 0; i < dai; i++) cout << char(220);
	for (int i = 0; i < rong; i++)
	{
		Sleep(delay);
		SetColor(8 * 16 + 8);
		gotoxy(x + 1, y + i);  Ve(dai);
		gotoxy(x, y + i); 
		SetColor(14 * 16 + 14);
		Ve(dai - 1);
		SetColor(GREEN_LYE);
		gotoxy(x, y + i);
		cout << char(221);
		gotoxy(x + dai - 1, y + i);
		cout << char(222);
	}
	SetColor(8 * 16 + 8);
	gotoxy(x + 1, y + rong);  Ve(dai);
	SetColor(8 * 16 + 2);
	gotoxy(x, y + rong);
	for (int i = 0; i < dai; i++) cout << char(223);
	SetColor(GREEN_W);
	gotoxy(x, y + rong); cout << char(223);
}
void XWin(int x, int y)
{
	SetColor(RED_LYE);
	gotoxy(x, y + 2); Ve(6), kVe(10), Ve(6), kVe(7), Ve(4), kVe(18), Ve(4), kVe(2), Ve(4), kVe(4), Ve(10);
	gotoxy(x, y + 3); Ve(6), kVe(10), Ve(6), kVe(7), Ve(4), kVe(18), Ve(4), kVe(2), Ve(4), kVe(4), Ve(10);
	gotoxy(x, y + 4); kVe(4), Ve(6), kVe(2), Ve(6), kVe(12), Ve(4), kVe(6), Ve(4), kVe(6), Ve(4), kVe(3), Ve(4), kVe(2), Ve(4), kVe(6), Ve(4);
	gotoxy(x, y + 5); kVe(4), Ve(6), kVe(2), Ve(6), kVe(12), Ve(4), kVe(6), Ve(4), kVe(6), Ve(4), kVe(3), Ve(4), kVe(2), Ve(4), kVe(6), Ve(4);
	gotoxy(x, y + 6); kVe(8), Ve(6), kVe(17), Ve(4), kVe(4), Ve(6), kVe(4), Ve(4), kVe(4), Ve(4), kVe(2), Ve(4), kVe(6), Ve(4);
	gotoxy(x, y + 7); kVe(8), Ve(6), kVe(17), Ve(4), kVe(4), Ve(6), kVe(4), Ve(4), kVe(4), Ve(4), kVe(2), Ve(4), kVe(6), Ve(4);
	gotoxy(x, y + 11); Ve(6), kVe(10), Ve(6), kVe(12), Ve(6), kVe(4), Ve(6), kVe(7), Ve(4), kVe(2), Ve(4), kVe(6), Ve(4);
	gotoxy(x, y + 10); Ve(6), kVe(10), Ve(6), kVe(11), Ve(8), kVe(2), Ve(8), kVe(6), Ve(4), kVe(2), Ve(4), kVe(6), Ve(4);
	gotoxy(x, y + 9); kVe(4), Ve(6), kVe(2), Ve(6), kVe(14), Ve(20), kVe(5), Ve(4), kVe(2), Ve(4), kVe(6), Ve(4);
	gotoxy(x, y + 8); kVe(4), Ve(6), kVe(2), Ve(6), kVe(14), Ve(4), kVe(2), Ve(8), kVe(2), Ve(4), kVe(5), Ve(4), kVe(2), Ve(4), kVe(6), Ve(4);
}
void OWin(int x, int y)
{
	SetColor(CYAN_LYE);
	gotoxy(x, y + 2); kVe(3), Ve(16), kVe(10), Ve(4), kVe(18), Ve(4), kVe(2), Ve(4), kVe(4), Ve(10);
	gotoxy(x, y + 3); kVe(3), Ve(16), kVe(10), Ve(4), kVe(18), Ve(4), kVe(2), Ve(4), kVe(4), Ve(10);
	gotoxy(x, y + 4); Ve(7), kVe(8), Ve(7), kVe(8), Ve(4), kVe(6), Ve(4), kVe(6), Ve(4), kVe(3), Ve(4), kVe(2), Ve(4), kVe(6), Ve(4);
	gotoxy(x, y + 5); Ve(5), kVe(12), Ve(5), kVe(8), Ve(4), kVe(6), Ve(4), kVe(6), Ve(4), kVe(3), Ve(4), kVe(2), Ve(4), kVe(6), Ve(4);
	gotoxy(x, y + 6); Ve(5), kVe(12), Ve(5), kVe(9), Ve(4), kVe(4), Ve(6), kVe(4), Ve(4), kVe(4), Ve(4), kVe(2), Ve(4), kVe(6), Ve(4);
	gotoxy(x, y + 7); Ve(5), kVe(12), Ve(5), kVe(9), Ve(4), kVe(4), Ve(6), kVe(4), Ve(4), kVe(4), Ve(4), kVe(2), Ve(4), kVe(6), Ve(4);
	gotoxy(x, y + 11); kVe(3), Ve(16), kVe(15), Ve(6), kVe(4), Ve(6), kVe(7), Ve(4), kVe(2), Ve(4), kVe(6), Ve(4);
	gotoxy(x, y + 10); kVe(3), Ve(16), kVe(14), Ve(8), kVe(2), Ve(8), kVe(6), Ve(4), kVe(2), Ve(4), kVe(6), Ve(4);
	gotoxy(x, y + 9); Ve(7), kVe(8), Ve(7), kVe(10), Ve(20), kVe(5), Ve(4), kVe(2), Ve(4), kVe(6), Ve(4);
	gotoxy(x, y + 8); Ve(5), kVe(12), Ve(5), kVe(10), Ve(4), kVe(2), Ve(8), kVe(2), Ve(4), kVe(5), Ve(4), kVe(2), Ve(4), kVe(6), Ve(4);
}
void Draw(int x, int y)
{
	SetColor(GREY_LYE);
	gotoxy(x, y + 2); Ve(10), kVe(9), Ve(9), kVe(8), Ve(10), kVe(4), Ve(4), kVe(18), Ve(4);
	gotoxy(x, y + 3); Ve(13), kVe(6), Ve(10), kVe(7), Ve(10), kVe(4), Ve(4), kVe(18), Ve(4);
	gotoxy(x, y + 4); Ve(4), kVe(4), Ve(8), kVe(3), Ve(4), kVe(3), Ve(4), kVe(5), Ve(4), kVe(4), Ve(4), kVe(4), Ve(4), kVe(6), Ve(4), kVe(6), Ve(4);
	gotoxy(x, y + 5); Ve(4), kVe(8), Ve(4), kVe(3), Ve(4), kVe(5), Ve(3), kVe(4), Ve(4), kVe(4), Ve(4), kVe(4), Ve(4), kVe(6), Ve(4), kVe(6), Ve(4);
	gotoxy(x, y + 6); Ve(4), kVe(10), Ve(3), kVe(2), Ve(4), kVe(4), Ve(4), kVe(4), Ve(12), kVe(5), Ve(4), kVe(4), Ve(6), kVe(4), Ve(4);
	gotoxy(x, y + 7); Ve(4), kVe(10), Ve(3), kVe(2), Ve(11), kVe(5), Ve(12), kVe(5), Ve(4), kVe(4), Ve(6), kVe(4), Ve(4);
	gotoxy(x, y + 8); Ve(4), kVe(10), Ve(3), kVe(2), Ve(10), kVe(5), Ve(4), kVe(6), Ve(4), kVe(5), Ve(4), kVe(2), Ve(8), kVe(2), Ve(4);
	gotoxy(x, y + 9); Ve(4), kVe(8), Ve(4), kVe(3), Ve(4), kVe(3), Ve(4), kVe(4), Ve(4), kVe(6), Ve(4), kVe(5), Ve(20);
	gotoxy(x, y + 10); Ve(16), kVe(3), Ve(4), kVe(4), Ve(4), kVe(3), Ve(4), kVe(6), Ve(4), kVe(6), Ve(8), kVe(2), Ve(7);
	gotoxy(x, y + 11); Ve(12), kVe(7), Ve(4), kVe(5), Ve(4), kVe(2), Ve(4), kVe(6), Ve(4), kVe(7), Ve(6), kVe(4), Ve(6);
}
void Enter(int x, int y)
{
	int i = 6;
	Board(11, 1, x, y, 0);
	gotoxy(x + 3, y);
	SetColor(LGREEN_LYE);
	cout << "ENTER";
}
void Erase(int d, int r, int x, int y)
{
	SetColor(7 * 16 + 7);
	for (int i = -1; i <= r; i++)
		for (int j = 0; j <= d; j++)
		{
			gotoxy(x + j, y + i);
			cout << char(219);
		}
}

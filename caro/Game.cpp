#include "Game.h"
#include "File.h"
#include "Graphic.h"
#include "Console.h"
//#include "Control.h"
int _COMMAND;
int _TURN;
int _COUNT;
int _WIN;
int _PLAYERX = 0;
int _PLAYERO = 0;
char _NAMEX[LONG];
char _NAMEO[LONG];
int _SoX = 0;
int _SoO = 0;
string P[50];
int nofs;
struct WINDETECT
{
	int x;
	int y;
	int c;
};
WINDETECT WINDT[6];
int A[BOARD][BOARD];
int _X, _Y;
struct _POINT
{
	int x; //hoanh do
	int y; // tung do
	int c; // (-1 =x ) (1=o )
};
int chuyenx(int a)
{
	return 2 + 4 * (a);
}
int chuyeny(int a)
{
	return 1 + 2 * (a);
}
void danhdau(int a, int x, int y)
{
	if (a == -1) {
		A[x][y] = -1;
		gotoxy(chuyenx(x), chuyeny(y));
		SetColor(RED_W);
		cout << "X";
	}
	else if (a == 1)
	{
		A[x][y] = 1;
		gotoxy(chuyenx(x), chuyeny(y));
		SetColor(CYAN_W);
		cout << "O";
	}

	SetColor(CO_THEME);
}
void Moveleft()
{
	if (_X > 0) _X -= 1;
	gotoxy(chuyenx(_X), chuyeny(_Y));
}
void Moveright()
{
	if (_X < BOARD - 1) _X += 1;
	gotoxy(chuyenx(_X), chuyeny(_Y));
}
void Moveup()
{
	if (_Y > 0)_Y -= 1;
	gotoxy(chuyenx(_X), chuyeny(_Y));
}
void Movedown()
{
	if (_Y < BOARD - 1)	_Y += 1;
	gotoxy(chuyenx(_X), chuyeny(_Y));
}
void kebang()
{
	system("cls");
	system("color 72");
	for (int i = 0; i <= (4 * BOARD); i++)
	{
		for (int j = 0; j <= (2 * BOARD); j++)
		{
			if (i == 0 && j == 0)
			{
				gotoxy(i, j);
				cout << char(218);
			}
			else if (i == 0 && j == 2 * BOARD)
			{
				gotoxy(i, j);
				cout << char(192);
			}
			else if (i == 4 * BOARD && j == 0)
			{
				gotoxy(i, j);
				cout << char(191);
			}
			else if (i == 4 * BOARD && j == 2 * BOARD)
			{
				gotoxy(i, j);
				cout << char(217);
			}
			else if (i == 0 && j % 2 == 0)
			{
				gotoxy(i, j);
				cout << char(195);
			}
			else if (i == 4 * BOARD && j % 2 == 0)
			{
				gotoxy(i, j);
				cout << char(180);
			}
			else if (i % 4 != 0 && j % 2 != 0)
			{
				gotoxy(i, j);
				cout << " ";
			}
			else if (i % 4 == 0 && j % 2 != 0)
			{
				gotoxy(i, j);
				cout << char(179);
			}
			else if (i % 4 == 0 && j == 0)
			{
				gotoxy(i, j);
				cout << char(194);
			}
			else if (i % 4 == 0 && j == 2 * BOARD)
			{
				gotoxy(i, j);
				cout << char(193);
			}
			else if (i % 4 == 0 && j % 2 == 0)
			{
				gotoxy(i, j);
				cout << char(197);
			}
			else
			{
				gotoxy(i, j);
				cout << char(196);
			}
		};
	}
	gotoxy(2, 2 * BOARD + 2); cout << "Nhan ESC de thoat...";
	SetColor(CO_THEME);
}
void ResetData()
{
	_COUNT = 0;
	_X = 0;
	_Y = 0;
	_SoX = 0;
	_SoO = 0;
	for (int i = 0; i < BOARD; i++)
		for (int j = 0; j < BOARD; j++)
		{
			A[i][j] = 0;
		}
	_TURN = -1;
	_COMMAND = -1;
	_WIN = 0;
	gotoxy(chuyenx(_X), chuyeny(_Y));
}
void BangDiem()
{
	SetColor(CO_THEME);
	ResetData();
	kebang();
	BoardGraphics();
	XTurnGraph();
	SetColor(GREY_W);
	gotoxy(128, 16); cout << _NAMEO;
	SetColor(RED_W);
	gotoxy(93, 16); cout << _NAMEX;
	gotoxy(86, 19); cout << "So X: " << _SoX;
	SetColor(CYAN_W);
	gotoxy(86, 21); cout << "So O: " << _SoO;
	SetColor(YELLOW_W);
	VeSo(_PLAYERX, 108, 18);
	VeSo(_PLAYERO, 136, 18);
	for (int i = 0; i < 5; i++)
	{
		gotoxy(97, 18 + i);
		cout << char(186);
	}
	gotoxy(124, 19); cout << char(219) << char(219);
	gotoxy(124, 21); cout << char(219) << char(219);
	gotoxy(chuyenx(_X), chuyeny(_Y));
}
void lenhr()
{
	Enter(118, 42);
	do {
		_COMMAND = toupper(_getch());
	} while (_COMMAND != 13);
	if (_COMMAND == 13)
	{
		BangDiem();
	}
}
void checkxeotp()
{
	int x = 0;
	int o = 0;
	int j;
	for (int c = BOARD-1; c >= 0; c--)
	{
		j = 0;
		for (int i = c; i < BOARD; i++)
		{
			if (A[j][i] == 0) { x = 0; o = 0; }
			if (A[j][i] == -1) {

				x++;  o = 0;
				if (_WIN == 0) { WINDT[x].y = i; WINDT[x].c = -1; WINDT[x].x = j; }
				if (x == CK) { _WIN = -1; break; }
			}
			if (A[j][i] == 1) {
				o++; x = 0;
				if (_WIN == 0) { WINDT[o].x = j; WINDT[o].y = i; WINDT[o].c = 1; }
				if (o == CK) { _WIN = 1; break; }
			}
			j++;
		}
		x = 0;
		o = 0;
	}
	for (int c = 0; c < BOARD; c++)
	{
		j = 0;
		for (int i = c; i < BOARD; i++)
		{
			if (A[i][j] == 0) { x = 0; o = 0; }
			if (A[i][j] == -1) {
				x++; o = 0;
				if (_WIN == 0) { WINDT[x].x = i; WINDT[x].y = j; WINDT[x].c = -1; }
				if (x == 5) { _WIN = -1; break; }
			}
			if (A[i][j] == 1) {
				o++; x = 0;
				if (_WIN == 0) {
					WINDT[o].x = i; WINDT[o].y = j; WINDT[o].c = 1;
				}
				if (o == 5) { _WIN = 1; break; }
			}
			j++;
		}
		x = 0;
		o = 0;
	}

}
void checkxeopt()
{
	int x = 0;
	int o = 0;
	int j;
	for (int c = BOARD-1; c >= 0; c--)
	{
		for (int i = c; i < BOARD; i++)
		{
			j = c - (i - BOARD + 1);
			if (A[j][i] == 0) { x = 0; o = 0; }
			if (A[j][i] == -1) {
				x++; o = 0;
				if (_WIN == 0) {
					WINDT[x].x = j; WINDT[x].y = i; WINDT[x].c = -1;
				}
				if (x == CK) { _WIN = -1; break; }

			}
			if (A[j][i] == 1) {
				o++; x = 0;
				if (_WIN == 0) {
					WINDT[o].x = j; WINDT[o].y = i; WINDT[o].c = 1;
				}
				if (o == CK) { _WIN = 1; break; }
			}
		}
		x = 0;
		o = 0;
	}
	for (int c = BOARD-1; c >= 0; c--)
	{
		for (int i = c; i >= 0; i--)
		{
			j = c - i;
			if (A[i][j] == 0) { x = 0; o = 0; }
			if (A[i][j] == -1) {
				x++; o = 0;
				if (_WIN == 0) {
					WINDT[x].x = i; WINDT[x].y = j; WINDT[x].c = -1;
				}
				if (x == 5) { _WIN = -1; break; }
			}
			if (A[i][j] == 1) {
				o++; x = 0;
				if (_WIN == 0) {
					WINDT[o].x = i; WINDT[o].y = j; WINDT[o].c = 1;
				}
				if (o == 5) { _WIN = 1; break; }
			}
		}
		x = 0;
		o = 0;
	}
}
void doc()
{
	int x;
	int o;

	for (int i = 0; i < BOARD; i++)
	{
		x = 0;
		o = 0;
		for (int j = 0; j < BOARD; j++)
		{
			if (A[j][i] == 0) { x = 0; o = 0; }
			if (A[j][i] == -1) {
				x++; o = 0;
				if (_WIN == 0) {
					WINDT[x].x = j; WINDT[x].y = i; WINDT[x].c = -1;
				}
				if (x == CK) { _WIN = -1; break; }
			}
			if (A[j][i] == 1) {
				o++; x = 0;
				if (_WIN == 0) {
					WINDT[o].x = j; WINDT[o].y = i; WINDT[o].c = 1;
				}
				if (o == CK) { _WIN = 1; break; }
			}
		}
	}
}
void ngang()
{
	int x;
	int o;

	for (int i = 0; i < BOARD; i++)
	{
		x = 0;
		o = 0;
		for (int j = 0; j < BOARD; j++)
		{
			if (A[i][j] == 0) { x = 0; o = 0; }
			if (A[i][j] == -1) {
				x++; o = 0;
				if (_WIN == 0) {
					WINDT[x].x = i; WINDT[x].y = j; WINDT[x].c = -1;
				}
				if (x == CK) { _WIN = -1; break; }
			}
			if (A[i][j] == 1) {
				o++; x = 0;
				if (_WIN == 0) {
					WINDT[o].x = i; WINDT[o].y = j; WINDT[o].c = 1;
				}
				if (o == CK) { _WIN = 1; break; }
			}

		}
	}
}
int thang()
{

	if (_WIN == 0) doc();
	if (_WIN == 0) ngang();
	if (_WIN == 0) checkxeotp();
	if (_WIN == 0) checkxeopt();
	return _WIN;
}
void loadgame(string tenfile)
{
	int i = -1;
	int j = -1;
	int giatri = 0;
	fstream f;
	f.open(tenfile, ios::in);
	f >> _NAMEX >> _NAMEO;
	f >> _TURN >> _PLAYERX >> _PLAYERO >> _SoX >> _SoO;
	SetColor(YELLOW_W);
	VeSo(_PLAYERX, 108, 18);
	VeSo(_PLAYERO, 136, 18);
	SetColor(RED_W);
	gotoxy(86, 19);
	cout << "So X: " << _SoX;
	SetColor(CYAN_W);
	gotoxy(86, 21);
	cout << "So O: " << _SoO;
	if (_SoX > _SoO)
	{
		BoardGraphics();
		OTurnGraph();
		SetColor(CYAN_W);
		gotoxy(128, 16); cout << _NAMEO;
		SetColor(GREY_W);
		gotoxy(93, 16); cout << _NAMEX;
	}
	else
	{
		BoardGraphics();
		XTurnGraph();
		SetColor(RED_W);
		gotoxy(93, 16); cout << _NAMEX;
		SetColor(GREY_W);
		gotoxy(128, 16); cout << _NAMEO;
	}
	gotoxy(2, 1);
			while (!f.eof())
			{
				f >> i >> j >> giatri;
				A[i][j] = giatri;
				_COUNT++; gotoxy(chuyenx(i), chuyeny(j));
				switch (A[i][j])
				{
				case -1: danhdau(-1, i, j); break;
				case 1: danhdau(1, i, j); break;
				}
			}
			gotoxy(chuyenx(_X), chuyeny(_Y));
	f.close();
}
void savegame(string tenfile)
{
	bool check = true;
	tenfile += ".txt";
	fstream f;

	for (int i = 1; i <= nofs; i++) if (P[i] == tenfile) { check = false; break; }
	if (check == true) {
		fstream k;
		k.open(LIST, ios::app | ios::out);
		k << tenfile << endl;
		k.close();
	}
	f.open(tenfile, ios::out);
	f << _NAMEX << " " << _NAMEO << endl;
	f << _TURN << " " << _PLAYERX << " " << _PLAYERO << " " << _SoX << " " << _SoO << endl;
	for (int i = 0; i < BOARD; i++)
		for (int j = 0; j < BOARD; j++)
			if (A[i][j] != 0) f << i << " " << j << " " << A[i][j] << endl;
	f.close();
}
int thoat()
{
	int c;
	string tenfile;
	Board(36, 7, 107, 29, 0);
	SetColor(GREEN_LYE);
	gotoxy(112, 29);
	cout << "----------EXIT---------- ";
	gotoxy(110, 31);
	cout << " Ban co muon save khong: ";
	gotoxy(114, 32);
	cout << "Yes(Y/y)    No(N/n)";
	gotoxy(135, 31);
	do
	{
		c = toupper(_getch());
	} while (c != 'Y' && c != 'N' && c != 27);
	if (c == 'Y' && c != 'N') {
		gotoxy(110, 34);
		cout << " Nhap ten file: " << endl;
		gotoxy(126, 34);
		cin >> tenfile;
		savegame(tenfile);
	}
	else if (c == 27) return 0;
	return 1;
	SetColor(CO_THEME);
}
bool KtraTen(char a[], char b[])
{
	for (int i = 0; i < LONG; i++)
	{
		if (a[i] != b[i])
		{
			return FALSE;
			break;
		}
	}
}
void DangNhap()
{
	int ktra;
	Erase(150, 40, 0, 0);
	Board(65, 4, 50, 18, 0);
	SetColor(GREEN_LYE);
	gotoxy(52, 19);
	cout << "Nhap ten nguoi choi X: ";
	gotoxy(75, 19);
	do
	{
		if (cin.peek() != '\n') {
			cin >> _NAMEX;
			ktra = 1;
		}
		else
		{
			cin.clear();
			cin.ignore();
			gotoxy(52, 20);
			cout << "Chua nhap ten";
			gotoxy(75, 19);
			ktra = 0;
		}
	} while (ktra == 0);
	gotoxy(52, 20);
	cout << "                                  ";
	cin.clear();
	cin.ignore();
	gotoxy(52, 19);
	cout << "Nhap ten nguoi choi O:                                        ";
	gotoxy(75, 19);
	do
	{
		if (cin.peek() != '\n') {
			cin >> _NAMEO;
			ktra = 1;
		}
		else 
		{
			cin.clear();
			cin.ignore();
			gotoxy(52, 19);
			cout << "Nhap ten nguoi choi O:                                        ";
			gotoxy(52, 20);
			cout << "Chua nhap ten";
			gotoxy(75, 19);
			ktra = 0;
		}
		if (KtraTen(_NAMEX, _NAMEO) != FALSE)
		{
			gotoxy(52, 20);
			cout << "Ten trung nhau";
			gotoxy(75, 19);
		}
	} while (ktra == 0 || KtraTen(_NAMEX, _NAMEO) != FALSE);
}
int game(int lenh, string tenfile, int k, string a[50])
{
	nofs = k;
	for (int i = 1; i <= nofs; i++) P[i] = a[i];
	if (lenh == 1) DangNhap();
	BangDiem();
	if (lenh == 2) loadgame(tenfile);
	while (1)
	{
		_COMMAND = toupper(_getch());
		if (_COMMAND != 27)
		{
			if (_COMMAND == 'A' || _COMMAND == 75) Moveleft();
			else if (_COMMAND == 'D' || _COMMAND == 77) Moveright();
			else if (_COMMAND == 'S' || _COMMAND == 80) Movedown();
			else if (_COMMAND == 'W' || _COMMAND == 72) Moveup();
			else if (_COMMAND == 13 || _COMMAND == 32)
			{
				if (A[_X][_Y] == 0)
				{
					switch (_TURN)
					{
					case -1: 
						_SoX++;
						BoardGraphics(); 
						OTurnGraph(); 
						SetColor(RED_W);
						gotoxy(86, 19);
						cout << "So X: " << _SoX;
						SetColor(CYAN_W);
						gotoxy(128, 16); cout << _NAMEO;
						SetColor(GREY_W);
						gotoxy(93, 16); cout << _NAMEX;
						danhdau(-1, _X, _Y); 
						_TURN = 1; 
						break;
					case 1: 
						_SoO++;
						BoardGraphics(); 
						XTurnGraph(); 
						SetColor(CYAN_W);
						gotoxy(86, 21);
						cout << "So O: " << _SoO;
						SetColor(RED_W);
						gotoxy(93, 16); cout << _NAMEX;
						SetColor(GREY_W);
						gotoxy(128, 16); cout << _NAMEO;
						danhdau(1, _X, _Y); 
						_TURN = -1;
						break;
					}
				}
				_COUNT++;
			}
			if (_COUNT == (BOARD) * (BOARD))
			{
				system("color 70");
				Board(87, 14, 81, 26, 0);
				Draw(87, 26);
				lenhr();
			}
			if (thang() == -1) {
				system("color 70");
				grapdetect();
				XTurnGraph();
				SetColor(RED_W);
				gotoxy(93, 16); cout << _NAMEX;
				Board(87, 14, 81, 26, 0);
				XWin(85, 26);
				SetColor(RED_W);
				VeSo(++_PLAYERX, 108, 18); lenhr();
			}
			else if (_WIN == 1) {
				system("color 70");
				grapdetect();
				OTurnGraph();
				SetColor(CYAN_W);
				gotoxy(128, 16); cout << _NAMEO;
				Board(87, 14, 81, 26, 0);
				OWin(85, 26);
				SetColor(CYAN_W);
				VeSo(++_PLAYERO, 136, 18); lenhr();
			}
		}
		else {
			if (thoat())
			{
				SetColor(CO_THEME);
				_PLAYERO = 0;
				_PLAYERX = 0;
				break;
			}
			else {
				SetColor(GREEN_LYE);
				for (int i = 0; i < 10; i++)
				{
					gotoxy(107, 28+i);
					cout << "                                     ";
				}
				gotoxy(chuyenx(_X), chuyeny(_Y));
			}
		}
	}
	return 0;
}
void grapdetect()
{
	for (int i = 1; i <= 5; i++)
	{
		gotoxy(chuyenx(WINDT[i].x) - 1, chuyeny(WINDT[i].y));
		switch (WINDT[i].c)
		{
		case 1: 
			SetColor(16 * 14 + 4);
			cout << " O ";
			break;
		case -1:
			SetColor(16 * 14 + 3);
			cout << " X "; 
			break;
		}
	}

}

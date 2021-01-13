#include "Game.h"
#include "File.h"
#include "main.h"
#include "Graphic.h"
#include "Console.h"
int numfile;
int nof;
string namefile;
string F[50];
void taofile()
{
	if ("list.txt" == NULL)
	{
		fstream f;
		f.open(LIST, ios::app | ios::out);
		f.close();
	}
}
int menu()
{
	SetColor(7);
	MainCaro();
	MainMenu();
	return 4;
}
void dichuyenmenu(int dh, int k)
{
	switch (k)
	{
	case 1:
	{
		if (dh == 2)
		{
			SetColor(GREEN_LYE);
			gotoxy(gox - 1, goy + k - 1); cout << "  NEW GAME   ";
			SetColor(LGREEN_LW);
			gotoxy(gox - 1, goy + k); cout <<     "> LOAD GAME <";
			break;
		}
	}
	case 2:
	{
		if (dh == 1)
		{
			SetColor(LGREEN_LW);
			gotoxy(gox - 1, goy + k - 2); cout << "> NEW GAME  <";
			SetColor(GREEN_LYE);
			gotoxy(gox - 1, goy + k - 1); cout << "  LOAD GAME  ";
			break;
		}
		if (dh == 2)
		{
			SetColor(GREEN_LYE);
			gotoxy(gox - 1, goy + k - 1); cout << "  LOAD GAME  ";
			SetColor(LGREEN_LW);
			gotoxy(gox - 1, goy + k); cout <<     "> HELP      <";
			break;
		}
	}
	case 3:
	{
		if (dh == 1)
		{
			SetColor(LGREEN_LW);
			gotoxy(gox - 1, goy + k - 2); cout << "> LOAD GAME <";
			SetColor(GREEN_LYE);
			gotoxy(gox - 1, goy + k - 1); cout << "  HELP       ";
			break;
		}
		if (dh == 2)
		{
			SetColor(GREEN_LYE);
			gotoxy(gox - 1, goy + k - 1); cout << "  HELP       ";
			SetColor(LGREEN_LW);
			gotoxy(gox - 1, goy + k); cout <<     "> ABOUT     <";
			break;
		}
	}
	case 4:
	{
		if (dh == 1)
		{
			SetColor(LGREEN_LW);
			gotoxy(gox - 1, goy + k - 2); cout << "> HELP      <";
			SetColor(GREEN_LYE);
			gotoxy(gox - 1, goy + k - 1); cout << "  ABOUT      ";
			break;
		}
		if (dh == 2)
		{
			SetColor(GREEN_LYE);
			gotoxy(gox - 1, goy + k - 1); cout << "  ABOUT      ";
			SetColor(LGREEN_LW);
			gotoxy(gox - 1, goy + k); cout <<     "> EXIT      <";
			break;
		}
	}
	case 5:
	{
		if (dh == 1)
		{
			SetColor(LGREEN_LW);
			gotoxy(gox - 1, goy + k - 2); cout << "> ABOUT     <";
			SetColor(GREEN_LYE);
			gotoxy(gox - 1, goy + k - 1); cout << "  EXIT       ";
			break;
		}
	}
	}
	SetColor(CO_THEME);
}
int nhap(int lenh, int l, int r)
{
	int k = 1;
	gotoxy(gox - 1, goy);
	SetColor(LGREEN_LW);
	cout << "> NEW GAME  <";
	SetColor(GREEN_LYE);
	do {
		lenh = toupper(_getch());
		if ((lenh == 'W' || lenh == 72) && k > l) {
			dichuyenmenu(1, k); k--; gotoxy(gox, goy + k - 1);
		}
		else if ((lenh == 'S' || lenh == 80) && k < r)
		{
			dichuyenmenu(2, k); k++; gotoxy(gox, goy + k - 1);
		}
		else if (lenh == 13) {
			return k; break;
		}
	} while (1);
}
int loa()
{
	nof = 0;
	string tenfile;
	fstream f;
	f.open(LIST, ios::in);
	gotoxy(gox + 5, goy - 7);
	SetColor(GREEN_LYE);
	cout << " LOAD DATA";
	gotoxy(gox - 3, goy - 6);
	cout << "------------------------------";
	while (!f.eof())
	{
		f >> tenfile;
		if (tenfile[0] == ' ') break;
		else if (tenfile[0] == '\n') break;
		else if (tenfile == "\0") break;
		nof++;
		gotoxy(gox + 1, goy - 6 + nof);
		SetColor(GREEN_LYE);
		cout << tenfile << endl;
		F[nof] = tenfile;
		tenfile="\0";

	}
	gotoxy(gox + 1, goy + nof - 5); cout << "------------------";
	gotoxy(gox + 1, goy + nof - 4);  cout << "BACK";
	f.close();
	return 0;
}
void dichuyenmenuload(int dh, int k)
{
	SetColor(GREEN_LYE);
	switch (dh)
	{
	case 1:
	{
		gotoxy(gox - 1, goy - 7 + k - 1); cout << " ";
		gotoxy(gox - 1, goy - 7 + k - 2); cout << ">";
		break;
	}
	case 2:
	{
		gotoxy(gox - 1, goy - 7 + k - 1); cout << " ";
		gotoxy(gox - 1, goy - 7 + k); cout << ">";
		break;
	}
	}
	SetColor(CO_THEME);
}
int nhapmenuload(int l, int r)
{
	int k = 3;
	char lenh;
	gotoxy(gox - 1, goy - 5);
	SetColor(GREEN_LYE);
	cout << ">";
	do {
		lenh = toupper(_getch());
		if (lenh == 'W' && k > l) {
			dichuyenmenuload(1, k); k--; gotoxy(gox, goy + k - 8);
		}
		else if (lenh == 'S' && k <= r)
		{
			dichuyenmenuload(2, k); k++; gotoxy(gox, goy + k - 8);
		}
		else if (lenh == 13 && k != r) {
			return k; break;
		}
	} while (1);
}
int xuly(int lenh)
{
	int enter;
	if (lenh == 1) {
		namefile = ""; 
		return 1;
	}
	else if (lenh == 2)
	{
		Erase(30, 9, 60, 23);
		loa();
		Board(40, nof + 5, 60, 18, 0);
		loa();
		numfile = nhapmenuload(3, (nof + 3));
		if (numfile < nof + 3)
		{
			namefile = F[numfile - 2];
			return 2;
		}
		else return -1;
	}
	else if(lenh == 3)
	{
		Erase(30, 9, 60, 23);
		Board(100, 21, 40, 18, DELAY - 20);
		help(41, 20);
		Enter(85, 41);
		enter = _getch();
		if (enter == 13) return 3;
	}
	else if (lenh == 4)
	{
		Erase(30, 9, 60, 23);
		Board(80, 21, 40, 18, DELAY - 20);
		about(50, 20);
		Enter(73, 41);
		enter = _getch();
		if (enter == 13) return 4;
	}
	else return 5;
}
void about(int x, int y)
{
	SetColor(GREEN_LYE);
	gotoxy(x - 4, y);
	cout << "Tro choi duoc thuc hien va hoanh thanh boi NHOM 23 - NMLT - Lop 20CTT3" ;
	gotoxy(x, y + 2);
	cout << "                 GVHD - Truong Toan Thinh             ";
	gotoxy(x, y + 6);
	cout << "                 Cac thanh vien cua nhom gom:             " ;
	gotoxy(x, y + 8);
	cout << "                 20120357 - Nguyen Duc Minh Quan          " ;
	gotoxy(x, y + 10);
	cout << "                 20120364 - Pham Phuoc Sang               " ;
	gotoxy(x, y + 12);
	cout << "                 20120382 - Hoang Thu Thuy                " ;
	gotoxy(x, y + 14);
	cout << "                 20120468 - Nguyen Van Hai                " ;
	gotoxy(x, y + 16);
	cout << "                 20120475 - Nguyen Minh Hieu              ";
}
void help(int x, int y)
{
	SetColor(GREEN_LYE);
	gotoxy(x, y);
	cout << "                                           LUAT CHOI                                              ";
	gotoxy(x, y+2);
	cout << "--------------------------------------------------------------------------------------------------";
	gotoxy(x, y+4);
	cout << "1. Van dau co caro duoc bat dau voi hai nguoi choi o 2 phia chia lam X va O";
	gotoxy(x, y+6);
	cout << "2. Van dau duoc xem nhu thang khi mot ben danh lien tuc 5 dau lien tiep theo hang cheo, doc, ngang";
	gotoxy(x, y+8);
	cout << "3. Khong ap dung luat chang 2 dau khong thang ";
	gotoxy(x, y+10);
	cout << "4. Van game duoc tinh la hoa khi het o de danh ma van chua co nguoi thang ";
	gotoxy(x, y+12);
	cout << "Su dung nut A,W,S,D hoac cac phim mui ten de di chuyen va dung phim Enter/Space de danh dau";
	gotoxy(x, y+14);
	cout << "Save game duoc thuc hien trong tran dau, Load game duoc thuc hien ngoai menu chinh cua game";
}
void main()
{
	int lein;
	createconsole();
	console();
	taofile();
	do {
		lein = xuly(nhap(menu(), 1, 5));
		if (lein <= 2 && lein > 0) 	game(lein, namefile, nof, F);
		system("cls");
	} while (lein != 5);
}
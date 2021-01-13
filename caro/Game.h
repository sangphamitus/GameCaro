#pragma once
#ifndef __GAME_H__
#define __GAME_H__
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "Control.h"
using namespace std;
#define BOARD 20
#define CK 5
#define LIST "list.txt"
#define LONG 15
#define GREEN_W 7 * 16 + 2
#define RED_W 7 * 16 + 3
#define CYAN_W 7 * 16 + 4
#define GREEN_LYE 14 * 16 + 2
#define YELLOW_W 7 * 16 + 6
#define GREY_W 7 * 16 + 8
#define LGREEN_LW 15 * 16 + 10
#define LGREEN_LYE 14 * 16 + 10
#define RED_LYE 14 * 16 + 3
#define CYAN_LYE 14 * 16 + 4
#define GREY_LYE 14 * 16 + 8
int chuyenx(int a);
int chuyeny(int a);
void danhdau(int a, int x, int y);
void Moveleft();
void Moveright();
void Moveup();
void Movedown();
void kebang();
void ResetData();
void lenhr();
void checkxeotp();
void checkxeopt();
void doc();
void ngang();
int thang();
int thoat();
bool KtraTen(char a[], char b[]);
void DangNhap();
int game(int, string, int, string[50]);
void grapdetect();
void BangDiem();
void dichuyenmenuload(int dh, int k);
void about(int, int);
void help(int, int);
#endif


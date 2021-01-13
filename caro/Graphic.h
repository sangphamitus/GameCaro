#pragma once
#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__
#define DELAY 50
#include <iostream>
using namespace std;
void Ve(int t);
void kVe(int t);
int VeSo(int, int, int);
void MainCaro();
void MainMenu();
void BoardGraphics();
void XTurnGraph();
void OTurnGraph();
void Board(int dai, int rong, int x, int y, int delay);
void XWin(int, int);
void OWin(int, int);
void Draw(int, int);
void Enter(int, int);
void Erase(int d, int r, int x, int y);

#endif

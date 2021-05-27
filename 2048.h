#ifndef TWO_H
#define TWO_H
#include <bits/stdc++.h>
#include <conio.h>
#define BOARD_SIZE 8
void board(std::vector<std::vector<int>>);
void startBoard(std::vector<std::vector<int>> &);
void actionBasedOnKeyPressed(char, std::vector<std::vector<int>>&, bool&);
void alterBoard(std::vector<std::vector<int>> &);
bool checkGameOver(std::vector<std::vector<int>> bM);
void printScore(bool ultWin);
bool boardFull(std::vector<std::vector<int>>);
std::vector<std::vector<std::string>> intToChar(std::vector<std::vector<int>>);
bool highestReached(std::vector<std::vector<int>>);
#endif

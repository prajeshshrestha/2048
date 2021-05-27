#ifndef TWO_H
#define TWO_H
#include <bits/stdc++.h>
#include <conio.h>

void board(std::vector<std::vector<int>>);
void startBoard(std::vector<std::vector<int>> &);
void actionBasedOnKeyPressed(char, std::vector<std::vector<int>>&, bool&);
void alterBoard(std::vector<std::vector<int>> &);
bool checkGameOver(std::vector<std::vector<int>> bM);

#endif

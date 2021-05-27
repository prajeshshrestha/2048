#include "2048.h"


int main(int argc, char** argv) 
{
	//initializers
	//initializing 4x4 board
	std::vector<std::vector<int>> bM = 
	{
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}
	};
	bool isRunning = true;
	startBoard(bM);
	
	while(isRunning)
	{
		system("CLS");
		board(bM);
		char kI;
		kI = getch();
		actionBasedOnKeyPressed(kI, bM, isRunning);
		if(checkGameOver(bM) && boardFull)
		{
			isRunning = false;
			std::cout << "\n\n\t\t\tNo more moves available\n";
		}
	}
	printScore();
	
	return 0;
}

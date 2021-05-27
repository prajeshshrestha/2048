#include "2048.h"

int main(int argc, char** argv) 
{
	//initializing 4x4 board
	std::vector<std::vector<int>> bM(BOARD_SIZE, std::vector<int>(BOARD_SIZE, 0));
	bool isRunning = true;
	bool ultWin = false;
	startBoard(bM);
	while(isRunning)
	{
		system("CLS");
		board(bM);
		char kI;
		kI = getch();
		actionBasedOnKeyPressed(kI, bM, isRunning);
		if(checkGameOver(bM) && boardFull(bM))
		{
			isRunning = false;
			std::cout << "\n\n\t\t\tNo more available moves\n";
		}
		if(highestReached(bM))
		{
			isRunning = false;
			ultWin = true;
		}
	}
	printScore(ultWin);
	return 0;
}

#include "2048.h"
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

void board(std::vector<std::vector<int>> bM)
{
	std::cout << "\n\n\n\n\n";
	for(auto i : bM)
	{
		std::cout << "\t\t\t\t\t";
		for(auto j : i)
			std::cout << j << "\t";
		std::cout << "\n\n";
	}	
	std::cout << "\n\n\t\t\t\t      Controls: Use the arrow keys."; 
	std::cout << "\n\t\t\t\t      Press q to quit.";

	std::cout << "\n\n\n";
}

void startBoard(std::vector<std::vector<int>> &aBM)
{
	srand(time(NULL));
	int a = rand()%16;
	int b = rand()%16;
	while(b == a)
	{
		b = rand()%16;
	}
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			int x = i*4 + j +1;
			if(x == a || x == b)
			{
				aBM[i][j] = 2;
			}
		}
	}
}

void actionBasedOnKeyPressed(char key, std::vector<std::vector<int>> &bData, bool &isRunning)
{
	int tempInt = 9;
	if(int(key)== KEY_LEFT)
	{
		std::cout << "You Pressed Left key.";
		for(int i = 0; i < 4; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				if(bData[i][j] != 0 && j != 0)
				{
					tempInt = bData[i][j];
					std::cout << i << "   " << j << " temp:  " << tempInt << std::endl;
					bData[i][j] = 0;
					bool found = false;
					for(int k = j-1; k >= 0; k--)
					{
						if(bData[i][k] == tempInt)
						{
							bData[i][k] = 2*tempInt;
							found = true;
						}
						else if(k == i && !found)
						{
							std::cout << "Yeah bruh you entered here!!" << std::endl;
							std::cout << i << " " << k << std::endl;
							bData[i][k] = tempInt;
							found = false;
								
						}
						
					}
				}
			}
		}
	}
	else if(int(key)== KEY_RIGHT)
	{
		std::cout << "You Pressed Right key.";
	}
	else if(int(key)== KEY_UP)
	{
		std::cout << "You Pressed Up key.";
	}
	else if(int(key)== KEY_DOWN)
	{
		std::cout << "You Pressed down key.";
	}
	else if(key == 'q' || key == 'Q')
	{
		isRunning = false;
	}
}














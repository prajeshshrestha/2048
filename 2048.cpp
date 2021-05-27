#include "2048.h"
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

int score = 0;

void board(std::vector<std::vector<int>> bM)
{
	std::cout << "\n\n\n\n\n";
	std::cout << "\n\t\t     |------|-------|-------|-------|\n";
	for(auto i : bM)
	{
		std::cout << "\t\t     |  ";
		for(auto j : i)
		{
			std::cout << j;
			std::cout << "   |   ";
		}
			
		std::cout << "\n\t\t     |------|-------|-------|-------|";
		std::cout << "\n";
	}	
	std::cout << "\n\n\t\t      Controls: Use the arrow keys."; 
	std::cout << "\n\t\t      Press q to quit.";
	std::cout << "\n\t\t      Score: " << score;

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

void calcVec(std::vector<int> &test)
{
	int tempInt;
	for(int i = 0; i < 4; i++)
	{
		if(test[i] != 0 && i != 0)
		{
			tempInt = test[i];
			bool found = false;
			test[i] = 0;
			for(int k = i -1; k >=0; k--)
			{
				if(test[k] == tempInt)
				{
					test[k] = 2*tempInt;
					score += 2*tempInt;
					break;
				}
				else if(test[k] != 0 && test[k] != tempInt)
				{
					test[k+1] = tempInt;
					break;
				}
				else if(k == 0)
				{
					test[k] = tempInt;
				}
			}
		}
	}
}

void alterBoard(std::vector<std::vector<int>> &bM)
{
    int pos = 0;
    std::vector<int> freeSpace;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++, pos++)
        {
            if(bM[i][j] == 0)
                freeSpace.push_back(pos);
        }
    }
    srand(time(NULL));
    int randPos = freeSpace[std::rand()%freeSpace.size()];
    bM[randPos/4][randPos%4] = 2;
    for(auto i : bM)
    {
        for(auto j : i)
        {
            std::cout << j << '\t';
        }
        std::cout << '\n';
    }
    std::cout << "\n\n";
}

void upDownMovement(std::vector<std::vector<int>> &bM, bool downKey = false)
{
    std::vector<int> tempVec;
    int j = 0;
    for(int j = 0; j < 4 ; j++)
    {
        for(int i = 0; i < 4; i++)
        {
            tempVec.push_back(bM[i][j]);
        }
        if(downKey)
        {
            std::reverse(tempVec.begin(), tempVec.end());
            calcVec(tempVec);
            std::reverse(tempVec.begin(), tempVec.end());
        }
        else
            calcVec(tempVec);
        for(int i = 0; i < 4; i++)
        {
            bM[i][j] = tempVec[i];
        }
        tempVec.clear();
    }
    for(auto i : bM)
    {
        for(auto j : i)
            std::cout << j << '\t';
        std::cout << std::endl;
    }
}

void actionBasedOnKeyPressed(char key, std::vector<std::vector<int>> &bData, bool &isRunning)
{
	int tempInt = 9;
	std::vector<std::vector<int>> copyVec(bData);
	if(int(key)== KEY_LEFT)
	{
		for(auto &item : bData)
			calcVec(item);
		if(copyVec != bData)
			alterBoard(bData);
	}
	else if(int(key)== KEY_RIGHT)
	{
		for(auto &item : bData)
		{
			std::vector<int> tempVec(item);
			std::reverse(tempVec.begin(), tempVec.end());
			calcVec(tempVec);
			std::reverse(tempVec.begin(), tempVec.end());
			item = tempVec;
		}
		if(copyVec != bData)
			alterBoard(bData);
		
	}
	else if(int(key)== KEY_UP)
	{
		upDownMovement(bData);
		if(copyVec != bData)
			alterBoard(bData);
		
	}
	else if(int(key)== KEY_DOWN)
	{
		upDownMovement(bData, true);
		if(copyVec != bData)
			alterBoard(bData);
	}
	else if(key == 'q' || key == 'Q')
	{
		isRunning = false;
	}
}



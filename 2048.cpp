#include "2048.h"
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77


int score = 0;
std::vector<std::vector<std::string>> intToChar(std::vector<std::vector<int>> bM)
{
	std::vector<std::vector<std::string>> result(BOARD_SIZE, std::vector<std::string>(BOARD_SIZE, " "));
	for(int i = 0; i < BOARD_SIZE; i++)
		for(int j = 0; j < BOARD_SIZE; j++)
			bM[i][j] == 0 ? result[i][j] = " " : result[i][j] = std::to_string(bM[i][j]);
	return result;
}


void board(std::vector<std::vector<int>> cM)
{
	std::vector<std::vector<std::string>> bM = intToChar(cM);
	std::cout << "\n\n\n\n\n";
	std::cout << "\n\t\t     |------|-------|-------|-------|\n";
	for(std::vector<std::string> i : bM)
	{
		std::cout << "\t\t     |  ";
		for(std::string j : i)
		{
			std::cout << j;
			if(j.length() == 2)
				std::cout << "  |   ";
			else if(j.length() == 3)
				std::cout << " |   ";
			else if(j.length() == 4)
				std::cout << "|   ";
			else if(j.length() == 1)
				std::cout << "   |   ";
		}
		std::cout << "\n\t\t     |------|-------|-------|-------|\n";
	}	
	std::cout << "\n\n\t\t      Controls: Use the arrow keys.\n\t\t      Press 'q' to quit.\n\t\t      Score: " << score << "\n\n\n"; 
}

void startBoard(std::vector<std::vector<int>> &aBM)
{
	alterBoard(aBM);
	alterBoard(aBM);
}

void calcVec(std::vector<int> &test)
{
	int tempInt;
	for(int i = 0; i < BOARD_SIZE; i++)
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
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        for(int j = 0; j < BOARD_SIZE; j++, pos++)
        {
            if(bM[i][j] == 0)
                freeSpace.push_back(pos);
        }
    }
    srand(time(NULL));
    int randPos = freeSpace[std::rand()%freeSpace.size()];
	int num = [](){return std::rand()%2 == 0 ? 2 : 4;}();
    bM[randPos/BOARD_SIZE][randPos%BOARD_SIZE] = num;
}

void upDownMovement(std::vector<std::vector<int>> &bM, bool downKey = false)
{
    std::vector<int> tempVec;
    int j = 0;
    for(int j = 0; j < BOARD_SIZE ; j++)
    {
        for(int i = 0; i < BOARD_SIZE; i++)
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
        for(int i = 0; i < BOARD_SIZE; i++)
        {
            bM[i][j] = tempVec[i];
        }
        tempVec.clear();
    }
}

bool boardFull(std::vector<std::vector<int>> bM)
{
	for(auto i : bM)
		for(auto j : i)
			if(j == 0)
				return false;
	return true;
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

bool checkGameOver(std::vector<std::vector<int>> bM)
{
	std::vector<std::vector<int>> copyVec = bM;
	std::vector<int> keys = {72, 75, 77, 80};
	int counter;
	bool isRunning = true;
	int tempScore = score;
	for(auto i : keys)
	{
		actionBasedOnKeyPressed(char(i), copyVec, isRunning);
		if(bM == copyVec)
			counter++;
	}
	score = tempScore;
	return counter == 4 ? true : false;
}
void printScore(bool ultWin)
{
	std::cout << "\t\t\tYour final score: " << score << std::endl;
	std::ifstream file("savedata");
	std::string data;
	file >> data;
	if(ultWin)
	{
		std::cout <<  "\t\t\tWinner Winner Chichken Dinner!!!" << std::endl;
	}
	else if(score > stoi(data))
	{
		std::ofstream file1("savedata");
		file1 << score;
		std::cout << "\t\t\tCongrats! You just smashed the highest score." << std::endl;
		std::cout << "\t\t\tThe new highest score is: " << score << std::endl;
	}
	else
		std::cout << "\t\t\tHighest score: " << stoi(data) << std::endl;
}

bool highestReached(std::vector<std::vector<int>> bM)
{
	for(auto i : bM)
		for(auto j : i)
			if(j == 2048)
				return true;
	return false;
}
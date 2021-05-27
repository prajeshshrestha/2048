#include <bits/stdc++.h>

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
	for(auto i : test)
		std::cout << i << "\t";
	std::cout << "\n\n";
}

int main()
{
	std::vector<int> test = {0,0,0,0};
	std::vector<int> test1 = {0,0,2,2};
	std::vector<int> test2 = {0,2,0,2};
	std::vector<int> test3 = {2,0,2,2};
	std::vector<int> test4 = {2,2,2,2};
	std::vector<std::vector<int>> testFinal =
	{
		{0,0,2,2},
		{0,0,2,0},
		{2,0,2,0},
		{2,0,0,0}
	};
	for(auto &item : testFinal)
	{
		calcVec(item);
	}

	
}

















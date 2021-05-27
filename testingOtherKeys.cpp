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
}

int main()
{
    std::vector<std::vector<int>> bM = 
	{
		{0,2,2,0},
		{0,0,0,0},
		{2,2,2,2},
		{0,0,2,0}
	};
    for(auto &item : bM)
    {
        std::vector<int> tempVec(item);
        std::reverse(tempVec.begin(), tempVec.end());
        calcVec(tempVec);
        std::reverse(tempVec.begin(), tempVec.end());
        item = tempVec;
    }
    for(auto i : bM)
    {
        for (auto j : i)
            std::cout << j << '\t';
        std::cout << std::endl;
    }
}
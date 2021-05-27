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

int main()
{
    std::vector<std::vector<int>> bM = 
	{
		{0,2,2,0},
		{0,0,2,0},
		{2,2,2,2},
		{0,0,2,0}
	};
    upDownMovement(bM);
    upDownMovement(bM, true);
}
#include <bits/stdc++.h>

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

int main()
{
    std::vector<std::vector<int>> testing
    {
		{0,2,0,0},
		{0,0,0,0},
		{0,2,0,0},
		{0,0,0,0}
	};
    alterBoard(testing);
    alterBoard(testing);
    alterBoard(testing);
    alterBoard(testing);

}
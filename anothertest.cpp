#include <bits/stdc++.h>


std::vector<std::vector<std::string>> intToCharVec(std::vector<std::vector<int>> test)
{
    std::vector<std::vector<std::string>> result =
     {
		{" "," "," "," "},
		{" "," "," "," "},
		{" "," "," "," "},
		{" "," "," "," "}
	};
	for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(test[i][j] == 0)
            {
                result[i][j] = " ";
            }
            else
            {
                result[i][j] = std::to_string(test[i][j]);
            }
        }
    }
	return result;
}

int main()
{
    std::vector<std::vector<int>> test 
    {
		{0,0,0,0},
		{0,0,0,8},
		{0,0,2,0},
		{0,16,0,0}
	};
    std::vector<std::vector<std::string>> result = intToCharVec(test);
    for(auto i : result)
    {
        for(auto j : i)
            std::cout << j << '\t';
        
        std::cout << std::endl;
    }

}
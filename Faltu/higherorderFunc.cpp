#include <bits/stdc++.h>

bool parser(std::string x)
{
    return x[0] == 'P';
}

std::vector<std::string> vecParser(std::vector<std::string> x, std::function<bool(std::string)> Upser)
{
    std::vector<std::string> result;
    for(auto str : x)
    {
        if(Upser(str))
            result.push_back(str);
    }
    return result;
}

int main()
{
    std::vector<std::string> smthng = {"Prajesh", "Shrestha", "Periodic"};
    for(auto str : vecParser(smthng, parser))
        std::cout << str << std::endl;
}
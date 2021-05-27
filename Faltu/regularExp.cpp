#include <bits/stdc++.h>

int main()
{
	std::string str = "The cat and fat ran together to accomplish nothing good but their distances from the point of rendezvous was oblivious";
	std::cout << std::boolalpha;
	std::cout << std::regex_match(str, std::regex("(t|T).*"));
}

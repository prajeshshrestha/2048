#include <bits/stdc++.h>

void finalFunc(std::string &result, std::string x, int carryT, int pos)
{
	int s_val = 0;
	std::cout << result << "  " << x << "  " << carryT << "  " << pos;
	while(pos > 0)
	{
		s_val = int(x[pos])-48+carryT;
		carryT = s_val /10;
		s_val = s_val % 10;
		result.insert(0, std::to_string(s_val));
		pos--;
	}
	result.insert(0, std::to_string(int(x[pos])-48+carryT));
}

std::string sum_strings(const std::string& a, const std::string& b) {
	int s_value = 0;
	int carryT = 0;
	std::string result = ""; 

	int i = a.size(); 
	int j = b.size();
	//running the loop in opposite order
	for(--i, --j; i > -1 && j > -1; i--, j--)
	{
		s_value = carryT + int(a[i]) + int(b[j]) - 96;
		carryT = s_value/10;
		s_value = s_value%10;
		result.insert(0, std::to_string(s_value));
	}
	
	if(i == -1 && j == -1 && carryT != 0)
		result.insert(0, std::to_string(carryT));
	
	if(i > j)
		finalFunc(result, a, carryT, i);
	else if(j > i)
		finalFunc(result, b, carryT, j);
	
//	if(i > j)
//	{
//		while(i > 0)
//		{
//			s_value = int(a[i])-48+carryT;
//			carryT = s_value /10;
//			s_value = s_value % 10;
//			result.insert(0, std::to_string(s_value));
//			i--;
//		}
//		result.insert(0, std::to_string(int(a[i])-48+carryT));
//	}
//	else if(j > i)
//	{
//		while(j > 0)
//		{
//			s_value = int(b[j])-48+carryT;
//			carryT = s_value /10;
//			s_value = s_value % 10;
//			result.insert(0, std::to_string(s_value));
//			j--;
//		}
//		result.insert(0, std::to_string(int(b[j])-48+carryT));
//	}
	return result;
}
int main()
{
	std::string a = "123";
	std::string b = "456";
	std::string smthng = "579";
	std::string result = sum_strings(a,b);
	std::cout << result << std::endl;
	if(result == smthng)
	{
		std::cout << "Voila" << std::endl;
	}

}

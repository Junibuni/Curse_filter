#include "Node.h"
#include <iostream>

#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <conio.h>
#include <time.h>

int main(void)
{
	List curse_list;
	std::ifstream inFile("Curse_DB1.txt");
	while (!inFile.eof())
	{
		std::string str;
		std::getline(inFile, str);
		curse_list.add(str);
	}
	inFile.close();

	std::string input;
	std::cout << "종료하려면 esc키 입력" << std::endl;

	do
	{
		std::cout << "문장을 입력하세요: ";
		std::getline(std::cin, input);
		clock_t start = 0, end = 0;
		start = clock();

		std::regex reg("");
		for (int i = 0; i < curse_list.size(); ++i)
		{
			reg = curse_list.getData(i);
			if (std::regex_search(input, reg))
			{
				if (curse_list.getData(i).size() / 2 == 2) input = std::regex_replace(input, reg, "**");
				else if (curse_list.getData(i).size() / 2 == 3) input = std::regex_replace(input, reg, "***");
				else if (curse_list.getData(i).size() / 2 == 4) input = std::regex_replace(input, reg, "****");
			}
		}
		std::cout << input << std::endl;


		end = clock();
		std::cout << "runtime: " << end - start << "ms" << std::endl;
	}while (_getch() != 27);

	return 0;
}
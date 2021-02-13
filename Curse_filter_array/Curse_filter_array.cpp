#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <conio.h>
#include <time.h>

std::string database = "Curse_DB.txt";

std::vector <std::string> create_list(std::string* filename)
{
	std::vector <std::string> curse_list;
	std::ifstream inFile(*filename);

	while (!inFile.eof())
	{
		std::string str;
		std::getline(inFile, str);
		curse_list.push_back(str);
	}
	inFile.close();

	return curse_list;
}	

void compare(std::vector <std::string>* list, std::string* sentence)
{
	std::regex reg("");
	std::string change_sentence = *sentence;
	for (int i = 0; i < (*(std::vector <std::string>*)list).size(); ++i)
	{
		reg = (*list)[i];
		if (std::regex_search(change_sentence, reg))
		{
			if ((*list)[i].size() / 2 == 2) change_sentence = std::regex_replace(change_sentence, reg, "**");
			else if ((*list)[i].size() / 2 == 3) change_sentence = std::regex_replace(change_sentence, reg, "***");
			else if ((*list)[i].size() / 2 == 4) change_sentence = std::regex_replace(change_sentence, reg, "****");
		}
	}

	std::cout << change_sentence << std::endl;
}

int main()
{
	std::vector <std::string> curse_list = create_list(&database);
	std::string input;
	std::cout << "Curse Filter Array" << std::endl;

	std::cout << "종료하려면 esc키 입력" << std::endl;
	do
	{
		std::cout << "문장을 입력하세요: ";
		std::getline(std::cin, input);
		clock_t start = 0, end = 0;
		start = clock();
		compare(&curse_list, &input);
		end = clock();
		std::cout << "runtime: " << end - start <<"ms"<< std::endl;
	} while (_getch() != 27);
	return 0;
}
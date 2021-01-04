#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

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
	for (int i = 1; i < (*(std::vector <std::string>*)list).size(); ++i)
	{
		reg = (*list)[i];
		
		if (std::regex_match(change_sentence, reg))
		{
			//한글의 숫자를 센뒤 밑에 '*' '**' '***' 정한다 --> 효율적인가?
			change_sentence = std::regex_replace(change_sentence, reg, "*");
		}
	}

	std::cout << change_sentence << std::endl;
}

int main()
{
	std::vector <std::string> curse_list = create_list(&database);
	std::string input;
	std::cout << "문장을 입력하세요: ";
	std::cin >> input;
	
	compare(&curse_list, &input);

	return 0;
}
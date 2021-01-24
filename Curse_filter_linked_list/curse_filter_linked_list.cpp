#include "Node.h"
#include "UnicodeConvert.h"
#include <stdio.h> //printf
#include <iostream> // cout
#include <locale.h>

#include <string>
#include <vector>
#include <regex>//정규표현식
#include <conio.h>//키 입력
#include <time.h>//시간

void sort_hangul(wchar_t* word, char* char_word);

List ga, na, da, ra, ma, ba, sa, ah, ja, cha, ka, ta, pa, ha;
List ko_order[14] = { ga, na, da, ra, ma, ba, sa, ah, ja, cha, ka, ta, pa, ha };
const char database[14] = "Curse_DB1.txt";
const char UTF8_type[13] = "rt,ccs=UTF-8";

int main(void)
{
	FILE* p_file = NULL;
	setlocale(LC_ALL, "ko-KR");
	
	if (0 == fopen_s(&p_file, database, UTF8_type))
	{
		List curse_list;
		wchar_t str[10];
		wchar_t* pline;
		char* char_pline;
		while (!feof(p_file))
		{
			pline = fgetws(str, 9, p_file);
			char_pline = ConvertWCtoC(pline);
			sort_hangul(pline, char_pline);

			//wprintf(L"%s\n", pline);
		}
		fclose(p_file);
	}


	//std::string input;
	//std::cout << "종료하려면 esc키 입력" << std::endl;

	//do
	//{
	//	std::cout << "문장을 입력하세요: ";
	//	std::getline(std::cin, input);
	//	clock_t start = 0, end = 0;
	//	start = clock();

	//	std::regex reg("");
	//	for (int i = 0; i < curse_list.size(); ++i)
	//	{
	//		reg = curse_list.getData(i);
	//		if (std::regex_search(input, reg))
	//		{
	//			if (curse_list.getData(i).size() / 2 == 2) input = std::regex_replace(input, reg, "**");
	//			else if (curse_list.getData(i).size() / 2 == 3) input = std::regex_replace(input, reg, "***");
	//			else if (curse_list.getData(i).size() / 2 == 4) input = std::regex_replace(input, reg, "****");
	//		}
	//	}
	//	std::cout << input << std::endl;


	//	end = clock();
	//	std::cout << "runtime: " << end - start << "ms" << std::endl;
	//}while (_getch() != 27);

	return 0;
}

void sort_hangul(wchar_t* word, char* char_word)
{
	if (word[0] >= 44032 && word[0] <= 45207) ko_order[0].add(char_word);		//가
	else if (word[0] >= 45208 && word[0] <= 45795) ko_order[1].add(char_word);	//나
	else if (word[0] >= 45796 && word[0] <= 46971) ko_order[2].add(char_word);	//다
	else if (word[0] >= 46972 && word[0] <= 47559) ko_order[3].add(char_word);	//라
	else if (word[0] >= 47560 && word[0] <= 48147) ko_order[4].add(char_word);	//마
	else if (word[0] >= 48148 && word[0] <= 49323) ko_order[5].add(char_word);	//바
	else if (word[0] >= 49324 && word[0] <= 50499) ko_order[6].add(char_word);	//사
	else if (word[0] >= 50500 && word[0] <= 51087) ko_order[7].add(char_word);	//아
	else if (word[0] >= 51088 && word[0] <= 52263) ko_order[8].add(char_word);	//자
	else if (word[0] >= 52264 && word[0] <= 52851) ko_order[9].add(char_word);	//차
	else if (word[0] >= 52852 && word[0] <= 53439) ko_order[10].add(char_word);	//카
	else if (word[0] >= 53440 && word[0] <= 54027) ko_order[11].add(char_word);	//타
	else if (word[0] >= 54028 && word[0] <= 54615) ko_order[12].add(char_word);	//파
	else if (word[0] >= 54616 && word[0] <= 55203) ko_order[13].add(char_word);	//하
}
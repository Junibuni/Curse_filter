#include <iostream> // cout
#include <string>
#include <vector>
#include <locale.h>
#include <map>
#include <conio.h>
#include <time.h>
#include <Windows.h>

using namespace std;

class Tree
{
public:
	Tree() : character(NULL) {};
	Tree(wchar_t input) : character(input){};
	void Insert(wchar_t* str)
	{
		Tree* curr = this; //항상 루트로 시작
		
		vector <wchar_t> word_store;
		word_store.reserve(wcslen(str));
		for (int i = 0; i < wcslen(str); ++i)
		{
			word_store.push_back(str[i]);
		}

		for (wchar_t ch : word_store)
		{
			bool tmp = curr->child.count(ch);
			if (!curr->child.count(ch)) //child 에 없으면?
			{
				curr->child.insert(make_pair(ch, new Tree(ch))); //그 단어의 tree node child* 생성
			}
			
			curr = curr->child[ch]; //문자가 있는 child 배열의 칸으로 이동
		}
	}
	int Search(wchar_t* str)
	{
		Tree* curr = this; //루트에서 시작
		vector <wchar_t> word_store;
		word_store.reserve(wcslen(str) + 1);
		for (int i = 0; i < wcslen(str); ++i)
		{
			word_store.push_back(str[i]);
		}
		word_store.push_back(NULL);

		for (wchar_t ch : word_store)
		{
			if (ch == NULL) return wcslen(str); //단어가 DB에 있음!

			//다음 글자가 없으면?
			if (!curr->child.count(ch)) return false; //DB에 없음!

			curr = curr->child[ch]; //child 로 이동
		}
		return false;
	}
private:
	map<wchar_t, Tree*> child;
	wchar_t character;

};


void Tokenize(const string& str, vector<string>& tokens, const string& delimiters = " ")
{
	// 맨 첫 글자가 구분자인 경우 무시
	string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	// 구분자가 아닌 첫 글자를 찾는다
	string::size_type pos = str.find_first_of(delimiters, lastPos);

	while (string::npos != pos || string::npos != lastPos)
	{
		// token을 찾았으니 vector에 추가한다
		tokens.push_back(str.substr(lastPos, pos - lastPos));
		// 구분자를 뛰어넘는다.  "not_of"에 주의하라
		lastPos = str.find_first_not_of(delimiters, pos);
		// 다음 구분자가 아닌 글자를 찾는다
		pos = str.find_first_of(delimiters, lastPos);
	}
}

string SwapToStars(string str, int cnt)
{
	string star("*");
	string output;
	if (cnt == 0) return str;
	for (int i = 0; i < cnt; ++i)
	{
		output += star;
	}

	return output;
}

wchar_t* ConvertCtoWC(const char* str)
{
	//wchar_t형 변수 선언
	wchar_t* pStr;

	//멀티 바이트 크기 계산 길이 반환
	int strSize = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, NULL);

	//wchar_t 메모리 할당
	pStr = new WCHAR[strSize];

	//형 변환
	MultiByteToWideChar(CP_ACP, 0, str, strlen(str) + 1, pStr, strSize);
	return pStr;
}

const char database[14] = "Curse_DB.txt";
const char UTF8_type[13] = "rt,ccs=UTF-8";

int main()
{
	Tree TreeRoot;
	FILE* p_file = NULL;
	setlocale(LC_ALL, "ko-KR");

	if (0 == fopen_s(&p_file, database, UTF8_type))
	{
		wchar_t str[10];
		wchar_t* pline;
		if (p_file != NULL)
		{
			while (!feof(p_file))
			{
				pline = fgetws(str, 9, p_file);
				TreeRoot.Insert(pline);
			}
			fclose(p_file);
		}
	}
	
	string input;
	std::cout << "Curse Filter Tree" << std::endl;
	cout << "종료하려면 esc키 입력" << endl;

	do
	{
		vector <string> tokens;
		cout << "문장을 입력하세요: ";
		std::getline(cin, input);
		Tokenize(input, tokens);

		clock_t start = 0, end = 0;
		start = clock();
	
		for (int i = 0; i < tokens.size(); ++i)
		{
			tokens[i] = SwapToStars(tokens[i], TreeRoot.Search(ConvertCtoWC(tokens[i].c_str())));
		}

		end = clock();
		for (int i = 0; i < tokens.size(); ++i)
		{
			cout << tokens[i] << " ";
		}
		cout << endl;
		cout << "runtime: " << end - start << "ms" << endl;
	} while (_getch() != 27);

	return 0;
}
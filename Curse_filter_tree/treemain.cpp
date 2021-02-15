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
		Tree* curr = this; //�׻� ��Ʈ�� ����
		
		vector <wchar_t> word_store;
		word_store.reserve(wcslen(str));
		for (int i = 0; i < wcslen(str); ++i)
		{
			word_store.push_back(str[i]);
		}

		for (wchar_t ch : word_store)
		{
			bool tmp = curr->child.count(ch);
			if (!curr->child.count(ch)) //child �� ������?
			{
				curr->child.insert(make_pair(ch, new Tree(ch))); //�� �ܾ��� tree node child* ����
			}
			
			curr = curr->child[ch]; //���ڰ� �ִ� child �迭�� ĭ���� �̵�
		}
	}
	int Search(wchar_t* str)
	{
		Tree* curr = this; //��Ʈ���� ����
		vector <wchar_t> word_store;
		word_store.reserve(wcslen(str) + 1);
		for (int i = 0; i < wcslen(str); ++i)
		{
			word_store.push_back(str[i]);
		}
		word_store.push_back(NULL);

		for (wchar_t ch : word_store)
		{
			if (ch == NULL) return wcslen(str); //�ܾ DB�� ����!

			//���� ���ڰ� ������?
			if (!curr->child.count(ch)) return false; //DB�� ����!

			curr = curr->child[ch]; //child �� �̵�
		}
		return false;
	}
private:
	map<wchar_t, Tree*> child;
	wchar_t character;

};


void Tokenize(const string& str, vector<string>& tokens, const string& delimiters = " ")
{
	// �� ù ���ڰ� �������� ��� ����
	string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	// �����ڰ� �ƴ� ù ���ڸ� ã�´�
	string::size_type pos = str.find_first_of(delimiters, lastPos);

	while (string::npos != pos || string::npos != lastPos)
	{
		// token�� ã������ vector�� �߰��Ѵ�
		tokens.push_back(str.substr(lastPos, pos - lastPos));
		// �����ڸ� �پ�Ѵ´�.  "not_of"�� �����϶�
		lastPos = str.find_first_not_of(delimiters, pos);
		// ���� �����ڰ� �ƴ� ���ڸ� ã�´�
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
	//wchar_t�� ���� ����
	wchar_t* pStr;

	//��Ƽ ����Ʈ ũ�� ��� ���� ��ȯ
	int strSize = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, NULL);

	//wchar_t �޸� �Ҵ�
	pStr = new WCHAR[strSize];

	//�� ��ȯ
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
	cout << "�����Ϸ��� escŰ �Է�" << endl;

	do
	{
		vector <string> tokens;
		cout << "������ �Է��ϼ���: ";
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
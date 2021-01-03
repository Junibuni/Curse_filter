#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

string database = "Curse_DB.txt";


vector <string> create_list(string* filename)
{
	vector <string> curse_list;
	ifstream inFile(*filename);
	
	while (!inFile.eof())
	{
		string str;
		getline(inFile, str);
		curse_list.push_back(str);
	}
	inFile.close();

	return curse_list;
}

void compare(vector <string> &list, string* word)
{
	string input = *word;
	char final[50] = {};
	int cnt = 0;

	for (int i = 0; i < (int)list.size(); i++)
	{	
		if (list[i] == input)
		{
			for (int j = 0; j < (int)input.size()/2 ; j++)
			{
				final[j] = '*';
			}
			cnt++;
			cout << final << endl;
			break;
		}
	}
	if (cnt == NULL) cout << input << endl;
}

int main()
{
	vector <string> curse_list = create_list(&database);
	string input;
	cout << "단어를 입력하세요: ";
	cin >> input;
	compare(curse_list, &input);

	return 0;
}
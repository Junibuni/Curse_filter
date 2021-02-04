#include "tree_node.h"
#include "tree_class.h"

int main()
{
	std::string word1 = "hello";
	std::string word2 = "world";
	std::string word3 = "my";
	std::string word4 = "name";

	Tree Curse_DB;
	Curse_DB.SetRoot(word1);
	Curse_DB.ParentInsertChild(word1);
	Curse_DB.ParentInsertChild(word2);
	Curse_DB.ParentInsertChild(word3);
	Curse_DB.ParentInsertChild(word4);

	std::cout << (*Curse_DB.GetCurrent()).GetData() << std::endl;
	std::cout << (*Curse_DB.GetCurrent()->GetChild()).GetData() << std::endl;
	std::cout << (*Curse_DB.GetCurrent()->GetChild()->GetSibling()).GetData() << std::endl;

	return 0;
}
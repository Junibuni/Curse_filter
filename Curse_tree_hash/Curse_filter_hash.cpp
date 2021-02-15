#include <stdio.h> 
#include <stdlib.h> 
#include <locale.h>
#include <iostream>

class hash
{
public:
	const int SIZE = 3; //테이블의 크기

	class node
	{
	public:
		int key;
		wchar_t* value;
		node* next;

		node(int key, wchar_t* value, node* next) :key(key), value(value), next(next) {};
	};

	class bucket
	{
	public:
		node* head = nullptr;
		int count = 0;
	};

	bucket* hashTable = new bucket[SIZE];

	node* createNode(int key, wchar_t* value)
	{
		node* newNode = new node{ key, value, nullptr };

		return newNode;
	}


	int hashFunction(wchar_t* value) 
	{
		int num = 0;
		int hash = 401;

		for (int i = 0; i < wcslen(value); ++i)
		{
			num += (int)value[i] * i;
		}
		hash = ((hash << 4) + num);

		return hash;
	}

	wchar_t* deleteEnter(wchar_t* input)
	{
		for (int i = 0; i < wcslen(input); ++i)
		{
			if (input[i] == '\n') { input[i] = 0; return input; }
		}
		return input;
	}

	void insert(wchar_t* value)
	{


		printf("\n--------넣기전---------\n");
		node* tmp = nullptr;
		tmp = hashTable[0].head;
		printf("Bucket[0] : ");
		while (tmp != nullptr)
		{

			printf("(key : %d, value : %S) ->", tmp->key, tmp->value);

			tmp = tmp->next;

		}
		printf("\n----------------------\n");


		value = deleteEnter(value);
		int key = hashFunction(value);
		int hashIndex = key%SIZE; 

		node* newNode = createNode(key, value);


		//값이 없는 경우
		if (hashTable[hashIndex].count == 0) {
			hashTable[hashIndex].head = newNode; //head를 newNode로 변경 후 cnt++
			hashTable[hashIndex].count = 1;
			printf("key = [%d], value = [%S], Index = [%d]\n", newNode->key, newNode->value, hashIndex);


			printf("\n------넣은후-------\n");
			node* tmp = nullptr;
			tmp = hashTable[0].head;
			printf("Bucket[0] : ");
			while (tmp != nullptr)
			{

				printf("(key : %d, value : %S) ->", tmp->key, tmp->value);

				tmp = tmp->next;

			}
			printf("\n----------------------\n");


			return;
		}

		newNode->next = hashTable[hashIndex].head;
		hashTable[hashIndex].head = newNode;
		hashTable[hashIndex].count++;
		printf("key = [%d], value = [%S], Index = [%d]\n", newNode->key, newNode->value, hashIndex);


		printf("\n------넣은후-------\n");
		tmp = hashTable[0].head;
		printf("Bucket[0] : ");
		while (tmp != nullptr)
		{

			printf("(key : %d, value : %S) ->", tmp->key, tmp->value);

			tmp = tmp->next;

		}
		printf("\n----------------------\n");



		return;
	}

	bool search(wchar_t* value) {
		value = deleteEnter(value);
		int key = hashFunction(value);
		int hashIndex = key % SIZE;

		node* node = hashTable[hashIndex].head;

		if (node == nullptr) 
		{ 
			printf("\n no key found\n");
			return false; 
		}
		while (node != nullptr) 
		{
			if (node->key == key) 
			{ 
				printf("\nkey found key = [%d], value = [%S]\n", node->key, node->value); 
				return true;
			}
			node = node->next; 

		}
		printf("\n no key found\n");
		return false; 

	}


	void display() 
	{
		node* tmp = nullptr; 
		for (int i = 0; i < SIZE; i++) 
		{ 
			tmp = hashTable[i].head; 
			printf("Bucket[%d] : ", i); 
			while (tmp != nullptr) 
			{

				printf("(key : %d, value : %S) ->", tmp->key, tmp->value);

				tmp = tmp->next;

			}
			printf("\n"); //다음 버켓으로
		}
		printf("\n");
		return;
	}

};

const char database[14] = "Curse_DB1.txt";
const char UTF8_type[13] = "rt,ccs=UTF-8";

int main() {
	wchar_t* a = L"최원준";
	hash hash;
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
				hash.insert(pline);

			}
			fclose(p_file);
		}
	}


	hash.search(a);
	hash.display();
}
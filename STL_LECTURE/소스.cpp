//------------------------------------------------------------
// 2023. 5.22, ��56                        (12�� 2��)
// 13�� 2�� 5. 29 ������ - ������ �⼮��ü
// 15�� 2�� 6. 12 ������ - �⸻ ����
//------------------------------------------------------------------
// �����̳ʵ��� ã�� �Ƿ��� �����Ѵ�. int õ�������� int ������ ã�´�
// vector
// set
// unordered_set
//-----------------------------------------------------------------
#include <iostream>
#include <random>
#include <array>
#include <vector>
#include <set>
#include <unordered_set>
#include "save.h"
#include "String.h"

using namespace std;
extern bool ����;

array<int, 1000'0000> numbers;
array<int, 10000> toFind;


template<>
struct hash<String>
{
	size_t operator()(const String& str) const
	{
		return hash<string>()(str.getString());
	}
};

//-------
int main()
//-------
{
	unordered_multiset<String, hash<String>> us{ "C++", "STL", "Container", "Iterator", "Algorithm"};

	auto p = us.find("Algorithm");
	cout << *p << endl;
}

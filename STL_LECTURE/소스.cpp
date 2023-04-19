//------------------------------------------------------------
// 2023. 4. 17 월56								(7주 2일)
// 4월 24일 월요일(8주 2일) - 중간시험
//------------------------------------------------------------
// Sequence container - list
//------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <list>
#include "save.h"
#include "String.h"

using namespace std;
extern bool 관찰;

// [문제] 파일 "리스트설명.txt"의 단어를 list<String>으로 읽어와라.
// 읽은 단어를 화면에 출려하라.

//-------
int main()
//-------
{
	ifstream in{ "리스트설명.txt" };

	if (!in)
	{
		cout << "파일 읽기 실패" << endl;
		return 0;
	}

	list<String> l;

	String s;
	while (in >> s)
	{
		l.push_back(s);
	}

	for (String& s : l)
	{
		cout << s << endl;
	}

	//save("소스.cpp");
}


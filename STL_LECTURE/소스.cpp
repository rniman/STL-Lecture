//------------------------------------------------------------
// 2023. 4. 17 ��56								(7�� 2��)
// 4�� 24�� ������(8�� 2��) - �߰�����
//------------------------------------------------------------
// Sequence container - list
//------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <list>
#include "save.h"
#include "String.h"

using namespace std;
extern bool ����;

// [����] ���� "����Ʈ����.txt"�� �ܾ list<String>���� �о�Ͷ�.
// ���� �ܾ ȭ�鿡 ����϶�.

//-------
int main()
//-------
{
	ifstream in{ "����Ʈ����.txt" };

	if (!in)
	{
		cout << "���� �б� ����" << endl;
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

	//save("�ҽ�.cpp");
}


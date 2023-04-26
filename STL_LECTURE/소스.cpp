//------------------------------------------------------------
// 2023. 4. 20 ��56								(8�� 1��)
// 4�� 24�� ������(8�� 2��) - �߰�����
//------------------------------------------------------------
// Sequence container - list
//------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include <numeric>
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
	//save("�ҽ�.cpp");

	ifstream in{ "����Ʈ����.txt" };

	if (!in)
	{
		cout << "���Ͽ��� ����" << endl;
	}

	//list<String> cont{����, ��}; -> ��� �����̳ʴ� ������ ���� ����
	//istream_iterator: �Է½�Ʈ���� ���ƴٴϴ� ���ͷ�����, >>�� ���� �Ǿ� �־���Ѵ�
	list<String> cont{ istream_iterator<String>{in}, {} };
	cout << "��� " << cont.size() << "���� �ܾ �о����ϴ�." << endl;

	// [����] ���̰� 7�� String�� "����7.txt"�� �����϶�
	// �� �ٿ� String �Ѱ��� �����϶�

	ofstream out{ "����7.txt" };

	//copy_if(cont.begin(), cont.end(), ostream_iterator<String>(out, '\n'), [](const String& s) {
	//	return s.size() == 7;
	//	});

	for (String& s : cont)
		if (s.size() == 7)
			out << s << endl;

	//cout << "���̰� 7�� �ܾ��� �� " << len7Num << endl;
}


//------------------------------------------------------------
// 2023. 5. 11 ��56								(11�� 1��)
//------------------------------------------------------------
// 
//------------------------------------------------------------
#include <iostream>
#include <set>
#include <fstream>
#include "save.h"
#include "String.h"

using namespace std;
extern bool ����;

//-------
int main()
//-------
{
	// "�ҽ�.cpp"�� s�� ����

	ifstream in{ "�ҽ�.cpp" };

	//set�� ���̱������� �����Ѵٰ� ġ�� ���̸��� �ϳ��� �����Ѵ�
	//set<String> s{ istream_iterator<String>{in},{} };
	multiset<String> s{ istream_iterator<String>{in},{} };

	for (const String& s : s)
		cout << s << endl;

	save("�ҽ�.cpp");
}

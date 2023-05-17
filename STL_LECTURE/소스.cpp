//------------------------------------------------------------
// 2023. 5.15, ��56                        (10�� 2��)
//------------------------------------------------------------------
// Associative �����̳� - set/map - ������ ������ equivalence�� ��
// 
// set�� ���ı����� �˷��ִ� ���
// 1. String�� ����� operator <�� �����Ѵ�. - ���̼�
// 2. Struct less�� Ư��ȭ�Ѵ� - ������
// 3. ȣ�Ⱑ�ɰ�ü�� ���� ���� - �����ڸ���
//------------------------------------------------------------------
#include <iostream>
#include <algorithm>
#include <set>   
#include <fstream>
#include <string>
#include "save.h"
#include "String.h"

using namespace std;
extern bool ����;

//-------
int main()
//-------
{

	//"�ҽ�.cpp"�� s�� ��ƺ��ƶ�.
	ifstream in("�̻��� ������ �ٸ���.txt");

	set<String> s{ istream_iterator<String>{in}, {} };

	//save("�ҽ�.cpp");

	// [����] ����ڰ� �Է��� �κдܾ ���Ե� �ܾ ��� ����϶�  

	while (true)
	{
		cout << "ã�� �ܾ �Է�:";
		String word;
		cin >> word;

		for (const String& str : s)
		{
			std::boyer
			if (search(str.begin(), str.end(), word.begin(), word.end()))
			{
				cout << str << ' ';
			}
		}
		cout << endl;
	}

}
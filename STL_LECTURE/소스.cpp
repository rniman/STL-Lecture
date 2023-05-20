//------------------------------------------------------------
// 2023. 5.18, ��56                        (12�� 1��)
//------------------------------------------------------------------
// Associative �����̳� - set/map - ������ ������ equivalence�� ��
// 
// map�� pair<key, value>�� ���ҷ� ���´�
//-----------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include "save.h"
#include "String.h"

using namespace std;
extern bool ����;

//-------
int main()
//-------
{
	// �Ҽ����� �� ���ڰ� ���� Ƚ���� ����϶�.

	ifstream in{ "�̻��� ������ �ٸ���.txt" };

	if (!in)
		return 0;

	map<char, int> cim;


	char c;
	while (in >> c)
	{
		++cim[c];
	}

	//cim['a'] -> �����迭

	// [����] ���� ���� ���� ������ ����϶�

	for (auto [����, ����] : cim)
	{
		cout << ���� << " - " << ���� << endl;
	}
	
	//save("�ҽ�.cpp");
}

//------------------------------------------------------------
// 2023. 4. 3 ��56								(5�� 2��)
//------------------------------------------------------------
// Sequence container - array
//------------------------------------------------------------
#include <iostream>
#include <array>
#include <fstream>
#include <algorithm>
#include "save.h"
#include "String.h"

using namespace std;

extern bool ����;

//-------
int main()
//-------
{	
	// [����] Ű���忡�� �Է��� int�� 10���� array�� ����Ͽ� �����϶�.
	// �հ踦 ȭ�鿡 ����϶�.
	array<int, 10> a;

	for (int& i : a)
	{
		cin >> i;
	}
	cin.clear();
	
	int sum = *a.begin();
	cout << *a.begin();
	for (auto i = a.begin() + 1; i!= a.end(); ++i)
	{
		cout << " + " << *i;
		sum += *i;
	}
	cout << " = " << sum << endl;

	save("�ҽ�.cpp");
}
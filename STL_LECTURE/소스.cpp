//------------------------------------------------------------
// 2023. 4. 13 ��56								(7�� 1��)
// 4�� 24�� ������(8�� 2��) - �߰�����
//------------------------------------------------------------
// Sequence container - vector
//------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include "save.h"
#include "String.h"

using namespace std;
extern bool ����;



//-------
int main()
//-------
{	
	vector<String> v{ "1", "2", "3", "4", "5" };
	
	// [����] v���� "3"�� �����϶�
	erase(v, "3");

	for (String& s : v)
	{
		cout << s << ' ';
	}
	cout << endl;

	//save("�ҽ�.cpp");
}
//------------------------------------------------------------
// 2023. 5. 8 ��56								(10�� 2��)
//------------------------------------------------------------
// �ݺ���(iterator) - �����͸� �߻�ȭ(=�Ϲ�ȭ) �� ���� �ݺ��ڴ�
// String�� ǥ�� �����̳ʷ� -> �ݺ��ڸ� ��������� 
//		begin(), end()
//		rbegin(), rend() -> �ݵ�� class�� �����ؾ߸� �Ѵ�
//		�ݺ��� adapter:�ݺ���ó�� �ൿ�ϴ� ��ü
//------------------------------------------------------------
#include <iostream>
#include <string>
#include <algorithm>
#include "save.h"
#include "String.h"

using namespace std;
extern bool ����;

//-------
int main()
//-------
{
	String s{ "The quick brown fox jumps over the lazy dog" };
	string str{ "The quick brown fox jumps over the lazy dog" };

	sort(s.begin(), s.end());
	sort(str.begin(), str.end());

	cout << s << endl;
	cout << str << endl;

	save("�ҽ�.cpp");
}

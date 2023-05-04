//------------------------------------------------------------
// 2023. 5. 4 ��56								(10�� 1��)
//------------------------------------------------------------
// �ݺ���(iterator)
// - �����͸� �߻�ȭ(=�Ϲ�ȭ) �� ���� �ݺ��ڴ�
// - Iterators are a generalization of pointers
// 6���� ����(category)�� ������.
// - �Է�/���/����(������)/�����(������)/�����＼��/��Ƽ��� �ݺ���
// ���ʵ���: *, ++, =
//------------------------------------------------------------
#include <iostream>
#include <vector>
#include <iterator>
#include "save.h"
#include "String.h"

using namespace std;
extern bool ����;

// [����] �Լ� f() �ݺ��ڸ� ���ڷ� �޾� � ������ �ݺ������� ȭ�� ����Ѵ�.
// 
// ���޵� ���ڰ� ���ϴ� Ÿ������ �Ǵ��ϴ� - type_traits 
template <class iter>
void f(iter)
{
	cout << typeid(iter).name() << endl;
}

//-------
int main()
//-------
{
	vector<int> v;
	ostream_iterator<char> p{ cout };
	
	f(123);
	f(v.begin());
	f(p);

	save("�ҽ�.cpp");
}

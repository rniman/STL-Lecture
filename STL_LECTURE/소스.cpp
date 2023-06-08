//------------------------------------------------------------
// 2023. 6. 5, ��56                        (14�� 2��)
// 6/6�� ���ε��� ������ - ������ �ǽ�
//------------------------------------------------------------------
// C++20 - 4 major change
// Concept - ���ø��� ���޵Ǵ� ����(�ڷ���)�� ���ϴ� �ǹ�(semantic)�� 
//			 �����ϴ��� ������ Ÿ�ӿ� �˻�(�ҽ��ڵ� Ȯ�� ��);
// Range - composable / less error-prone --> lazy evaluation(���� ��)
// - lightWeight object -> ex) string_view�� ���� ������ ������ ���� �淮ȭ�� ��ü
//  -- [begin, end)
//  -- [start, size)
//  -- [start, predicate)
//  -- [start..)  ���̾��� ������
//-----------------------------------------------------------------
#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include "save.h"
#include "String.h"

using namespace std;
extern bool ����;

bool isPrime2(int n) {
	for (int i = 2; i <= sqrt(n); i++) {//2~n�� �����ٱ���
		if (n % i == 0) {//i�� n�� ������ �Ҽ��� �ƴϹǷ� false return
			return false;
		}
	}
	//2 ~ n-1���� ����� ���ٸ� �Ҽ��̹Ƿ�, true return
	return true;
}

//-------
int main()
//-------
{
	save("�ҽ�.cpp");

	// �Ҽ�(prime num, 2 3 5 7 9 11 13)�� ������ ����϶�
	// 100�� �̻��� �� �߿��� 100���� �ڿ������� ����϶�

	for (int n : views::iota(2)
			   | views::drop_while([](int i) {return i < 100'0000; })
			   | views::filter(isPrime2)
			   | views::take(100)
			   | views::reverse
		)
		cout << n << ' ';
	cout << endl;

}

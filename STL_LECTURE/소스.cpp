//------------------------------------------------------------
// 2023. 3. 13 ��56						(2�� 2��)
//------------------------------------------------------------
// ���� ���� �ڷḦ ó���ϱ� - class
//------------------------------------------------------------
 
#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
#include "save.h"


// [����] "int õ��"���� int �� 1000���� binary ���� 4000����Ʈ�� �״�� ��ϵǾ��ִ�.
// �޸𸮷� �о�Ͷ�.
// ���� 100���� ���� ���� ��� �� ���ΰ� ����϶�.

//-------
int main()
//-------
{
	std::ifstream in{ "int õ��", std::ios::binary };

	if (!in) {
		exit(0);
	}

	std::array<int, 1'000> numbers;
	in.read((char*)&numbers, sizeof numbers);

	// ���� �ð����� �˰������� �ذ�

	int cnt = std::count_if(numbers.begin(), numbers.end(), [](int n) {return n < 100; });

	//int cnt{};

	//for (int num : numbers) {
	//	if (num < 100) {
	//		++cnt;
	//	}
	//}

	std::cout << "100���� ���� ���� - " << cnt << '\n';

	//save("�ҽ�.cpp");
}
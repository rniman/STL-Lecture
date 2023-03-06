//------------------------------------------------------------
// 2023. 3. 6 ��56						(1�� 2��)
//------------------------------------------------------------
// ���� ���� �ڷḦ ó���ϱ� int
//------------------------------------------------------------
 
#include <iostream>
#include <random>
#include <format>
#include "save.h"

std::default_random_engine dre;

//-------
int main()
//-------
{
	// ���� int 1000���� ȭ�鿡 �����Ͽ� ȭ�鿡 ����϶�

	std::uniform_int_distribution<int> uid{ 0, 99999'9999 };

	// [����] 1000�� �߿��� ���� ū ���� ����϶�.

	int max = -1;
	
	for (int i{}; i < 1000; ++i)
	{
		int rand_num = uid(dre);
		std::cout << std::format("{:10}", rand_num);
		if (max < rand_num)
			max = rand_num;
	}

	std::cout << '\n' << "max_num = " << max << '\n';

	save("�ҽ�.cpp");
}


//------------------------------------------------------------
// 2023. 3. 6 월56						(1주 2일)
//------------------------------------------------------------
// 많은 수의 자료를 처기하기 int
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
	// 랜덤 int 1000개를 화면에 생성하여 화면에 출력하라

	std::uniform_int_distribution<int> uid{ 0, 99999'9999 };

	// [문제] 1000개 중에서 가장 큰 수를 출력하라.

	int max = -1;
	
	for (int i{}; i < 1000; ++i)
	{
		int rand_num = uid(dre);
		std::cout << std::format("{:10}", rand_num);
		if (max < rand_num)
			max = rand_num;
	}

	std::cout << '\n' << "max_num = " << max << '\n';

	save("소스.cpp");
}


//------------------------------------------------------------
// 2023. 3. 13 월56						(2주 2일)
//------------------------------------------------------------
// 많은 수의 자료를 처리하기 - class
//------------------------------------------------------------
 
#include <iostream>
#include <fstream>
#include <array>
#include "save.h"


// [문제] "int 천개"에는 int 값 1000개가 binary 모드로 4000바이트가 그대로 기록되어있다.
// 메모리로 읽어와라.
// 값이 100보다 작은 것은 모두 몇 개인가 출력하라.

//-------
int main()
//-------
{
	std::ifstream in{ "int 천개", std::ios::binary };

	if (!in) {
		exit(0);
	}

	std::array<int, 1'000> numbers;
	in.read((char*)&numbers, sizeof numbers);

	// 다음 시간에는 알고리즘으로 해결

	int cnt{};

	for (int num : numbers) {
		if (num < 100) {
			++cnt;
		}
	}

	std::cout << "100보다 작은 숫자 - " << cnt << '\n';

	save("소스.cpp");
}
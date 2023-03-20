//------------------------------------------------------------
// 2023. 3. 20 월56						(3주 2일)
// 4. 3 예비군 훈련 - 수업 강의녹화 영상을 e-class에 제공
//------------------------------------------------------------
// 정렬(sort) - callable type
//------------------------------------------------------------
#include <iostream>
#include <array>
#include <random>
#include <format>
#include <algorithm>
#include <ranges>		// C++ 20
#include "save.h"

// [문제] int 100만개를 만들고 random 값으로 채워라
// 오름차순으로 정렬하라
// 값을 출력하라


std::array<int, 1'000'000> numbers;
std::default_random_engine dre;
std::uniform_int_distribution uid{ 1, 1'000'000 };

//bool 어떻게( int a, int b)
//{
//	return a > b;
//}
class Dog {
public:
	bool operator()(int a, int b)
	{
		return a > b;
	}
};

//-------
int main()
//-------
{	
	for (int& number : numbers)
	{
		number = uid(dre);
	}

	//오름차순 정렬
	// 3번째 인자가 디폴트 인자 오름차순 정렬 -> 정렬 방법은 sort에게 직접 알려줘야 한다.(함수를 인자로 전다)
	// 3번째 인자의 타입은 무한개이다. (부를 수 있는 타입, callable type)
	std::sort(numbers.begin(), numbers.end(), Dog());	// O(nlog(n))
	//std::ranges::sort(numbers); //C++ 20이상

	// 뒤에서 100개만 출력
	for (int number : numbers | 				  // -> for(auto i = numbers.begin(); numbers.end(); ++i)로 번역 ( syntatic sugar )
			std::views::drop(numbers.size()-100)) // | filter를 통해서 
	{
		std::cout << std::format("{:8}", number);
	}

	save("소스.cpp");
}


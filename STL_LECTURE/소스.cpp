//------------------------------------------------------------
// 2023. 3. 16 목56						(3주 1일)
//------------------------------------------------------------
// 더 많은 자료 처리하기 - new를 사용한 메모리 동적할당 
//------------------------------------------------------------
#include <iostream>
#include <memory>
#include <chrono>
#include "save.h"

// [문제] 스마트 포인터의 동작을 관찰할 수 있도록 class Dog를 사용

class Dog
{
public:
	Dog();
	~Dog();

private:
	char c[100'000'000];
};

Dog::Dog()
{
	std::cout << "Dog 생성" << '\n';
}

Dog::~Dog()
{
	std::cout << "Dog 소멸" << '\n';
}

//-------
int main()
//-------
{
	save("소스.cpp");
	int cnt{};
	while (true)
	{
		std::cout << ++cnt << '\n';
		std::unique_ptr<Dog[]> dog{ new Dog[10] };    // sizeof(Dog) * 10 = 1GB

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}
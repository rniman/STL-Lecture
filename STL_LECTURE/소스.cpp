//------------------------------------------------------------
// 2023. 3. 16 ��56						(3�� 1��)
//------------------------------------------------------------
// �� ���� �ڷ� ó���ϱ� - new�� ����� �޸� �����Ҵ� 
//------------------------------------------------------------
#include <iostream>
#include <memory>
#include <chrono>
#include "save.h"

// [����] ����Ʈ �������� ������ ������ �� �ֵ��� class Dog�� ���

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
	std::cout << "Dog ����" << '\n';
}

Dog::~Dog()
{
	std::cout << "Dog �Ҹ�" << '\n';
}

//-------
int main()
//-------
{
	save("�ҽ�.cpp");
	int cnt{};
	while (true)
	{
		std::cout << ++cnt << '\n';
		std::unique_ptr<Dog[]> dog{ new Dog[10] };    // sizeof(Dog) * 10 = 1GB

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}
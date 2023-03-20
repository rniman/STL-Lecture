//------------------------------------------------------------
// 2023. 3. 20 ��56						(3�� 2��)
// 4. 3 ���� �Ʒ� - ���� ���ǳ�ȭ ������ e-class�� ����
//------------------------------------------------------------
// ����(sort) - callable type
//------------------------------------------------------------
#include <iostream>
#include <array>
#include <random>
#include <format>
#include <algorithm>
#include <ranges>		// C++ 20
#include "save.h"

// [����] int 100������ ����� random ������ ä����
// ������������ �����϶�
// ���� ����϶�


std::array<int, 1'000'000> numbers;
std::default_random_engine dre;
std::uniform_int_distribution uid{ 1, 1'000'000 };

//bool ���( int a, int b)
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

	//�������� ����
	// 3��° ���ڰ� ����Ʈ ���� �������� ���� -> ���� ����� sort���� ���� �˷���� �Ѵ�.(�Լ��� ���ڷ� ����)
	// 3��° ������ Ÿ���� ���Ѱ��̴�. (�θ� �� �ִ� Ÿ��, callable type)
	std::sort(numbers.begin(), numbers.end(), Dog());	// O(nlog(n))
	//std::ranges::sort(numbers); //C++ 20�̻�

	// �ڿ��� 100���� ���
	for (int number : numbers | 				  // -> for(auto i = numbers.begin(); numbers.end(); ++i)�� ���� ( syntatic sugar )
			std::views::drop(numbers.size()-100)) // | filter�� ���ؼ� 
	{
		std::cout << std::format("{:8}", number);
	}

	save("�ҽ�.cpp");
}


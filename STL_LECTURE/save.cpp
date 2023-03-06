//------------------------------------------------------------
// save.cpp ���б� ���Ǹ� �����ϴ� �Լ�
//------------------------------------------------------------

#include <fstream>
#include <vector>
#include <chrono>
#include "save.h"

void save(const std::string& fileName)
{
	// fileName�� �б� ���� ����
	std::ifstream in{ fileName };

	//char c;
	//in >> c; in��ü�� ������ �����ε��� �����Ǿ�����
	/*while (in >> c)
		std::cout << c;*/

		// ������ ������ ���ٿ� ���� ���� ����
	std::ofstream out{ "2023 1�б� STL ��56 ��56 ��������.txt", std::ios::app }; //���ٿ� ������

	// ������ �ð��� ���Ͽ� ����Ѵ�.
	// epoch: �ð��� ���
	auto now = std::chrono::system_clock::now();			// time_point�� ��´�
	//std::cout << now << '\n'; -> ǥ�� �ð� ���
	auto time = std::chrono::system_clock::to_time_t(now);	// UTC �ð����� ��ȯ	
	//std::cout << time << '\n'; ->  ƽ���� ���
	auto lt = localtime(&time);								// ���� �ð����� ��ȯ

	auto old = out.imbue(std::locale("ko_KR"));				// �ѱ����� ����

	// �ð� ���
	out << '\n' << '\n';
	out << "==================================================" << '\n';
	out << fileName << " " << std::put_time(lt, ", ����ð�: %x %A %X") << '\n';
	out.imbue(std::locale(old));							// ���� �������� �ǵ�����.
	out << "==================================================" << '\n';

	// fileName�� �о� ���� ���Ͽ� ���ٿ� ����. (STL �ڷᱸ���� �˰���)
	//std::vector<char> v{ std::istream_iterator<char>{in} , {} }; -> white space�� ������
	std::vector<char> v{ std::istreambuf_iterator <char>{in} , {} };
	std::copy(v.begin(), v.end(), std::ostream_iterator<char>{out});

}

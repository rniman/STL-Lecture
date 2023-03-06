//------------------------------------------------------------
// save.cpp 한학기 강의를 저장하는 함수
//------------------------------------------------------------

#include <fstream>
#include <vector>
#include <chrono>
#include "save.h"

void save(const std::string& fileName)
{
	// fileName을 읽기 모드로 연다
	std::ifstream in{ fileName };

	//char c;
	//in >> c; in객체에 연산자 오버로딩이 구현되어있음
	/*while (in >> c)
		std::cout << c;*/

		// 저장할 파일을 덧붙여 쓰기 모드로 연다
	std::ofstream out{ "2023 1학기 STL 월56 목56 강의저장.txt", std::ios::app }; //덧붙여 쓰기모드

	// 저장한 시간을 파일에 기록한다.
	// epoch: 시간의 기원
	auto now = std::chrono::system_clock::now();			// time_point를 얻는다
	//std::cout << now << '\n'; -> 표준 시간 출력
	auto time = std::chrono::system_clock::to_time_t(now);	// UTC 시간으로 변환	
	//std::cout << time << '\n'; ->  틱수를 출력
	auto lt = localtime(&time);								// 현지 시간으로 변환

	auto old = out.imbue(std::locale("ko_KR"));				// 한국으로 변경

	// 시간 출력
	out << '\n' << '\n';
	out << "==================================================" << '\n';
	out << fileName << " " << std::put_time(lt, ", 저장시간: %x %A %X") << '\n';
	out.imbue(std::locale(old));							// 원래 형식으로 되돌린다.
	out << "==================================================" << '\n';

	// fileName을 읽어 저장 파일에 덧붙여 쓴다. (STL 자료구조와 알고리즘)
	//std::vector<char> v{ std::istream_iterator<char>{in} , {} }; -> white space를 무시함
	std::vector<char> v{ std::istreambuf_iterator <char>{in} , {} };
	std::copy(v.begin(), v.end(), std::ostream_iterator<char>{out});

}

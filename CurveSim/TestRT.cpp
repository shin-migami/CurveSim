#include <iostream>
#include "ReserveTable.h"

//Compile only if Testing class ReserveTable
#ifdef TEST_RESERVETABLE_H

int main()
{
	ReserveTable tab1(3, 8);
	tab1.add_stage(std::string("10000101"), 0);
	tab1.add_stage(std::string("01010000"), 1);
	tab1.add_stage(std::string("00101010"), 2);

	std::cout << tab1.to_string();
	std::cout << tab1.get_ICV() << std::endl;
	for (const auto latency : tab1.get_forbidden())
		std::cout << latency << std::endl;
	std::cout << std::endl;
	for (const auto latency : tab1.get_permissible())
		std::cout << latency << std::endl;
	return 0;
}
#endif

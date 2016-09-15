#include <iostream>
#include "StateDiagram.h"

//Compile only in testing Mode
#ifdef TEST_STATE_DIAG_H
int main()
{
	ReserveTable tab1(3, 8);
	tab1.add_stage(std::string("10000101"), 0);
	tab1.add_stage(std::string("01010000"), 1);
	tab1.add_stage(std::string("00101010"), 2);
	StateDiagram sd(tab1);

	for (auto c : sd.simple_cycles())
		std::cout << c.to_string() << std::endl;

	for (auto c : sd.greedy_cycles())
		std::cout << c.to_string() << std::endl;

	std::cout << sd.to_string() << std::endl;
	std::cout << sd.MAL() << std::endl;
	std::cout << sd.get_throughput() << std::endl;
	return 0;
}
#endif
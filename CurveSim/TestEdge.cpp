#include <iostream>
#include "Edge.h"

//Compile only in testing Mode
#ifdef TEST_EDGE_H
int main()
{
	std::bitset<STATES> to("1010");
	std::bitset<STATES> from("1111");
	Edge testEdge(from, 1, to, 2, 5);
	std::cout << testEdge.from()       << std::endl;
	std::cout << testEdge.to()         << std::endl;
	std::cout << testEdge.from_state() << std::endl;
	std::cout << testEdge.to_state()   << std::endl;
	std::cout << testEdge.to_string(4)  << std::endl;
	return 0;
}
#endif

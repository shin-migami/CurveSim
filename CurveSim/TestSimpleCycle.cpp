#include <algorithm>
#include <iostream>
#include <queue>
#include "SimpleCycle.h"

//Author      : Suvojit Manna
//Application : CurveSim

#ifdef TEST_CYCLE_H
int main()
{
	std::cout.setf(std::ios::fixed);
	SimpleCycle cycle1;
	std::bitset<STATES> to, from;
	to   = std::bitset<STATES>("1010");
	from = std::bitset<STATES>("1111");
	Edge testEdge(from, 1, to, 2, 5);
	cycle1.add_edge(testEdge);
	to   = std::bitset<STATES>("1111");
	from = std::bitset<STATES>("1010");
	testEdge = Edge(from, 2, to, 1, 3);
	cycle1.add_edge(testEdge);

	std::cout << cycle1.length()      << std::endl;
	std::cout << cycle1.avg_latency() << std::endl;
	std::cout << cycle1.to_string()   << std::endl;

	SimpleCycle cycle2;
	to   = std::bitset<STATES>("1011");
	from = std::bitset<STATES>("1011");
	testEdge = Edge(from, 1, to, 1, 5);
	cycle2.add_edge(testEdge);

	std::cout << cycle2.length()      << std::endl;
	std::cout << cycle2.avg_latency() << std::endl;
	std::cout << cycle2.to_string()   << std::endl;

	SimpleCycle cycle4;
	to = std::bitset<STATES>("1111");
	from = std::bitset<STATES>("1010");
	testEdge = Edge(from, 1, to, 3, 1);
	cycle4.add_edge(testEdge);
	to = std::bitset<STATES>("1010");
	from = std::bitset<STATES>("1111");
	testEdge = Edge(from, 3, to, 1, 5);
	cycle4.add_edge(testEdge);

	SimpleCycle cycle3;
	to   = std::bitset<STATES>("1011");
	from = std::bitset<STATES>("1111");
	testEdge = Edge(from, 1, to, 2, 3);
	try
	{
		std::cout << cycle3.to_string() << std::endl;
	}
	catch (std::domain_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << cycle3.avg_latency() << std::endl;
	}
	catch (std::domain_error &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::vector<SimpleCycle> pq2{ cycle1, cycle2, cycle4 };
	std::make_heap(pq2.begin(), pq2.end(), SimpleCycle());
	std::cout << pq2.front().to_string() << std::endl;

	std::priority_queue<SimpleCycle,
						std::vector<SimpleCycle>,
						SimpleCycle> pq;
	pq.push(cycle1);
	pq.push(cycle2);
	pq.push(cycle4);
	std::cout << pq.top().to_string() << std::endl;
	return 0;
}
#endif
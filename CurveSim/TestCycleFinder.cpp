#include <iostream>
#include "CycleFinder.h"

//Compile only in Testing Mode
#ifdef TEST_CYCLE_FINDER_H
#define CASE_1
int main()
{
	Graph G;
	std::bitset<STATES> v;

	//Generate A graph : TestCase 1
#ifdef CASE_1
	v = std::bitset<STATES>("1010");
	G.add_vertex(v);
	G.add_edge(v, v, 5);
	v = std::bitset<STATES>("1011");
	G.add_vertex(v);
	G.add_edge(v, std::bitset<STATES>("1010"), 5);
	G.add_edge(std::bitset<STATES>("1010"), v, 3);
	G.add_edge(v, v, 3);
	v = std::bitset<STATES>("1111");
	G.add_vertex(v);
	G.add_edge(std::bitset<STATES>("1010"), v, 1);
	G.add_edge(v, std::bitset<STATES>("1010"), 5);
	v = std::bitset<STATES>("1011");
	G.add_vertex(v);
#endif

	//Generate A graph : TestCase 2
#ifdef CASE_2
	v = std::bitset<STATES>("1011010");
	G.add_vertex(v);
	G.add_edge(v, v, 8);
	v = std::bitset<STATES>("1011011");
	G.add_vertex(v);
	G.add_edge(std::bitset<STATES>("1011010"), v, 3);
	G.add_edge(std::bitset<STATES>("1011010"), v, 6);
	G.add_edge(v, std::bitset<STATES>("1011010"), 8);
	G.add_edge(v, v, 3);
	G.add_edge(v, v, 6);
	v = std::bitset<STATES>("1111111");
	G.add_vertex(v);
	G.add_edge(std::bitset<STATES>("1011010"), v, 1);
	G.add_edge(v, std::bitset<STATES>("1011010"), 8);
#endif

	//Find All Cycles
	CycleFinder allCycle(G);
	std::cout << allCycle.simple_cycle_count() << std::endl;
	std::cout << allCycle.greedy_cycle_count() << std::endl;

	for (auto c : allCycle.simple_cycles())
		std::cout << c.to_string() << std::endl;

	for (auto c : allCycle.greedy_cycles())
		std::cout << c.to_string() << std::endl;
	return 0;
}
#endif
#include <iostream>
#include "Graph.h"

//Compile only in testing Mode
#ifdef TEST_GRAPH_H
int main()
{
	Graph G;
	std::bitset<STATES> v;

	//Generate A graph
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
	G.add_edge(v, std::bitset<STATES>("1010"), 1);
	v = std::bitset<STATES>("1011");
	G.add_vertex(v);

	//Test Features
	std::cout << "States  : " << G.v_count() << std::endl;
	std::cout << "Changes : " << G.e_count() << std::endl;

	for (auto edge : G.adj(std::bitset<STATES>("1011")))
		std::cout << edge.to_string() << std::endl;

	std::cout << G.in_degree (std::bitset<STATES>("1011")) << std::endl;
	std::cout << G.out_degree(std::bitset<STATES>("1011")) << std::endl;

	std::cout << G.to_string() << std::endl;
	return 0;
}
#endif
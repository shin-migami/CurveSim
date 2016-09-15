#ifndef CYCLE_FINDER_H
#define CYCLE_FINDER_H
//#define TEST_CYCLE_FINDER_H

//Author      : Suvojit Manna
//Application : CurveSim
//Header for Cycle Finder API
//Finds and enumerates over all simple and Greedy cycle
//Use DFS to start looking for cycle from each vertex
//If cycle is found insert in a List. 
//For each vertex choose the edge with lowest latency
//to find the Greedy Cycle

#include <algorithm>
#include <vector>
#include <queue>
#include "Edge.h"
#include "Graph.h"
#include "SimpleCycle.h"

class CycleFinder
{
private:
	std::vector<SimpleCycle> simple;	//store simple cycles
	std::vector<SimpleCycle> greedy;	//store greedy cycles
	std::deque<bool>         onStack;	//maintain stack list
	std::deque<bool>         ignore;	//maintain ignore list
	std::vector<size_t>      stack;		//stack of vertex path

	//Use Depth First Search to enumerate over all cycle
	//from a given vertex v
	//Complexity : O(|V|*|C|*(|E| + 1))
	//@param  G Graph  State Diagram as a Graph
	//@param  v pair   Starting vertex map of v
	//@return None
	void dfs(Graph& G, 
			 std::pair<std::bitset<STATES>, size_t> vMap,
			 std::vector<SimpleCycle>& fromV,
			 SimpleCycle& c);

public:
	//Finds cycle in Weighted Directed Graph
	CycleFinder(Graph& G);

	//Return Simple Cycle Count
	//@param  None
	//@return size_t  No of Simple Cycles
	size_t simple_cycle_count(void);

	//Return Greedy Cycle Count
	//@param  None
	//@return size_t  No of Greedy Cycle
	size_t greedy_cycle_count(void);

	//Return list of Simple Cycles
	//@param  None
	//@return vector<SimpleCycle>  All Simple Cycles
	const std::vector<SimpleCycle>& simple_cycles(void);

	//Return list of Greedy Cycles
	//@param  None
	//@return vector<SimpleCycle>  All Greedy Cycles
	const std::vector<SimpleCycle>& greedy_cycles(void);

	//Return Greedy Cycle with minimum Latency
	//@param  None
	//Return SimpleCycle the Greedy cycle leading to MAL
	SimpleCycle& min_greedy(void);
};

#endif
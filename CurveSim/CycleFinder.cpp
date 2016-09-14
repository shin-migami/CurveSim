#include "CycleFinder.h"

//Author      : Suvojit Manna
//Application : CurveSim

//Instantiate and find all Cycles
CycleFinder::CycleFinder(Graph& G)
{
	onStack.assign(G.v_count(), false);
	ignore.assign(G.v_count(),  false);
	std::vector<SimpleCycle> fromV;
	for (auto vMap : G.vertex())
	{
		SimpleCycle c;
		dfs(G, vMap, fromV, c);
		if (!fromV.empty())
		{
			std::make_heap(fromV.begin(), fromV.end(), SimpleCycle());
			greedy.push_back(fromV.front());
			simple.insert(simple.end(), fromV.begin(), fromV.end());
			fromV.clear();
		}
		ignore[vMap.second] = true;
	}
	//Lowest latency Cycle is moved to the top
	std::make_heap(greedy.begin(), greedy.end(), SimpleCycle());
}

//Find and Enumerate over all cycles
void CycleFinder::dfs(Graph& G,
					  std::pair<std::bitset<STATES>, size_t> vMap,
					  std::vector<SimpleCycle>& fromV,
					  SimpleCycle& c)
{
	size_t v = vMap.second;
	stack.push_back(v);
	onStack[v] = true;
	for (auto edge : G.adj(vMap.first))
	{
		size_t w = edge.to();
		if (!onStack[w] && !ignore[w])
		{
			c.add_edge(edge);
			std::pair<std::bitset<STATES>, size_t> e(edge.to_state(),
													 edge.to());
			dfs(G, e, fromV, c);
		}
		else if (stack[0] == w && !ignore[w])
		{
			//Cycle is found for either self loop
			//or when tail of path is equal to head
			c.add_edge(edge);
			fromV.push_back(c);
			c = SimpleCycle();
		}
	}
	stack.pop_back();
	onStack[v] = false;
}

//Return Simple Cycle Count
size_t CycleFinder::simple_cycle_count(void)
{
	return simple.size();
}

//Return simple Cycle Count
size_t CycleFinder::greedy_cycle_count(void)
{
	return greedy.size();
}

//Return list of Simple Cycles
const std::vector<SimpleCycle>& CycleFinder::simple_cycles(void)
{
	return simple;
}

//Return list of Greedy Cycles
const std::vector<SimpleCycle>& CycleFinder::greedy_cycles(void)
{
	return greedy;
}
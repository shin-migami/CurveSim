#include "StateDiagram.h"

//Author      : Suvojit Manna
//Application : CurveSim

//Initialize StateDiagram with a Reservation Table
StateDiagram::StateDiagram(ReserveTable& resrcMat) : latencyCycle(stateDiag)
{
	stateLen = resrcMat.timeslot_count() - 1;
	std::deque<std::bitset<STATES>> stateQ;
	std::bitset<STATES> icv(resrcMat.get_ICV());
	icv >>= 1;
	stateDiag.add_vertex(icv);
	stateQ.push_back(icv);
	while (!stateQ.empty())
	{
		std::bitset<STATES> state = stateQ.front();
		for (size_t p = 0; p < resrcMat.timeslot_count(); ++p)
		{
			if (!state.test(p))
			{
				std::bitset<STATES> newState = (state >> (p + 1)) | icv;
				if (!stateDiag.has_vertex(newState))
				{
					stateQ.push_back(newState);
					stateDiag.add_vertex(newState);
				}
				stateDiag.add_edge(state, newState, p + 1);
			}
		}
		stateQ.pop_front();
	}
	latencyCycle  = CycleFinder(stateDiag);
	minAvgLatency = latencyCycle.min_greedy().avg_latency();
	throughput    = 1 / minAvgLatency;
}

//Return list of Simple Cycles
const std::vector<SimpleCycle>& StateDiagram::simple_cycles(void)
{
	return latencyCycle.simple_cycles();
}

//Return list of Greedy Cycles
const std::vector<SimpleCycle>& StateDiagram::greedy_cycles(void)
{
	return latencyCycle.greedy_cycles();
}

//Return MAL
float StateDiagram::MAL(void)
{
	return minAvgLatency;
}

//Return Throughtput of the Pipeline
float StateDiagram::get_throughput(void)
{
	return throughput;
}

//Return State Diagram as String
const std::string StateDiagram::to_string(void)
{
	return stateDiag.to_string(stateLen);
}
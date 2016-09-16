#include "StateDiagram.h"

//Author      : Suvojit Manna
//Application : CurveSim

//Initialize StateDiagram with a Reservation Table
StateDiagram::StateDiagram(ReserveTable& resrcMat) : latencyCycle(stateDiag)
{
	//Get Maximum ICV Length
	stateLen = resrcMat.get_ICV().length();
	std::deque<std::bitset<STATES>> stateQ;
	std::bitset<STATES> icv(resrcMat.get_ICV());
	//Add ICV to Graph as vertex
	stateDiag.add_vertex(icv);
	//Push ICV to state queue
	stateQ.push_back(icv);
	//Repeat While all possible states are checked
	while (!stateQ.empty())
	{
		std::bitset<STATES> state = stateQ.front();
		//Check for all possible latency config
		for (size_t p = 0; p <= stateLen; ++p)
		{
			//If latency is prmissible
			if (!state.test(p))
			{
				//Calculte the new State  by ORing with ICV
				std::bitset<STATES> newState = (state >> (p + 1)) | icv;
				//Eureka !! We dicovered a new State
				if (!stateDiag.has_vertex(newState))
				{
					//Add it to the records
					stateQ.push_back(newState);
					stateDiag.add_vertex(newState);
				}
				//Make latency edge Connection
				stateDiag.add_edge(state, newState, p + 1);
			}
		}
		//Done with checking the state
		stateQ.pop_front();
	}
	//Calculate all latency Cycle
	latencyCycle  = CycleFinder(stateDiag);
	//Calcucle Min Average Latency
	minAvgLatency = latencyCycle.min_greedy().avg_latency();
	//Calcuclte Throughput as (1 / MAL)
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
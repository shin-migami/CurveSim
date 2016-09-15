#ifndef STATE_DIAG_H
#define STATE_DIAG_H
//#define TEST_STATE_DIAG_H

//Author      : Suvojit Manna
//Application : CurveSim
//Header for state diagram API
//Constructs a state diagram out of a Reservation Table
//And intiate the Cycle Finder also calculate the
//Minimum Average Latency and Throughput

#include <deque>
#include "CycleFinder.h"
#include "Graph.h"
#include "ReserveTable.h"

class StateDiagram
{
private:
	Graph       stateDiag;
	CycleFinder latencyCycle;
	float       minAvgLatency;
	float       throughput;
	size_t      stateLen;

public:
	//Initialize StateDiagram with a Reservation Table
	//Calculate other state Reachable from ICV
	//And store as a graph also calculte all simple and
	//Greedy cycles, MAL and Throughput
	//@param  resrcMat  Resource Matrix ie the Reservation Table
	StateDiagram(ReserveTable& resrcMat);

	//Return list of Simple Cycles
	//@param  None
	//@return vector<SimpleCycle>  All Simple Cycles
	const std::vector<SimpleCycle>& simple_cycles(void);

	//Return list of Greedy Cycles
	//@param  None
	//@return vector<SimpleCycle>  All Greedy Cycles
	const std::vector<SimpleCycle>& greedy_cycles(void);

	//Return MAL
	//@param  None
	//@return float  Return Minimum Average Latency
	float MAL(void);

	//Return Throughtput of the Pipeline
	//@param  None
	//return float  Retun throughput
	float get_throughput(void);

	//Return State Diagram as String
	//@param  None
	//@return string  String representation of the Graph
	const std::string to_string(void);
};

#endif
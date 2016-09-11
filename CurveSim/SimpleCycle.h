#ifndef CYCLE_H
#define CYCLE_H

//Author      : Suvojit Manna
//Application : CurveSim
//Header for Simple Cycle API
//Abstraction for vectors of Edges
//Supports redundancy check for Cyclec. Each state may occur
//once in each Cycle. Start state and end states must be same

#include <exception>
#include <cmath>
#include <vector>
#include "Edge.h"

class SimpleCycle
{
private:
	//Store as a Vector of Edges
	std::vector<Edge> cycle;
	bool              loaded;
	double            latency;
public:
	//Instansiate objects
	SimpleCycle();

	//Return true if cycle is formed
	//@param  None
	//@return bool  True if there is a cycle
	bool is_cycle(void);

	//Add new Edge to cycle
	//Stops when intial and final vertex are same
	//@param  e Edge  Next Edge
	//@return None
	void add_edge(Edge& e);

	//Return length of Cycle
	//@param  None
	//@return length  Length of Cycle
	size_t length(void);

	//Return the Cycle as a String
	//@param  None
	//@return string  String representation of Cycle
	//@throws domain_error  When cycle ids not closed
	std::string to_string(void);

	//Return average latency of cycle
	//@param  None
	//@return avg_latency double  Average Latency of Cycle
	double avg_latency(void);

	//Comparator functor to comapre average latency
	//Compares two objects of the class and return
	//true if left's latency is greater than right's
	//@param  that SimpleCycle  obj to be compared
	//@return bool True if this greater than that
	const bool operator()(SimpleCycle& L,SimpleCycle& R);
};

#endif
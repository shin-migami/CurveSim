#ifndef EDGE_H
#define EDGE_H

//Author      : Suvojit Manna
//Application : CurveSim
//Header for Edge API. Eache edge stores its source state,
//its destination state as well as its corresponding latency
//It also store ID for the each stage to navigate the graph
//Commarator is provided by latency to comapre two Edge objects
//@param  to      bitset state of origin
//@param  from    bitset destination state
//@param  toID    size_t origin state ID
//@param  fromID  size_t dest state ID
//@param  latency size_t latency of change

#include <bitset>
#include <string>
#include "ReserveTable.h"

class Edge
{
private:
	std::bitset<STATES> toState,		//state of origin
						fromState;		//destination state
	size_t              toID,			//origin state ID
						fromID;			//dest state ID
	size_t              latency;		//latency of change

public:
	//Constructor to create object of Edge type
	//@param  to      bitset state of origin
	//@param  from    bitset destination state
	//@param  toID    size_t origin state ID
	//@param  fromID  size_t dest state ID
	//@param  latency size_t latency of change
	Edge(const std::bitset<STATES> &fromState,
		 const size_t              fromID, 
		 const std::bitset<STATES> &toState,
		 const size_t              toID,
		 const size_t              latency);

	//Retuns the tail state
	//@param  None
	//@return bitset destination state
	const std::bitset<STATES>& to_state  (void);

	//Returns head state
	//@param  None
	//@return bitset source state
	const std::bitset<STATES>& from_state(void);

	//Returns tail state ID
	//@param  None
	//@return size_t destination state ID
	const size_t to  (void);

	//Returns head state ID
	//@param  None
	//@return size_t source state ID
	const size_t from(void);

	//Return latency
	//@param  None
	//@return size_t latency of change
	const size_t get_latency(void);

	//Return the Edge as a string
	//@param  None
	//@return string string representation of the edge
	std::string to_string(void);
};

#endif
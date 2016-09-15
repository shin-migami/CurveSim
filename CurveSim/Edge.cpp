#include "Edge.h"

//Author      : Suvojit Manna
//Application : CurveSim

Edge::Edge( const std::bitset<STATES> &fromState,
			const size_t              fromID,
			const std::bitset<STATES> &toState,
			const size_t              toID,
			const size_t              latency )
{
	this->toState   = toState;
	this->fromState = fromState;
	this->toID      = toID;
	this->fromID    = fromID;
	this->latency   = latency;
}

//Return the tail state
const std::bitset<STATES>& Edge::to_state(void)    { return toState;   }

//Return head state
const std::bitset<STATES>& Edge::from_state(void)  { return fromState; }

//Return tail state ID
const size_t Edge::to(void)    { return toID; }

//Return head state ID
const size_t Edge::from(void)  { return fromID; }

//Return latency
const size_t Edge::get_latency(void)  { return latency; }

//Return the Edge as a string
std::string Edge::to_string(size_t stateLen)
{
	std::string edgeStr;
	//Build the string
	edgeStr = fromState.to_string().substr(STATES - stateLen)
		    + " -("
		    + std::to_string(latency)
		    + ")-> "
		    + toState.to_string().substr(STATES - stateLen);
	return edgeStr;
	//TODO : Format string
}
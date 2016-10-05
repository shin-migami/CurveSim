#include "SimpleCycle.h"

//Author      : Suvojit Manna
//Application : CurveSim

//Define Constructor
SimpleCycle::SimpleCycle()
{
	loaded = false;
	latency = 0.0f;
}

//Return true if cycle is formed
bool SimpleCycle::is_cycle(void)  {	return loaded; }

//Add Edge to Cycle
//Check if Tail and Head of Cycle are Same
//If True then lock the cycle
void SimpleCycle::add_edge(const Edge& e)
{
	//If locked return
	if (loaded)  return;

	//Else add the New Edge object
	cycle.push_back(e);
	latency += e.get_latency();

	//Check if a simple cycle is formed
	if (cycle[0].from() == e.to())
	{
		loaded = true;
		latency /= cycle.size();
	}
}

//Return length of cycle
size_t SimpleCycle::length(void)
{
	return cycle.size();
}

//Return the Cycle as a String
std::string SimpleCycle::to_string(void)
{
	//Return Error if Cycle is not formed
	//if (!loaded)  throw std::domain_error("Cycle not closed !");

	std::string cycleStr("(");
	for (auto &edge : cycle)
		cycleStr += std::to_string(edge.get_latency()) + ", ";
	cycleStr.pop_back();	//remove space
	cycleStr.pop_back();	//remove comma
	cycleStr += ")";
	return cycleStr;
}

//Return average latency of cycle
float SimpleCycle::avg_latency(void) const
{
	//Return NULL String if Cycle is not formed
	//if (!loaded)  throw std::domain_error("Cycle not closed !");
	return latency;
}

//Comparator functor for Simple Cycle Class
const bool SimpleCycle::operator()(const SimpleCycle& L, const SimpleCycle& R) const
{
	float a = L.avg_latency();
	float b = R.avg_latency();
	//Return true if a > b
	return a - b > 0;
}

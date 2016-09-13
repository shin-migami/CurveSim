#include "Graph.h"

//Author      : Suvojit Manna
//Application : CurveSim

//Initialize Graph as a Null graph
Graph::Graph()
{
	this->V = 0;
	this->E = 0;
}

//Initiate with the number of Vertex
Graph::Graph(const size_t n)
{
	this->V = n;
	this->E = 0;
	//Set size of adjadency list to no of Vertex
	G.resize(n);
}

//Adds a new vertex to the Graph
void Graph::add_vertex(const std::bitset<STATES> &state)
{
	//check if already in Graph
	if (vertexID.find(state) != vertexID.end())  return;

	//else proceed to add in graph
	size_t stateID = V;	//assign state ID
	std::pair<std::bitset<STATES>, size_t> vertex(state, stateID);
	//add to map
	vertexID.insert(vertex);
	//add to adjadency list
	std::vector<Edge> adj;
	G.push_back(adj);

	//increment vertex count
	++V;
	inDegree.push_back(0);
}

//Add a new edge to the Graph
void Graph::add_edge(const std::bitset<STATES> &u,
					 const std::bitset<STATES> &v,
					 const size_t latency)
{
	//Find state IDs
	size_t uid = vertexID.find(u)->second;
	size_t vid = vertexID.find(v)->second;
	//Create a new Edge and insert
	Edge uv(u, uid, v, vid, latency);
	G[uid].push_back(uv);

	//Increment Edge Count
	++E;
	//Increment Indegree Count
	inDegree[vid] += 1;
	//TODO : Add Exception Check
}

//Return all adjacent Edges of vertex
const std::vector<Edge>& Graph::adj(const std::bitset<STATES> &vertex)
{
	size_t vID = vertexID.find(vertex)->second;
	return G[vID];
}

//Return |V|
size_t Graph::v_count(void)  { return V; }

//Return |E|
size_t Graph::e_count(void)  { return E; }

//Return all vertex as map vertex to ID
const std::unordered_map<std::bitset<STATES>, size_t>& Graph::vertex(void)
{
	return vertexID;
}

//Return Outdegree of a vertex
size_t Graph::out_degree(const std::bitset<STATES> &vertex)
{
	size_t vID = vertexID.find(vertex)->second;
	return G[vID].size();
}

//Return Indegree of a vertex
size_t Graph::in_degree(const std::bitset<STATES> &vertex)
{
	size_t vID = vertexID.find(vertex)->second;
	return inDegree[vID];
}

//Return String representation of the Graph
std::string Graph::to_string(void)
{
	std::string graphStr;
	//For all vertex
	for (auto &state : vertexID)
	{
		//TODO : Format String
		graphStr += "State : " + state.first.to_string() + "\n";
		//For all edges of the vertex
		for (auto &edge : G[state.second])
			graphStr += edge.to_string() + "\n";
	}
	return graphStr;
}
#ifndef GRAPH_H
#define GRAPH_H

//Author      : Suvojit Manna
//Application : CurveSim
//Header for Graph API 
//Provides abstraction for Edge Weighteed Directed Graph
//Supports Self Loops. PRovide methods to add Vertices on
//the fly (redundancy check included). Abstracts over
//Adjadency List Representaion of Graphs.

#include <bitset>
#include <string>
#include <unordered_map>
#include <vector>
#include "Edge.h"

class Graph
{
private:
	//maintain a map of state with ID
	std::unordered_map<std::bitset<STATES>, size_t> vertexID;
	//store Graph as Adjadency List
	std::vector<std::vector<Edge>>                  G;	
	//Strore indegree of each Vetex
	std::vector<size_t>                             inDegree;
	size_t V;
	size_t E;

public:
	//Default constructor for Graph
	//initialize with a Null Graph
	//@param  None
	Graph();

	//Initiate with the number of Vertex
	//@param  n size_t  Number of vertices
	Graph(const size_t n);

	//Adds a new Vertex to the graph
	//@param  state bitset  State of Pipeline
	//@return None
	void add_vertex(const std::bitset<STATES> &state);

	//Adds a new Edge to the Graph
	//@param  u bitset  Head State
	//@param  v bitset  Tail State
	//@param  latency size_t  Latency of change
	//@return None
	void add_edge(const std::bitset<STATES> &u,
				  const std::bitset<STATES> &v,
				  const size_t latency);

	//Return all adjacent Edges of a vetex
	//@param  vertex bitset  The vertex in check
	//@return const vector&  List of adjacent Edges
	const std::vector<Edge>& adj(const std::bitset<STATES> &vertex);

	//Returns |V|
	//@param  None
	//@return size_t  No of Vertex
	size_t v_count(void);

	//Returns |E|
	//@param  None
	//@return size_t  No of Edges
	size_t e_count(void);

	//Reutrns the no of incoming edge of a vertex
	//@param  vertex bitset  The vertex in check
	//@return size_t  Indegree of vertex
	size_t in_degree(const std::bitset<STATES> &vertex);

	//Reutrns the no of ougoing edge of a vertex
	//@param  vertex bitset  The vertex in check
	//@return size_t  Outdegree of vertex
	size_t out_degree(const std::bitset<STATES> &vertex);

	//Return String representation of the Graph
	//@param  None
	//@return string  String representation of the Graph
	std::string to_string(void);
};

#endif
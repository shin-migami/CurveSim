#ifndef RESERVETABLE_H
#define RESERVETABLE_H

//Author      : Suvojit Manna
//Application : CurveSim
//Header for the Reservation Table API
//Reservation Table is strored as a vector of Bitset 
//The API provides function for calculating ICV and
//Generates the State Diagram as a Graph using the
//Graph API. Further it calls the Cycle Finding API
//to generate Simple and Greedy Cycles
//@param  row size_t specifing the number of rows
//@param  col size_t specifing the number of columns

#include <bitset>
#include <vector>
#include <string>
#define STATES 64

class ReserveTable
{
private:
	//Size of Bitsets
	std::vector<std::bitset<STATES>> table;		//Stores the reservation table
	size_t                           load_count;//Keep count of Loaded stages
	bool                             loaded;	//All the states are loaded
	size_t                           row;		//No of rows in use
	size_t                           col;		//No of cols in use
	std::bitset<STATES>              ICV;		//The Initial Collision Vector

	//Calculate the Initial collision Vector if the Table is loaded
	//@param  None
	void calc_ICV(void);

public:
	//Constructor creates the Initializes the Table
	//with a vector of BitSet of Size row
	//Bitset is set to size 64 by default
	//@param  row size_t specifing the number of rows
	//@param  col size_t specifing the number of columns
	ReserveTable(const size_t row, const size_t col);

	//Return the Initial Collision Vector of the reservation table
	//@param  None
	//@return ICV string represntation of the Collision Vector
	std::string get_ICV(void);

	//Function to add a stage to the reservation table
	//@param  stageStr a string representation of the stage
	//@param  stageID  ID of stage to be loaded
	//@return None
	void add_stage(const std::string &stageStr, const size_t stageID);

	//Returns is the table loaded
	//@param  None
	//@return loaded bool indicating if the table is loaded
	bool is_loaded(void);

	//Return size of time slot
	//@param  None
	//@return size_t  No of time slot in use
	size_t timeslot_count(void);

	//Returns the Reservation Table as a String Object
	//@param  None
	//@return table std::string of the reservation table
	std::string to_string(void);
};
#endif
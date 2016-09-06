#include "ReserveTable.h"

//Author      : Suvojit Manna
//Application : CurveSim

ReserveTable::ReserveTable(size_t row, size_t col)
{
	//Set table is not loaded
	loaded     = false;
	load_count = 0;
	this->row  = row;
	this->col  = col;
	table.resize(row);
}

void ReserveTable::add_stage(std::string stageStr, size_t stageID)
{
	//Return on false call
	if (loaded)  return;

	//else create a bitset from the string
	std::bitset<STATES> stage(stageStr);
	table[stageID] = stage;
	//Increment the no of stages loaded
	++load_count;

	//If Table is completely loaded
	if (load_count == row)
	{
		loaded = true;
		//Pre calculate the ICV
		calc_ICV();
	}
}

bool ReserveTable::is_loaded(void)
{
	return loaded;
}

void ReserveTable::calc_ICV(void)
{
	//Calculates the ICV
	//Slides the stage vector along the orignal vector
	//Bitwise AND is performed on both vectors
	//If any bit is set in a iteration(i) it shows that
	//that (i) is a forbidden latency.Thus (i)th bit is set
	//in the Initial Collision Vector

	std::bitset<STATES> slideVector,
						checkVector;
	for (size_t i = 0; i < row; i++)
	//Repeat for all stages
	{
		for (size_t j = 1; j <= col; j++)
		{
			slideVector = table[i] >> j;
			//Bitwise AND
			checkVector = table[i] & slideVector;
			//Check if any bit is set
			if (checkVector.any())
				//Set the ith bit
				ICV.set(j);
		}
	}
}

std::string ReserveTable::get_ICV(void)
{
	//Return ICV as String
	std::string ICVString = ICV.to_string();
	//TODO : Format to Correct string
	return ICVString;
}

std::string ReserveTable::to_string(void)
{
	std::string tableStr;
	for (size_t i = 0; i < row; i++)
		tableStr += table[i].to_string() + "\n";
	return tableStr;
}
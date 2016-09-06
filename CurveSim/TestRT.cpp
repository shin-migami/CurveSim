#include <iostream>
#include "ReserveTable.h"

//Compile only if Testing class ReserveTable
#ifdef TEST_RESERVETABLE_H

int main()
{
	ReserveTable tab1(3, 8);
	std::string stage;
	for (size_t i = 0; i < 3; i++)
	{
		std::cin >> stage;
		if (stage.length() != 8)
			std::cout << "String Length Mismatch";
		else
			tab1.add_stage(stage, i);
	}
	std::cout << tab1.to_string();
	std::cout << tab1.get_ICV() << std::endl;
	return 0;
}
#endif
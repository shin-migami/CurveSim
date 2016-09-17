#include "MainUI.h"

//Author      : Suvojit Manna
//Application : CurveSim

#ifndef DEBUG
int main(int argc, char *argv[])
{
	size_t stages, timeSlot;
	std::cout << "*** Pipeline Scheduler ***" << std::endl;
	//If stages and timeslot provided in argument
	if (argc == 3)
	{
		try
		{
			stages   = std::atol(argv[1]);
			timeSlot = std::atol(argv[2]);
		}
		catch (const std::invalid_argument& ia)
		{
			std::cout << "Invalid Arguments" << std::endl;
			return -1;
		}
	}
	//Bad Argument
	else if (argc != 1)
	{
		std::cout << "Invalid Arguments" << std::endl;
		return -1;
	}
	//If not provided explicitly ask for argument
	else
	{
		std::cout << "Enter No of Stages : " << std::endl;
		std::cin  >> stages;
		std::cout << "Enter No of Time Slots : " << std::endl;
		std::cin  >> timeSlot;
	}
	//Create Reservation Table
	ReserveTable initTable(stages, timeSlot);
	//Fill up the Reservation Table
	if (!fill_reserve_table(initTable))  return -1;
	//Create State Diagram from the Reservation Table
	StateDiagram initDiagram(initTable);
	size_t choice;
	do
	{
		//Take Options
		main_menu();
		std::cin >> choice;
		switch (choice)
		{
			case 1: print_reserve_tab(initTable);     break;

			case 2: print_permissible(initTable);     break;

			case 3: print_forbidden(initTable);       break;

			case 4: print_ICV(initTable);             break;

			case 5: print_SID(initDiagram);           break;

			case 6: print_simple_cycles(initDiagram); break;

			case 7: print_greedy_cycles(initDiagram); break;

			case 8: print_MAL(initDiagram);           break;

			case 9: print_throughput(initDiagram);    break;

			case 0:  break;
			default: std::cout << "Invalid Option" << std::endl; break;
		}
	} while (choice != 0);
	return 0;
}
#endif
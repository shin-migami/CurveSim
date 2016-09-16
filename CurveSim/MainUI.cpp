#include "MainUI.h"

bool fill_reserve_table(ReserveTable& initTable)
{
	std::cout << "Enter data for each Stage\n"
		      << "Enter 0 if the Stage is unused for the time slot\n"
			  << "Enter 1 if the Stage is   used for the time slot"
			  << std::endl;
	for (size_t i = 0; i < initTable.stage_count(); i++)
	{
		std::cout << "Task list for Stage " << i + 1 << std::endl;
		std::string stageDesc;
		std::cin >> stageDesc;
		if (stageDesc.length() != initTable.timeslot_count())
		{
			std::cout << "Invalid Arguments" << std::endl;
			return false;
		}
		initTable.add_stage(stageDesc, i);
	}
	if (!initTable.is_loaded())
	{
		std::cout << "Internal Error" << std::endl;
		return false;
	}
	else  return true;
}

void main_menu(void)
{
	std::cout << "\nEnter Options : \n"
		<< "1 - Print Reservation Table\n"
		<< "2 - Print all Permissible Latency\n"
		<< "3 - Print all Forbidden Latency\n"
		<< "4 - Print Initial Collision Vector\n"
		<< "5 - Print State Initiation Diagram\n"
		<< "6 - Print all Simple Cycles\n"
		<< "7 - Print all Greedy Cycles\n"
		<< "8 - Print Minimum Average Latency\n"
		<< "9 - Print Pipeline Throughput\n"
		<< "0 - Exit\n"
		<< std::endl;
}

//Print Reservation Table
//@param  initTable  The Reservation Table
//@return None
void print_reserve_tab(ReserveTable& initTable)
{
	std::cout << "Reservation Table for Non-Linear Pipeline" << std::endl;
	std::cout << initTable.to_string() << std::endl;
}

//Print all Permissible Latency
//@param  initTable  The Reservation Table
//@return None
void print_permissible(ReserveTable& initTable)
{
	std::cout << "Permissible Latency for the Pipeline" << std::endl;
	for (auto latency : initTable.get_permissible())
		std::cout << latency << " ";
	std::cout << std::endl;
}

//Print all Forbidden Latency
//@param  initTable  The Reservation Table
//@return None
void print_forbidden(ReserveTable& initTable)
{
	std::cout << "Forbidden Latency for the Pipeline" << std::endl;
	for (auto latency : initTable.get_forbidden())
		std::cout << latency << " ";
	std::cout << std::endl;
}

//Print Initial Collision Vector
//@param  initTable  The Reservation Table
//@return None
void print_ICV(ReserveTable& initTable)
{
	std::cout << "Initial Collision Vector : <"
		<< initTable.get_ICV()
		<< ">" << std::endl;
}

//Print State Initiation Diagram
//@param  stateDiag  The State Initiation Diagram
//@return None
void print_SID(StateDiagram& stateDiag)
{
	std::cout << "State Initiation Diagram for the Pipeline\n"
		<< "Format : <Start State> -(Latency)-> <End State>" << std::endl;
	std::cout << stateDiag.to_string() << std::endl;
}

//Print all Simple Cycles
//@param  stateDiag  The State Initiation Diagram
//@return None
void print_simple_cycles(StateDiagram& stateDiag)
{
	std::cout << "All Simple Cycles in State Diagram" << std::endl;
	for (auto cycle : stateDiag.simple_cycles())
		std::cout << cycle.to_string() << " ";
	std::cout << std::endl;
}

//Print all Greedy Cycles
//@param  stateDiag  The State Initiation Diagram
//@return None
void print_greedy_cycles(StateDiagram& stateDiag)
{
	std::cout << "All Greedy Cycles in State Diagram" << std::endl;
	for (auto cycle : stateDiag.greedy_cycles())
		std::cout << cycle.to_string() << " ";
	std::cout << std::endl;
}

//Print Minimum Average Latency
//@param  stateDiag  The State Initiation Diagram
//@return None
void print_MAL(StateDiagram& stateDiag)
{
	std::cout << std::setprecision(2)
		<< "Minimum Average Latency : "
		<< stateDiag.MAL() << std::endl;
}

//Print Pipeline Throughput
//@param  stateDiag  The State Initiation Diagram
//@return None
void print_throughput(StateDiagram& stateDiag)
{
	std::cout << std::setprecision(5)
		<< "Pipeline Throughput : "
		<< stateDiag.get_throughput() << std::endl;
}


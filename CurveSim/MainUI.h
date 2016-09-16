#ifndef UI_H
#define UI_H
//#define DEBUG

//Author      : Suvojit Manna
//Application : CurveSim
//Header for User Interface point of the application

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include "ReserveTable.h"
#include "StateDiagram.h"

bool fill_reserve_table(ReserveTable& initTable);

void main_menu(void);

void print_reserve_tab(ReserveTable& initTable);

void print_permissible(ReserveTable& initTable);

void print_forbidden(ReserveTable& initTable);

void print_ICV(ReserveTable& initTable);

void print_SID(StateDiagram& stateDiag);

void print_simple_cycles(StateDiagram& stateDiag);

void print_greedy_cycles(StateDiagram& stateDiag);

void print_MAL(StateDiagram& stateDiag);

void print_throughput(StateDiagram& stateDiag);

#endif
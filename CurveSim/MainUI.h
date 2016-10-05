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

void print_reserve_tab(const ReserveTable& initTable);

void print_permissible(const ReserveTable& initTable);

void print_forbidden(const ReserveTable& initTable);

void print_ICV(const ReserveTable& initTable);

void print_SID(const StateDiagram& stateDiag);

void print_simple_cycles(const StateDiagram& stateDiag);

void print_greedy_cycles(const StateDiagram& stateDiag);

void print_MAL(const StateDiagram& stateDiag);

void print_throughput(const StateDiagram& stateDiag);

#endif

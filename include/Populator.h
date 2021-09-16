/* 
* Populator.h
* 
* Created on:16.9.21
* Author: Tom Krüger
*/
#include <iostream>
#include "Cell_Field.h"

using namespace std;
using namespace game_of_life;

#ifndef POPULATOR_H_
#define POPULATOR_H_
namespace populator
{
    void populate_field(Cell_Field &field, char distribution_char, int active_cells);

} /* namespace populator */
#endif /* POPULATOR_H_ */
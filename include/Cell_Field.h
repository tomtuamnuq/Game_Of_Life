/* 
* Cell_Field.h
* 
* Created on:16.9.21
* Author: Tom Krüger
*/
#include <iostream>
#include <vector>
#include "Cell.h"
using namespace std;

#ifndef CELL_FIELD_H_
#define CELL_FIELD_H_
namespace game_of_life
{
    class Cell_Field
    {

    public:
        static const int NR_ROWS = 200;
        static const int NR_COLUMNS = 200;
        Cell_Field();
        ~Cell_Field();
        void update();
        bool is_alive(int row, int col);
        void set_alive(int row, int col);
        static const int FIELD_WIDTH;
        static const int FIELD_HEIGHT;

    private:
        vector<vector<Cell>> field;
        void init_iteration();
        void calculate_neighbours();
        void check_cells(Cell *c1, Cell *c2);
    };
} /* namespace game_of_life */
#endif /* CELL_FIELD_H_ */
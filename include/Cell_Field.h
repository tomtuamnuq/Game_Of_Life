/* 
* Cell_Field.h
* 
* Created on:16.9.21
* Author: Tom Krüger
*/
#define NUMBER_OF_ROWS 512
#define NUMBER_OF_COLUMNS 512

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
        static const int NR_ROWS = NUMBER_OF_ROWS;
        static const int NR_COLUMNS = NUMBER_OF_COLUMNS;
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
/* 
* Cell_Field.cpp
* 
* Created on:16.9.21
* Author: Tom Krüger
*/
#include "Cell_Field.h"
#include <stdlib.h>
namespace game_of_life
{
    const int Cell_Field::FIELD_WIDTH = NR_COLUMNS * Cell::CELL_WIDTH;
    const int Cell_Field::FIELD_HEIGHT = NR_ROWS * Cell::CELL_HEIGHT;

    Cell_Field::Cell_Field() : field(vector<vector<Cell>>(NR_ROWS, vector<Cell>(NR_COLUMNS)))
    {
    }
    Cell_Field::~Cell_Field()
    {
    }

    bool Cell_Field::is_alive(int row, int col)
    {

        return field[row][col].is_alive();
    }
    void Cell_Field::set_alive(int row, int col)
    {
        field[row][col].set_alive();
    }
    void Cell_Field::update()
    {
        init_iteration();
        calculate_neighbours();
    }
    void Cell_Field::init_iteration()
    {
        for (int i = 0; i < NR_ROWS; i++)
        {
            for (int j = 0; j < NR_COLUMNS; j++)
            {
                field[i][j].new_iteration();
            }
        }
    }
    void Cell_Field::calculate_neighbours()
    {
        Cell *current_cell = nullptr;
        for (int i = 0; i < NR_ROWS; i++)
        {
            for (int j = 0; j < NR_COLUMNS; j++)
            {
                current_cell = &field[i][j];
                if (j + 1 < NR_COLUMNS)
                {
                    check_cells(current_cell, &field[i][j + 1]);
                }
                if (i + 1 < NR_ROWS)
                {
                    check_cells(current_cell, &field[i + 1][j]);
                    if (j - 1 >= 0)
                    {
                        check_cells(current_cell, &field[i + 1][j - 1]);
                    }
                    if (j + 1 < NR_COLUMNS)
                    {
                        check_cells(current_cell, &field[i + 1][j + 1]);
                    }
                }
                current_cell->check_if_alive();
            }
        }
    }
    void Cell_Field::check_cells(Cell *c1, Cell *c2)
    {
        if (c1->is_alive())
        {
            c2->increment_neighbours();
        }

        if (c2->is_alive())
        {
            c1->increment_neighbours();
        }
    }

} /* namespace game_of_life */
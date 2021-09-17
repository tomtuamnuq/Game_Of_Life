/* 
* Cell.h
* 
* Created on:16.9.21
* Author: Tom Krüger
*/
#include <iostream>
#define WIDTH_OF_CELL 20
#define HEIGHT_OF_CELL 20

using namespace std;

#ifndef CELL_H_
#define CELL_H_
namespace game_of_life
{
    static const bool debug = true;
    extern int number_of_cells;
    extern int number_of_direct_cells;
    extern int number_of_copied_cells;

    class Cell
    {
    private:
        bool alive;
        short active_neighbours; // range 0 to 8

    public:
        static const int CELL_WIDTH = WIDTH_OF_CELL;
        static const int CELL_HEIGHT = HEIGHT_OF_CELL;
        Cell();
        Cell(const Cell &other);
        ~Cell();
        void new_iteration();
        void increment_neighbours();
        bool is_alive();
        void check_if_alive();
        void set_alive();
    };
} /* namespace game_of_life */
#endif /* CELL_H_ */
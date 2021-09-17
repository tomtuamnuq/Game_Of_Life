/* 
* Cell.h
* 
* Created on:16.9.21
* Author: Tom Krüger
*/
#include <iostream>

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
        static const int CELL_WIDTH = 20;
        static const int CELL_HEIGHT = 20;
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
/* 
* Cell.cpp
* 
* Created on:
* Author: Tom Krüger
*/
#include "Cell.h"
#include <stdlib.h>
namespace game_of_life
{
    // for sanity and performance checking:
    int number_of_cells = 0;
    int number_of_direct_cells = 0;
    int number_of_copied_cells = 0;

    Cell::Cell() : active_neighbours(0), alive(false)
    {
        if (debug)
        {
            number_of_cells++;
            number_of_direct_cells++;
        }
    }
    Cell::Cell(const Cell &other) : active_neighbours(0), alive(false)
    {
        if (debug)
        {
            number_of_cells++;
            number_of_copied_cells++;
        }
    }
    Cell::~Cell()
    {
        if (debug)
            number_of_cells--;
    }
    void Cell::new_iteration()
    {
        active_neighbours = 0;
    }
    void Cell::increment_neighbours()
    {
        if (debug && active_neighbours > 8)
        {
            throw logic_error("Too many neighbours!");
        }

        active_neighbours++;
    }
    bool Cell::is_alive()
    {
        return alive;
    }
    void Cell::set_alive()
    {
        alive = true;
    }
    void Cell::check_if_alive()
    {
        if (!alive)
        {
            if (active_neighbours == 3)
            {
                alive = true;
            }
        }
        else
        {
            if (active_neighbours < 2 || active_neighbours > 3)
            {
                alive = false;
            }
        }
    }

} /* namespace game_of_life */
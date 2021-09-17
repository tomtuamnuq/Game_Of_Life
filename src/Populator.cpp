/* 
* Populator.cpp
* 
* Created on:16.9.21
* Author: Tom Krüger
*/

#include <stdlib.h>
#include <random>
#include <functional>
#include "Populator.h"
namespace populator
{
    random_device rd{};
    mt19937 rng{rd()};
    normal_distribution<> normal;
    uniform_real_distribution<> uniform;
    negative_binomial_distribution<> binomial(100, 0.5); // number of failures must be high to produce many points
    exponential_distribution<> exponential;

    double normal_rng()
    {
        return normal(rng);
    }
    double uniform_rng()
    {
        return uniform(rng);
    }
    double binomial_rng()
    {
        return binomial(rng);
    }
    double exponential_rng()
    {
        return exponential(rng);
    }

    void populate_field(Cell_Field &field, char distribution_char, int active_cells)
    {
        if (active_cells < 2)
        {
            throw logic_error("Must be two or more active cells at the start!");
        }
        if (active_cells > Cell_Field::NR_ROWS * Cell_Field::NR_COLUMNS)
        {
            throw logic_error("Must not be more active cells than cells on the field!");
        }

        function<double()> distribution;

        switch (distribution_char)
        {
        case 'n': // normal
            distribution = normal_rng;
            break;
        case 'b': // binomial
            distribution = binomial_rng;
            break;
        case 'e': // exponential
            distribution = exponential_rng;
            break;
        case 'u':
        default:
            distribution = uniform_rng;
            break;
        }
        double random_x[active_cells];
        double random_y[active_cells];
        double min_x = distribution();
        double min_y = distribution();
        double max_x = min_x;
        double max_y = min_y;
        random_x[0] = min_x;
        random_y[0] = min_y;
        for (int i = 1; i < active_cells; i++)
        {
            random_x[i] = distribution();
            if (random_x[i] < min_x)
                min_x = random_x[i];
            if (random_x[i] > max_x)
                max_x = random_x[i];
            random_y[i] = distribution();
            if (random_y[i] < min_y)
                min_y = random_y[i];
            if (random_y[i] > max_y)
                max_y = random_y[i];
        }
        if (debug)
        {
            cout << "Max x on Populator: " << max_x << endl;
            cout << "Min y on Populator: " << min_y << endl;
        }
        const double range_x = max_x - min_x;
        const double range_y = max_y - min_y;
        const double ratio_x = (Cell_Field::NR_COLUMNS - 1) / range_x;
        const double ratio_y = (Cell_Field::NR_ROWS - 1) / range_y;
        if (debug)
        {
            cout << "Ratio x on Populator: " << ratio_x << endl;
            cout << "Ratio y on Populator: " << ratio_y << endl;
        }
        for (int i = 0; i < active_cells; i++)
        {
            int pos_x = round((random_x[i] - min_x) * ratio_x);
            int pos_y = round((random_y[i] - min_y) * ratio_y);
            field.set_alive(pos_y, pos_x);
        }
    }

} /* namespace populator */

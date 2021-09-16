/* 
* main.cpp
* 
* Created on:16.9.21
* Author: Tom Krüger
*/
#include <iostream>
#include <SDL.h>
#include "Screen.h"
#include "Cell_Field.h"
using namespace std;
using namespace game_of_life;

const float RATIO_X = float(Screen::SCREEN_WIDTH) / Cell_Field::FIELD_WIDTH;
const float RATIO_Y = float(Screen::SCREEN_HEIGHT) / Cell_Field::FIELD_HEIGHT;
const int CELL_WIDTH_ON_SCREEN = floor(RATIO_X * Cell::CELL_WIDTH);
const int CELL_HEIGHT_ON_SCREEN = floor(RATIO_Y * Cell::CELL_HEIGHT);

void draw_field_to_screen(Cell_Field &field, Screen &screen);

int main()
{
    {
        Screen screen;
        if (!screen.init("Game Of Life"))
        {
            screen.close();
            return 1;
        }

        Cell_Field field;
        // init field with some probability distribution TODO
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 150; j++)
            {
                field.set_alive(i, j);
            }
        }

        while (true)
        {
            Uint64 start = SDL_GetPerformanceCounter();
            field.update();
            draw_field_to_screen(field, screen);
            screen.update();
            if (!screen.processEvents())
                break;

            Uint64 end = SDL_GetPerformanceCounter();
            float elapsedMS = (end - start) / (float)SDL_GetPerformanceFrequency() * 1000.0f;
            screen.check_for_fps(elapsedMS);
        }
    }
    if (debug)
    {
        cout << "Number of Cells: " << number_of_cells << endl;
        cout << "Number of direct Cells: " << number_of_direct_cells << endl;
        cout << "Number of copied Cells: " << number_of_copied_cells << endl;
    }

    return 0;
}

void draw_field_to_screen(Cell_Field &field, Screen &screen)
{
    SDL_Rect rect;
    rect.w = CELL_WIDTH_ON_SCREEN;
    rect.h = CELL_HEIGHT_ON_SCREEN;
    bool colored = false;
    bool alive = false;
    rect.y = 0;
    screen.setDrawColor(WHITE);
    colored = false;
    for (int i = 0; i < Cell_Field::NR_ROWS; i++)
    {
        rect.x = 0;
        for (int j = 0; j < Cell_Field::NR_COLUMNS; j++)
        {
            alive = field.is_alive(i, j);
            if (alive && !colored)
            {
                screen.setDrawColor(BLUE);
                colored = true;
            }
            else
            {
                if (!alive && colored)
                {
                    screen.setDrawColor(WHITE);
                    colored = false;
                }
            }
            screen.drawFilledRect(&rect);
            rect.x += CELL_WIDTH_ON_SCREEN;
        }
        rect.y += CELL_HEIGHT_ON_SCREEN;
    }
}
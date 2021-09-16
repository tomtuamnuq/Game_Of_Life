/* 
* Screen.cpp
* 
* Created on:16.9.21
* Author: Tom Krüger
*/
#include "Screen.h"

namespace game_of_life
{
    Screen::Screen() : m_window(NULL), m_renderer(NULL)
    {
    }

    Screen::~Screen()
    {
    }

    bool Screen::init(const char *window_name)
    {
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {

            cout << "SDL Init failed!" << endl;
            cout << "SDL Error message:" << SDL_GetError() << endl;
            return false;
        }

        m_window = SDL_CreateWindow(window_name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                    SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if (m_window == NULL)
        {
            return false;
        }

        m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
        if (m_renderer == NULL)
        {

            cout << "Could not create renderer!" << endl;
            return false;
        }

        return true;
    }
    void Screen::clear()
    {
        setDrawColor(BLACK);
        SDL_RenderClear(m_renderer);
    }
    void Screen::update()
    {
        SDL_RenderPresent(m_renderer);
    }

    bool Screen::processEvents()
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                return false;
            }
        }
        return true;
    }
    void Screen::check_for_fps(float elapsedMS)
    {
        if (elapsedMS < MS_PER_FRAME)
        {
            SDL_Delay(floor(MS_PER_FRAME - elapsedMS));
        }
    }
    void Screen::close()
    {
        // delete[] 2D structure TODO
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
    }
    void Screen::setDrawColor(SDL_Color color)
    {
        SDL_SetRenderDrawColor(m_renderer,
                               color.r, color.g, color.b,
                               255);
    }
    void Screen::drawFilledRect(const SDL_Rect *rect)
    {
        SDL_RenderFillRect(m_renderer, rect);
    }

} /* namespace game_of_life */
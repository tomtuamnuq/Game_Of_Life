/* 
* EventHandler.cpp
* 
* Created on:16.9.21
* Author: Tom Krüger
*/
#include "EventHandler.h"

namespace game_of_life
{
    EventHandler::EventHandler()
    {
    }

    EventHandler::~EventHandler()
    {
    }

    bool EventHandler::processEvents()
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

} /* namespace game_of_life */
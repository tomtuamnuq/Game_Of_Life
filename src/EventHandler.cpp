/* 
* EventHandler.cpp
* 
* Created on:16.9.21
* Author: Tom Krüger
*/
#include "EventHandler.h"

namespace game_of_life
{
    EventHandler::EventHandler() : clickListener(nullptr)
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
            else
            {
                if (clickListener != nullptr && event.type == SDL_MOUSEBUTTONDOWN) // for left only add: && event.button.button == SDL_BUTTON_LEFT
                {
                    cout << "Call click Listener " << endl;
                    clickListener(event.button.x, event.button.y);
                }
            }
        }
        return true;
    }
    void EventHandler::addClickListener(function<void(int, int)> clickListener)
    {
        this->clickListener = clickListener;
    }

} /* namespace game_of_life */
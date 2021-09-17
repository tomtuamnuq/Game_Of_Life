/* 
* EventHandler.h
* 
* Created on:17.9.21
* Author: Tom Krüger
*/
#include <iostream>
#include <SDL.h>

using namespace std;

#ifndef EVENT_HANDLER_H_
#define EVENT_HANDLER_H_
namespace game_of_life
{

    class EventHandler
    {
    public:
    private:
    public:
        EventHandler();
        ~EventHandler();
        bool processEvents();
    };
} /* namespace game_of_life */
#endif /* EVENT_HANDLER_H_ */
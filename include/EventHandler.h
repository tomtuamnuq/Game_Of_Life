/* 
* EventHandler.h
* 
* Created on:17.9.21
* Author: Tom Krüger
*/
#include <iostream>
#include <SDL.h>
#include <functional>

using namespace std;

#ifndef EVENT_HANDLER_H_
#define EVENT_HANDLER_H_
namespace game_of_life
{

    class EventHandler
    {
    public:
    private:
        function<void(int, int)> clickListener;

    public:
        EventHandler();
        ~EventHandler();
        bool processEvents();
        void addClickListener(function<void(int, int)>);
    };
} /* namespace game_of_life */
#endif /* EVENT_HANDLER_H_ */
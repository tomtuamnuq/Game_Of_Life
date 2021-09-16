/* 
* Screen.h
* 
* Created on:16.9.21
* Author: Tom Krüger
*/
#include <iostream>
#include <SDL.h>

using namespace std;

#ifndef SCREEN_H_
#define SCREEN_H_
namespace game_of_life
{
    static const SDL_Color WHITE = {255, 255, 255};
    static const SDL_Color BLUE = {0, 0, 255};
    static const SDL_Color BLACK = {0, 0, 0};
    static const int FPS = 2;
    static const float MS_PER_FRAME = 1000.0f / FPS;

    class Screen
    {
    public:
        static const int SCREEN_WIDTH = 800;
        static const int SCREEN_HEIGHT = 600;

    private:
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;

    public:
        Screen();
        ~Screen();
        void clear();
        void update();
        bool init(const char *window_name);
        bool processEvents();
        void close();
        void setDrawColor(SDL_Color color);
        void drawFilledRect(const SDL_Rect *rect);
        void check_for_fps(float elapsedMS);
    };
} /* namespace game_of_life */
#endif /* SCREEN_H_ */
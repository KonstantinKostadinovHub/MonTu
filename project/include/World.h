#ifndef WORLD_H
#define WORLD_H

#define _WIN32_WINNT 0x0500

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include <SDL2/SDL.h>

#include "ConfigManager.h"
#include "SoundManager.h"
#include "HealthManager.h"
#include "PopUpWriter.h"
#include "PickAndBan.h"
#include "PlayerStatsManager.h"
#include "Battle.h"
#include "Menu.h"
#include "Engine.h"

class World
{
    public:
        World();
        virtual ~World();

        SDL_Window* m_main_window;
        SDL_Cursor* m_cursor;
        SDL_Renderer* m_main_renderer;

        TTF_Font* m_font;

        ConfigManager m_configManager;
        SoundManager m_soundManager;
        PickAndBan m_pickAndBan;
        HealthManager m_healthManager;
        PlayerStatsManager m_playerStatsManager;
        Battle m_battle;
        Menu m_menu;
        WorldMap m_worldMap;

        int m_SCREEN_WIDTH;
        int m_SCREEN_HEIGHT;
        coordinates m_mouse;
        bool m_mouseIsPressed;
        SDL_Event m_event;
        GAME_STATE m_gameState;
        bool m_quitScene;

        coordinates m_cameraOffset;
        short int m_cameraShakeDuration = 1;
        short int m_cameraShakeMagnitude = 2;
        time_t m_startShake;
        bool m_shake;

        color m_CP1;
        color m_CP2;

        char field[26][16];

        vector<SQUAD> m_available;
        vector<SQUAD> m_banned;

        vector<Building*> m_buildings;

        void initSDL(string configFile);
        void draw();
        void update();
        void cleaner();
        void destroySDL();
        void input();

        void initSession(GAME_STATE state);

        void cameraShake();

        void pickAndBan();

        void initMap(string configFile);

    protected:

    private:
};

#endif // WORLD_H

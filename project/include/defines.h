#ifndef DEFINES_H
#define DEFINES_H

#include <cmath>
#include <vector>
#include <map>
#include <SDL2/SDL.h>

#define MIN_FRAMETIME 5
#define D(x) cerr << #x << " = " << (x) << " | " << "LINE: " << __LINE__  << " in: " << __FILE__ << endl;

#include<vector>
#include<string>
using namespace std;
using usi = unsigned short int;

enum OWNER
{
    NOOWNER = 0,
    PLAYER1 = 1,
    PLAYER2 = 2
};

enum GAME_STATE
{
    NOSCENE = 0,
    MENU = 1,
    PICK_BAN = 2,
    GAME = 3,
    STATS = 4,
    MAP_CHOOSING = 5,
    WORLD_MAP = 6,
    EXIT = 7
};

enum SQUAD
{
    NOSQUAD = 0,
    ARCHER = 1,
    WARRIOR = 2,
    SPEARMEN = 3,
    CROSSBOWMEN = 4,
    KNIGHTS = 5
};

enum ICON_STATE
{
    AVAILABLE = 0,
    BANNED = 1,
    PICKED = 2
};
struct Button
{
    SDL_Rect startRect;
    SDL_Rect objectRect;

    SDL_Texture* objTexture = nullptr;

    double currentBonusW = 0;
    double currentBonusH = 0;

    double bonusW = 0;
    double bonusH = 0;

    double maxWidth = 0;
    double maxHeigth = 0;
};
enum PLAYER_STAT
{
    NOSTAT = 0,
    MONEY = 1,
    FOOD = 2
};

struct icon
{
    SQUAD m_type;
    ICON_STATE m_iconState;
    SDL_Rect m_rect;
    SDL_Texture* m_texture;
};

struct coordinates
{
    int x;
    int y;

    void operator=(const SDL_Rect& rect)
    {
        x = rect.x;
        y = rect.y;
    }

    void operator=(coordinates coor)
    {
        x = coor.x;
        y = coor.y;
    }

    void operator-(coordinates coor)
    {
        x -= coor.x;
        y -= coor.y;
    }

    void operator+(coordinates coor)
    {
        x += coor.x;
        y += coor.y;
    }

    bool operator==(coordinates coor)
    {
        if(x == coor.x && y == coor.y)
        {
            return true;
        }
        return false;
    }

    bool operator!=(coordinates coor)
    {
        if(x != coor.x && y != coor.y)
        {
            return true;
        }
        return false;
    }
};

struct UI_object
{
    SDL_Texture* objTexture = NULL;
    vector<SDL_Texture*> objAnimation;
    SDL_Rect objRect;
};

struct color
{
    short int r;
    short int g;
    short int b;
};
struct soldier{
    SQUAD type;
    int health;
    coordinates coord;
    unsigned int numberOfSoldiers;
};

struct squad_data{
    ///0 - city
    ///1 - map
    int state;
    string city;
    coordinates coords;
    string soldierFile;
    vector <soldier> soldiers;
};

struct soldier_data{
    vector <soldier> soldiers;
};

struct fcoordinates
{
    double x;
    double y;

    void operator=(const SDL_Rect& rect)
    {
        x = rect.x;
        y = rect.y;
    }

    void operator=(fcoordinates coor)
    {
        x = coor.x;
        y = coor.y;
    }

    void operator-(fcoordinates coor)
    {
        x -= coor.x;
        y -= coor.y;
    }

    void operator+(fcoordinates coor)
    {
        x += coor.x;
        y += coor.y;
    }

    bool operator==(fcoordinates coor)
    {
        if(x == coor.x && y == coor.y)
        {
            return true;
        }
        return false;
    }

    bool operator!=(fcoordinates coor)
    {
        if(x != coor.x && y != coor.y)
        {
            return true;
        }
        return false;
    }
};

struct mapObject
{
    SDL_Rect objRect;
    SDL_Rect dstRect;

    SDL_Texture* objTexture;

    bool mooving = false;

    fcoordinates coor;
};

#endif // DEFINES_H

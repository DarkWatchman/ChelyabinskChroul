#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#include <TxLib.h>

//#define NDEBUG

inline void screen_update(int ms_sleep_time);
inline void pause_if(int vkey);

const unsigned short WindowX = 1500;                /*Window OX axis length*/
const unsigned short WindowY = 700;                 /*Window OY axis length*/
const unsigned short WindowR = WindowX / WindowY;   /*Window OX / OY lengths ratio*/

const double gravity = 9.81;

const unsigned sleep_time = 10;

const unsigned max_hp = 100;

const double NPC_JUMP_FORCE = 40;

const int attack_cooldown = 3;
const int slide_cooldown = 4;
const int parry_cooldown = 4;

const int RKEY = int('D');                              /*The button responsible for moving to the right*/
const int LKEY = int('A');                              /*the button responsible for moving to the left*/
const int SKEY = int('S');                              /*The button responsible for sliding*/
const int JUMP = int(VK_SPACE);                         /*The button responsible for jumping*/
const int AKEY = int(VK_LBUTTON);                       /*The button responsible for attack*/
const int EXIT = int(VK_ESCAPE);                        /*The button responsible for exit*/
const int PKEY = int('Q');                              /*The button responsible for game pausing*/

const size_t NPC_MAX_HP = 100;

inline void screen_update(int ms_sleep_time)
{
    txSleep(ms_sleep_time);
    txSetFillColor(TX_WHITE);
    txSetColor(TX_WHITE);
    txClear();
}

inline void pause_if(int vkey)
{
    while(GetKeyState(vkey))
        txSleep();
}

#endif //__GLOBALS_H__

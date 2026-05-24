#pragma once

enum state {POM_STATE_WORKING, POM_STATE_IDLE, POM_STATE_PAUSED, POM_STATE_SHORT_BREAK, POM_STATE_LONG_BREAK};


struct Pomodoro_Config
{
    unsigned int work_duration; 
    unsigned int short_break_duration;  //сохраняем в секундах
    unsigned int long_break_duration;
    unsigned int cycle_threshold;
};

struct Pomodoro_Runtime
{
    enum state current_state;
    unsigned int remaining_seconds;
    unsigned int current_cycle_count;
   
};


struct AppState
{
    enum state s;
    struct Pomodoro_Runtime pmd_r;
    struct Pomodoro_Config pmd_c;

};


int AppState_Init(struct AppState* state, const struct Pomodoro_Config* cfg );

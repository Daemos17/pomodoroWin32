#include "app_state.h"
#include <stdio.h>

int AppState_Init(struct AppState* state, const struct Pomodoro_Config* cfg )
{
    struct Pomodoro_Config p_cfg;
    if(cfg != NULL)
    {
        p_cfg = *cfg;
    }
    else{
        p_cfg.work_duration = 1500;
        p_cfg.short_break_duration = 300;
        p_cfg.long_break_duration = 900;
        p_cfg.cycle_threshold = 3;
    }

    struct Pomodoro_Runtime p_r;
    p_r.current_state = POM_STATE_IDLE;
    p_r.remaining_seconds = p_cfg.work_duration ;
    p_r.current_cycle_count = 0;

    if(state != NULL)
    {
        state->s = POM_STATE_IDLE;
        state->pmd_r = p_r;
        state->pmd_c = p_cfg; 
    }
    else{return -1;}

    return 0;
}

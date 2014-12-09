#include "gamestate.h"

Gamestate gamestate;

/** \brief Initialize the clock.
 */
void startClock() {
    srand(time(NULL));
    gamestate.clock = 15 + (rand()%15);
}
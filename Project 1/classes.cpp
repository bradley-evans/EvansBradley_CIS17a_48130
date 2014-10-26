#include "classes.h"

void Gameclock::downtick(int loss) {    ///< To decrement the time counter.
    timeleft = timeleft - loss;
}

int Gameclock::currtime() {             ///< Displays time remaining.
    return(timeleft);
}

void Gameclock::initialize() {
    srand(time(NULL));
    timeleft = 20 + (rand()%20);
}

int Dice::roll (int size) {  
    int result;
    srand(clock());
    result = rand() % size;
    // Delay, to ensure the same time isn't used for each dice roll accidentally.
    clock_t start_time = clock();
    clock_t end_time = 10 + start_time;
    do { /* nothing */ } while ( clock() < end_time);
    return(result);
}

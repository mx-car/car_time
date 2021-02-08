/**
 * @author Markus Bader <markus.bader@mx-robotics.com>
 */

#include "car/time/cycle_rate.h"

using namespace car::time;

CycleRate::CycleRate(uint32_t duration_ms) 
: duration(duration_ms * 1000)
{
    last = micros();
    next = last + duration;
}

int CycleRate::passed()
{
    int counter = 0;
    uint32_t now = micros();
    if(now > next){
        last = now;
        while(next < now) {
            counter++;
            next+=duration;
        }
    }
    return counter;
}   
int32_t CycleRate::wait()
{
    uint32_t now = micros();
    int32_t delay = next - now;
    if(delay < 0){ 
        /// we missed the cycle
        last = now;
        while(next < now) next+=duration;
    } else {
        /// we have to wait for the cycle
        delayMicroseconds(delay);
        last = micros();
        next+=duration;
    }
    return delay;
} 

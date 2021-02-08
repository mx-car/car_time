/**
 * @author Markus Bader <markus.bader@mx-robotics.com>
 */


#ifndef CAR_TIME_CYCLE_RATE_H
#define CAR_TIME_CYCLE_RATE_H

#include <Arduino.h>

namespace car {
namespace time {

/**
 * Class to generate a constant loop cycle
 **/
class CycleRate {
    uint32_t last;             /// last trigger
    uint32_t next;             /// next trigger
    uint32_t duration;         /// duration between trigger in micros
    public:
    /**
     * Constructer
     * @param ms cycle time;
     **/
    CycleRate(uint32_t ms);

    /**
     * used to check if a cylce was passed
     * @returns returns zero if no cycle was passed otherwise the number of missed cycles;
     **/
    int passed();  

    /**
     * blocks unit the cyle starts or starts if the cycle passed already
     * @returns delay to the cycle rate if negative the cycle was passed and positive the fnc waited
     **/
    int32_t wait();  
};

};
};
#endif //CAR_TIME_CYCLE_RATE_H



/*
 * Scheduler.h
 *
 *  Created on: Sep 5, 2023
 *      Author: aaron
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include <stdint.h>

#define SCHEDULER_TOGGE_ZERO 1 << 0
#define SCHEDULER_DELAY 1 << 1



uint32_t getScheduledEvents();

void addSchedulerEvent(uint32_t Event);

void removeSchedulerEvent(uint32_t Event);

#endif /* SCHEDULER_H_ */

#ifndef HELLO1_H
#define HELLO1_H

#include <linux/list.h>
#include <linux/ktime.h>

struct event_data {
    struct list_head list;
    ktime_t timestamp;
    ktime_t print_duration;
};

void hello(unsigned int param);

#endif
#include <pthread.h>
#include <sched.h>

pthread_attr_t tattr;
pthread_t tid;
int newprio = 20;
sched_param param;

/* initialized with default attributes */
pthread_attr_init(&tattr);

/* get exisiting scheduling param */
pthread_attr_getschedparam(&tattr, &param);
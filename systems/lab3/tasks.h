#ifndef TASKS_H
#define Tasks_H

#define TASKS_MAX 100
#define TASK_LEN 100

//public return code
typedef enum
{
        TASK_OK=0,
        TASKS_ERR_FULL,
        TASKS_ERR_OOB,
        TASKS_ERR_INVALID
}task_result;

int tasks_init(void);
int  tasks_add(const char *text);
int tasks_remove(int index);
int tasks_count(void);
int tasks_get(int index, const char **out);

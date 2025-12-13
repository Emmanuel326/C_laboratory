#include <stdio.h>
#include "tasks.h"
#include <ctype.h>
#include <string.h>



static char tasks[TASKS_MAX][TASK_LEN +1];
static int task_count=0;


int tasks_init(void)
{
        task_count =0;

        for(int i=0; i<TASKS_MAX; i++)
        {
                tasks[i][0]='\0';

        }
        return 0;
}

int tasks_add(const char *text)
{
        if (text==NULL || text[0]=='\0' || isspace((unsigned char)text[0]))
        {
                return TASKS_ERR_INVALID;
        }
        if(task_count>=TASKS_MAX)
                return TASKS_ERR_FULL;

        //measure length
        size_t length=strlen(text);

        //destination pointer
        char *dest=tasks[task_count];

        size_t copy_len=(length<TASK_LEN) ? length:TASK_LEN;

        memcpy(dest, text, copy_len);
        dest[copy_len]='\0';

        task_count++;

        return TASKS_OK;
}


int tasks_remove(int index)
{
        if(index<0 || index>=task_count)

        {
                return TASKS_ERR_OOB;
                
        }
        //now i have to shift the tasks left
        for(int i=index; i<task_count-1; i++)
        {
                strcpy(tasks[i], tasks[i+1]);
        }

        //i am clearing the unused last slot
        tasks[task_count-1][0]='\0';
        task_count--;
        return TASKS_OK;
        //and  i just leveled up.i wont optimize it 
}

int tasks_count(void)
{
        return task_count;
}

int tasks_get(int index, const char **out)
{
        if(out==NULL)
        {return TASKS_ERR_INVALID;}
        if(index<0 || index>=task_count)
        {return TASKS_ERR_OOB;}

        *out=tasks[index];

        return TASKS_OK;

}

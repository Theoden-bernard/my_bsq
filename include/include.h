/*
** Lib printf, write...
*/
#include <stdio.h>
#include <stdlib.h>

/*
** Lib open
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*
** Lib close, read...
*/
#include <unistd.h>

/*
** ------------------------------------------------------------------------------------------------------------
*/

typedef struct s_file_bsq
{
    char* file_name;
    int size;
    int raw;
    int lentgh;
}t_file_bsq;


int my_bsq(char* file);
int open_file(char* file, int flag);
int my_strlen(char* str);
int my_putstr(char* str);
void* my_malloc(int size);
int my_atoi(char* str);
char* my_memeset(char* str, char car, int size);
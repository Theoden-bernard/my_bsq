#include <include.h>

char* my_memeset(char* str, char car, int size)
{
    for (int i = 0; i < size; i++)
    {
        str[i] = car;
    }
    
    return str;
}

int my_atoi(char* str)
{
    int num = 0;
    char zero_char = '0'; 

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            while (zero_char < str[i])
            {
                num += 1;
                zero_char += 1;
            }
        }
        
        if (str[i + 1] == '\0' || str[i + 1] == 10)
        {
            return num;
        }
        
        zero_char = '0';
        num *= 10;
    }
    
    return num;
}

int my_strlen(char* str)
{
    int index = 0;

    while (str[index] != '\0')
    {
        index += 1;
    }

    return index;
}

int my_putstr(char* str)
{
    return write(1, str, my_strlen(str));
}

void* my_malloc(int size)
{
    char* buff = malloc(sizeof(*buff) * (size));

    if (buff == NULL)
    {
        write(2, "[ERROR]: My malloc buffer null\n", my_strlen("[ERROR]: My malloc buffer null\n"));
        return 0;
    }

    my_memeset(buff, 0, size);
    
    return buff;
}

int open_file(char* file, int flag)
{
    int fd = open(file, flag);

    if (fd == -1)
    {
        write(2, "[ERROR]: file not found\n", my_strlen("[ERROR]: file not found\n"));
        return fd;
    }

    return fd;
}
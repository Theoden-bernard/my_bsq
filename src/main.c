#include <include.h>

int main(int ac, char** av)
{
    if (ac < 2)
    {
        write(2, "[ERROR]: Not file\n", my_strlen("[ERROR]: Not file\n"));
        return 1;
    }
    
    (void)av[1];
    
    my_bsq(av[1]);

    return 0;
}
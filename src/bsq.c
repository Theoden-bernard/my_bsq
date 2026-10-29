#include <include.h>

t_file_bsq* init_struct_size(t_file_bsq* stat_file)
{
    int fd = open_file(stat_file->file_name, O_RDONLY );

    if (fd == -1)
    {
        return 0;
    }
    
    char buff[4096];
    char c = 0;
    int index = 0;

    my_memeset(buff, 0, 4096);

    while (c != 10)
    {
        read(fd, &c, 1);
        buff[index] = c;
        index += 1;
    }
    
    stat_file->raw = my_atoi(buff);
    my_memeset(buff, 0, 4096);

    index = 0;
    c = 0;

    while (c != 10)
    {
        read(fd, &c, 1);
        buff[index] = c;
        index += 1;
    }

    stat_file->lentgh = index;
    stat_file->size = stat_file->raw * stat_file->lentgh;
    
    close(fd);

    return stat_file;
}

void past_intro_seed(int fd)
{
    char c = 0;

    while (c != 10)
    {
        read(fd, &c, 1);
    }
}

int my_bsq(char* file)
{
    t_file_bsq* stat_file = malloc(sizeof(*stat_file) * 1);
    if (stat_file == NULL) return 1;
    stat_file->file_name = file;
    init_struct_size(stat_file);

    int fd = open_file(stat_file->file_name, O_RDONLY );

    if (fd == -1)
    {
        return 0;
    }
    
    char* seed = my_malloc(sizeof(*seed) * (stat_file->size + 1));
    past_intro_seed(fd);
    read(fd, seed, stat_file->size);

    close(fd);
    free(seed);
    free(stat_file);

    return 0;
}
#include "include.h"

int map_height(char *f_name)
{
    int i;
    char *line;
    int fd;

    i = 0;
    fd = open(f_name, O_RDONLY);
    while(get_next_line(fd, &line))
    {
        i++;
        free(line);
    }
   close(fd);
    return (i);
}

int map_width(char *f_name)
{
    int i;
    int fd;
    char *line;

    fd = open(f_name, O_RDONLY);
    get_next_line(fd, &line);
    i = ft_word_count(line, ' ');
    close(fd);
    free(line);
    return(i);
}

void get_matrix_info(int *int_line, char *line)
{
    int i;
    i = 0;
    char **num_char;
    num_char = ft_split(line, ' ');
    while(num_char[i])
    {
        int_line[i] = ft_atoi(num_char[i]);
        i++;
    }
    free(num_char);
}

void get_map_info(char* f_name,t_info *info)
{
    int i;
    int j;
    int fd;
    char *line;

    info->height = map_height(f_name); // count of lines
    info->width = map_width(f_name); // count of numbers in line
    info->map_matrix = malloc(sizeof(int*) * (info->height));
    i = 0;
    while(i < info->height)
    {
        info->map_matrix[i] = malloc(sizeof(int*) * (info->width ));
        i++;
    }
    fd = open(f_name, O_RDONLY);
    i = 0;
    while(get_next_line(fd, &line))
    {
        get_matrix_info(info->map_matrix[i], line);
        free(line);
        i++;
    }
    close(fd);
    info->map_matrix[i] = 0;
}
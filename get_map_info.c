#include "include.h"

void get_map_info(char* f_name,t_info *info)
{
    info->height = map_height(f_name);
    info->width = map_witdth(f_name);
}
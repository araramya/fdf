#include "include.h"

int main()
{
    t_info *info;
    info = (t_info*)malloc(sizeof(t_info));
    get_map_info(info);
}
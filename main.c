#include "include.h"
int		create_rgb(int r, int g, int b)
{
	return(r << 16 | g << 8 | b);
}

void	ft_clear(t_info *data) // paint all window BLACK
{
	for(int i = 0; i < WIN_H; i++)
	{
		for(int j = 0; j < WIN_L; j++)
		{
			my_mlx_pixel_put(&data->image, j, i, create_rgb(0, 0, 0));
		}
	}
}
int ft_frame(t_info *info)
{
  ft_clear(info);
           //    mlx_clear_window(info->mlx_ptr, info->mlx_win);
  merge_lines(info);
  mlx_put_image_to_window(info->mlx_ptr, info->mlx_win, info->image.img, 0, 0);
  mlx_do_sync(info->mlx_ptr);
  return(1);
}

int main(int argc, char **argv)
{
    int x;
    int y;
    t_info *info;
    info = (t_info*)malloc(sizeof(t_info));
    info->coefficient = 20;
    get_map_info (argv[1],info);
    info->mlx_ptr = mlx_init();
    info->mlx_win = mlx_new_window(info->mlx_ptr, WIN_H, WIN_L, "FDF");
    info->image.img = mlx_new_image(info->mlx_ptr, WIN_H, WIN_L);
    info->image.addr = mlx_get_data_addr(info->image.img, &info->image.bbp, &info->image.line_len, &info->image.endian);
   // mlx_key_hook(info->mlx_win, key_pressed, info);
    mlx_hook(info->mlx_win, 2, 0, key_pressed, info);
    mlx_loop_hook(info->mlx_ptr, ft_frame, info );
    mlx_loop(info->mlx_ptr); 
   // ft_frame(info);
  
    //mlx_put_image_to_window(info->mlx_ptr, info->mlx_win, info->image.img, 0, 0);
    //printf("hi\n");
  

}
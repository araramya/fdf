# fdf

USAGE:

      "make" or "make bonus"
      "./fdf test_maps/mapname.fdf"
      
You can read about mlx libary here:

      https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
      https://qst0.github.io/ft_libgfx/man_mlx.html

READING MAP:
      
      first of all you need read map file and save it data. For that you need:
      get height (number of lines)
      get width (number of words in each line)
      allocate memory (**int) in array and write the data in it.
      #BE_SMART: Use get_next_line function
      
DRAWING LINE FUNCTION (Bresenham algorithm):

      You need a function which get 2 point coordinates and connect that points to each other.
      
      void ft_bresenham(float x1, float x2, float y1, float y2)
      {
        dx = x2 - x1;
        dy = y2 - y1;
        max = MAXIMUM(|dx|, |dy|) // you need maximum to understand how will your line grow, and the speed of it.
        dx = dx\max;
        dy = dy\max;
        while((int)(x2 - x1) || (int)(y2 - y1))
        {
          my_mlx_pixel_put(x1, y1);
          x1 += dx;
          y1 += dy;
        }
      }
      
      I don't know when you will write this programm but when I wrote that it had some BUGS for that I added some additional statment im my drowing function
      
      if((y1 < WIN_HEIGHT) && (x1 < WIN_LEN))
        if(x1 >= 0 && y1 >= 0)
          draw_function.

CONNECTION DOTS:

      Now you need dunction which will draw lines betveen every dot
      
      0 -> 0 -> 0 -> 0
      |    |    |    |
      v    v    v    v
      0 -> 0 -> 0 -> 0
      |    |    |    |
      v    v    v    v
      0 -> 0 -> 0 -> 0
      |    |    |    |
      v    v    v    v
      0 -> 0 -> 0 -> 0
      
      Don't forget to check limits.
      
      I recommend you to change your pixel color when your z is not a 0.
      
      if you done it and you see in your monitor a little dot or something like dot in the left corner, DON'T PANIC, you just need to zoom your map.
      Just multiplay your coordinates with const value.
      
ADDING 3D EFFECT:

       I found this formula to draw isometric form for 2D pattern
       x1 = (x - y) * cos(angle)
       x2 = (x + y) * sin(angle) - z
       Play with angle it will help you in Bonus part.

BONUSES:
        Add zoom, rotation, translation of map for bonus part if you want, don't forget about leaks, and error handling.
        GOOD LUCK!!! Forany questions arsen.aramyan2001@gmail.com
      
      
    

#include "solong.h"




/*t_img *initialize_img(char c, void *mlx)
{
    t_img img;
    t_rect space;
    int elm_w = ELM_WIDTH; 
    int elm_h = ELM_WIDTH;

    space.width  = ELM_WIDTH;
    space.height = ELM_WIDTH;
    space.fill_color = 0x00FF0000;
    space.x = 0;
    space.y = 0;

    if (c == 'w')
    {
        img.mlx_img = mlx_xpm_file_to_image(mlx, "wall.xpm", &elm_w, &elm_h);
    }
    else if (c == 'e')
    {
        img.mlx_img = mlx_new_image(mlx,  ELM_WIDTH, ELM_WIDTH);
        put_filled_rect(img, space);
    }
    img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp, &img.line_len, &img.endian);
    return (img);
}*/
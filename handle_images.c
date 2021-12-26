#include "solong.h"

void    display_image(t_data *data, int i, int j, int x, int y)
{
    t_img   wall;
    t_img   monster;
    t_img   coin;
    t_img   empty_space;
    t_img   closed_door;
    t_img   open_door;
    t_img enemy;
    
    init_images(&monster, &empty_space, &coin, data);
    init_images_(&wall, &closed_door, &open_door, data);
    init_enemy(&enemy, data);
    if (data->map_tab[i][j] == '1')
        mlx_put_image_to_window(data->mlx, data->win, wall.mlx_img, x, y);
    else if (data->map_tab[i][j] == '0')
        mlx_put_image_to_window(data->mlx, data->win, empty_space.mlx_img, x, y);
    else if (data->map_tab[i][j] == 'C')
        mlx_put_image_to_window(data->mlx, data->win, coin.mlx_img, x, y);
    else if (data->map_tab[i][j] == 'P')
        mlx_put_image_to_window(data->mlx, data->win, monster.mlx_img, x, y);
    else if (data->map_tab[i][j] == 'E')
        mlx_put_image_to_window(data->mlx, data->win, closed_door.mlx_img, x, y);
    else if (data->map_tab[i][j] == 'O')
        mlx_put_image_to_window(data->mlx, data->win, open_door.mlx_img, x, y);
    else if (data->map_tab[i][j] == 'I')
        mlx_put_image_to_window(data->mlx, data->win, enemy.mlx_img, x, y);
}
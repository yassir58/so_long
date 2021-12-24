#include "solong.h"


char **extract_map(void)
{
    int i = 0;
    char *line = NULL;
    char **map;

    map = (char  **)malloc(1000 * sizeof(char *));
    if (!map)
    {
        printf ("run out of heap memory\n");
        return (NULL);
    }
    int fd = open("test.ber", O_RDONLY);
    while ((line = get_next_line(fd)))
        map[i++] = line;
    map[i] = NULL;
    return (map);
}


void process_map(char **map, int *ln, int *en)
{
    int line_number = 0;
    int elem_number = 0;

    if (map)
    {
        while (map[line_number])
        {
            printf ("|%s|\n",map[line_number]);
            line_number++;
        }
        *ln = line_number;
        *en = ft_strlen(map[0]) - 1;
    }
}

/*int check_for_valid_map(char **map)
{
    int i = 0;
    int j = 0;

    

}*/


void draw_map(t_data *data)
{
   int elm_w = ELM_WIDTH; 
    int elm_h = ELM_WIDTH;
    int x=0, y=0, i=0, j=0;
    t_img img;
    t_img monster;
    t_img coin;
    t_img empty_space;
    t_rect space;
    t_img closed_door;
    t_img open_door;
    space.width  = ELM_WIDTH;
    space.height = ELM_WIDTH;
    space.fill_color = 0x00FF0000;
    space.x = 0;
    space.y = 0;


    img.mlx_img = mlx_xpm_file_to_image(data->mlx, "wall.xpm", &elm_w, &elm_h);
    img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp, &img.line_len, &img.endian);
    empty_space.mlx_img = mlx_new_image(data->mlx,  ELM_WIDTH, ELM_WIDTH);
    empty_space.addr = mlx_get_data_addr(empty_space.mlx_img, &empty_space.bpp, &empty_space.line_len, &empty_space.endian);
    put_filled_rect(empty_space, space);
    monster.mlx_img = mlx_xpm_file_to_image(data->mlx, "monster.xpm", &elm_w, &elm_h);
    monster.addr = mlx_get_data_addr(monster.mlx_img, &monster.bpp, &monster.line_len, &monster.endian);
    coin.mlx_img = mlx_xpm_file_to_image(data->mlx, "coin.xpm", &elm_w, &elm_h);
    coin.addr = mlx_get_data_addr(coin.mlx_img, &coin.bpp, &coin.line_len, &coin.endian);
    closed_door.mlx_img = mlx_xpm_file_to_image(data->mlx, "closed_door.xpm", &elm_w, &elm_h);
    closed_door.addr = mlx_get_data_addr(closed_door.mlx_img, &closed_door.bpp, &closed_door.line_len, &closed_door.endian);
    open_door.mlx_img = mlx_xpm_file_to_image(data->mlx, "open_door.xpm", &elm_w, &elm_h);
    open_door.addr = mlx_get_data_addr(open_door.mlx_img, &open_door.bpp, &open_door.line_len, &open_door.endian);

    while (data->map_tab[i])
    {
        while (data->map_tab[i][j])
        {
            if (data->map_tab[i][j] == '1')
                mlx_put_image_to_window(data->mlx, data->win, img.mlx_img,x,y);
            else if (data->map_tab[i][j] == '0')
                mlx_put_image_to_window(data->mlx, data->win,empty_space.mlx_img,x, y);
            else if (data->map_tab[i][j] == 'C')
                mlx_put_image_to_window(data->mlx, data->win,coin.mlx_img,x, y);
            else if (data->map_tab[i][j] == 'P')
                mlx_put_image_to_window(data->mlx, data->win,monster.mlx_img,x, y);
            else if (data->map_tab[i][j] == 'E')
                mlx_put_image_to_window(data->mlx, data->win,closed_door.mlx_img,x,y);
            else if (data->map_tab[i][j] == 'O')
                 mlx_put_image_to_window(data->mlx, data->win,open_door.mlx_img,x,y);

            x += ELM_WIDTH;
            j++;
        }
        
        y += ELM_WIDTH;
        j= 0;
        x = 0;
        i++;
    }
}


void get_element_position(char **map, int *i, int *j, char c)
{
    int in = 0;
    int jn = 0;
    while (map[in])
    {
         
        while (map[in][jn])
        {
            if (map[in][jn] == c)
            {
                *i = in;
                *j = jn;
            }
           jn++;
        }
        jn = 0;
        in++;
    }
}


int coin_count(char **map)
{
    int i = 0;
    int j = 0;
    int coin_count = 0;

    while (map[i])
    {
        while (map[i][j])
        {
            if (map[i][j] == 'C')
                coin_count++;

            j++;
        }
        j = 0;
        i++;
    }
    return (coin_count);
}


void end_game(t_data *data)
{
    int player_p_row = 0;
    int player_p_column = 0;
    int door_p_row = 0;
    int door_p_column = 0;
    get_element_position(data->map_tab, &player_p_row, &player_p_column, 'P');
    get_element_position(data->map_tab, &door_p_row, &door_p_column, 'E');
    data->map_tab[player_p_row][player_p_column] = '0';
    data->map_tab[door_p_row][door_p_column] = 'O';
    //mlx_clear_window(data->mlx,data->win);
}
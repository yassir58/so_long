#include "solong.h"

/*
char **extract_map(void)
{
    int i = 0;
    char *line = NULL;
    char **map;

    map = (char  **)malloc(1000 * sizeof(char *));
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
    int map_info[2];

    while (map[line_number])
        line_number++;
    while (map[0][elem_number])
        elem_number++;
    *ln = line_number;
    *en = elem_number;
}*/
/*
int check_for_valid_map(char **map)
{

}*/
/*

void draw_map(char **map, void *mlx, void *mlx_win, int i)
{
    int  j = 0;
    int x = 0;
    static int y = 0;
    int line_number = 0;
    int element_each = 0;
    process_map(map, &line_number, &element_each);
    double rect_width =  WINDOW_WIDTH / element_each;
    double rect_length = WINDOW_HEIGHT / line_number;

        printf("ln %d en %d gw %f gl %f \n",line_number,element_each,rect_width,rect_length);
    while (map[i][j])
    {
        if (map[i][j] == '0')
            put_filled_rect(mlx, mlx_win, x, y, rect_width, rect_length ,0x0000FFFF);
        else if (map[i][j] == '1')
            put_filled_rect(mlx, mlx_win, x, y, rect_width, rect_length ,0x00808080);
        else if (map[i][j] == 'C')
               // put_filled_rect(mlx, mlx_win, x, y, rect_width, rect_length ,0x00FFA500);
            put_circle(mlx, mlx_win, x+ 20,y + 20,15, 0x00FFA500);
        else if (map[i][j] == 'E')
            put_filled_rect(mlx, mlx_win, x, y, rect_width, rect_length ,0x00000000);
        else if (map[i][j] == 'P')
            put_filled_rect(mlx, mlx_win, x, y, rect_width, rect_length ,0x00964B00);
        x += rect_width;
        j++;
    }
    y += rect_length;
    printf("Y : %d\n",y);
}

*/
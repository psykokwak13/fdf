#include "test.h"

// static void iso(int *x, int *y, int z)
// {
//     int previous_x;
//     int previous_y;

//     previous_x = *x;
//     previous_y = *y;
//     *x = (previous_x - previous_y) * cos(0.523599);
//     *y = -z + (previous_x + previous_y) * sin(0.523599);
// }

// void ligne(int x1, int y1, int x2, int y2, void *win, void *mlx) {
//     int dx = abs(x2 - x1);
//     int dy = abs(y2 - y1);
//     int sx = (x1 < x2) ? 1 : -1;
//     int sy = (y1 < y2) ? 1 : -1;
//     int err = dx - dy;

//     while (1) {
//         mlx_pixel_put(mlx, win, x1, y1, 0x3498DB); // Place un pixel

//         if (x1 == x2 && y1 == y2)
//             break;

//         int e2 = 2 * err;

//         if (e2 > -dy) {
//             err -= dy;
//             x1 += sx;
//         }
//         if (e2 < dx) {
//             err += dx;
//             y1 += sy;
//         }
//     }
// }
// int fdf(char *filepath)
// {
// 	if (!parsing(filepath))
//         return (0);
// 	return (1);
// }

// int main(int argc, char **argv)
// {
// 	if (argc == 2)
// 		fdf(argv[1]);
// 	if (argc == 1)
// 		fdf("test.fdf");
// 	if (argc > 2)
// 		perror("trop d'argument : ./main.o [filename]");

// }

//   void *mlx;
//     void *window;

//     int x1 = 0;
//     int y1 = 0;

//     int x2 = 20;
//     int y2 = 0;
    
//     int z = 0;

//     mlx = mlx_init(); // Initialiser MiniLibX
//     window = mlx_new_window(mlx, 800, 600, "Wireframe Cube"); 
    
//     // Appliquer la transformation isométrique avant de dessiner la première ligne
//     isometric(&x1, &y1, z);
//     isometric(&x2, &y2, z);

//     // Affichage de la première ligne dans la fenêtre avec les coordonnées transformées
//     ligne(x1, y1, x2, y2, window, mlx);

//     // Redéfinir de nouvelles coordonnées pour la deuxième ligne (sans appliquer à nouveau la transformation)
//     // Si vous avez des nouvelles coordonnées, ajustez-les ici
//     int x3 = 0, y3 = 0;
//     int x4 = 0, y4 = -20;

//     // Appliquer la transformation isométrique pour les nouvelles coordonnées de la deuxième ligne
//     isometric(&x3, &y3, z);  // Sans hauteur (z=0) pour la deuxième ligne
//     isometric(&x4, &y4, z);

//     ligne(x3, y3, x4, y4, window, mlx);
//     mlx_loop(mlx); // Lancer la boucle principale
//     return 0;

#include <stdio.h>
#include <stdlib.h>
#include "test.h"

typedef struct s_data
{
    void *mlx;
    void *win;
    int width;
    int height;
} t_data;

// Fonction pour dessiner un quadrillage
void draw_grid(t_data *data)
{
    int x, y;
    int cell_size = 20;

    // Effacer la fenêtre
    mlx_clear_window(data->mlx, data->win);

    // Dessiner les lignes horizontales
    for (y = 0; y <= data->height; y += cell_size)
        for (x = 0; x < data->width; x++)
            mlx_pixel_put(data->mlx, data->win, x, y, 0xFFFFFF);

    // Dessiner les lignes verticales
    for (x = 0; x <= data->width; x += cell_size)
        for (y = 0; y < data->height; y++)
            mlx_pixel_put(data->mlx, data->win, x, y, 0xFFFFFF);
}

// Gestion de l'événement ConfigureNotify
int handle_configure(void *param)
{
    t_data *data = (t_data *)param;

    // Récupérer les nouvelles dimensions de la fenêtre
    XWindowAttributes attrs;
    XGetWindowAttributes(XOpenDisplay(NULL), (Window)data->win, &attrs);
    data->width = attrs.width;
    data->height = attrs.height;

    // Afficher les nouvelles dimensions
    printf("New window size: width=%d, height=%d\n", data->width, data->height);

    // Redessiner le contenu
    draw_grid(data);

    return (0);
}

int main()
{
    t_data data;

    // Initialiser MiniLibX
    data.mlx = mlx_init();
    data.width = 800;
    data.height = 600;
    data.win = mlx_new_window(data.mlx, data.width, data.height, "Resizable Window");

    // Associer l'événement ConfigureNotify
    mlx_hook(data.win, 17, 0, handle_configure, &data);

    // Boucle principale
    mlx_loop(data.mlx);

    return (0);
}


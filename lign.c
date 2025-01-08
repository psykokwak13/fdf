#include "fdf.h"
#include <math.h>
void ligne(m_point pointA, m_point pointB, void *win, void *mlx)
{
    int dx = abs(pointB.x - pointA.x);
    int dy = abs(pointB.y - pointA.y);
    int sx = (pointA.x < pointB.x) ? 1 : -1;  // Direction du mouvement en x
    int sy = (pointA.y < pointB.y) ? 1 : -1;  // Direction du mouvement en y
    int err = dx - dy;  // Erreur initiale
    int e2;  // Variable pour stocker l'erreur temporaire

    while (1)
    {
        mlx_pixel_put(mlx, win, pointA.x, pointA.y, 0x3498DB);  // Place un pixel à la position (x, y)

        // Si le point actuel est le point B, on arrête
        if (pointA.x == pointB.x && pointA.y == pointB.y)
            break;

        e2 = 2 * err;

        // Correction de l'erreur pour l'axe des x
        if (e2 > -dy)
        {
            err -= dy;
            pointA.x += sx;  // Déplace le point en x
        }

        // Correction de l'erreur pour l'axe des y
        if (e2 < dx)
        {
            err += dx;
            pointA.y += sy;  // Déplace le point en y
        }
    }
}


void iso(int *x, int *y, int z)
{
	int previous_x = *x;
	int previous_y = *y;

	// Calcul des constantes
	double cos30 = cos(3.14159265358979323846 / 6); // cos(30°)
	double sin30 = sin(3.14159265358979323846 / 6); // sin(30°)

	*x = (previous_x - previous_y) * cos30;
	*y = -z + (previous_x + previous_y) * sin30;
}
// m_point	*pointSpaceInit(int x, int y, int z)
// {
// 	m_point *point;
// 	point = newpoint(x, y, z);
// 	iso(&point->x, &point->y, point->z);
// 	return (point);
// }

void traceline(m_point *pointmat,p_struct param)
{
	m_point *pointmattemp;

	pointmattemp = pointmat;
	iso(&pointmattemp->x, &pointmattemp->y, pointmattemp->colorZ.z_value);
	while (pointmattemp->next)
	{
		iso(&pointmattemp->next->x, &pointmattemp->next->y, pointmattemp->next->colorZ.z_value);
		ligne(*pointmattemp, *pointmattemp->next, param.win, param.mlx);
		pointmattemp = pointmattemp->next;
	}
}

void tracevertical(m_point *matpoint, m_point *secondmatpoint, p_struct param)
{
    int     countcols;
    m_point *matpointtemp;
    m_point *secondmatpointtemp;


    countcols = ft_lstsizempoint(matpoint);
    printf("\n-%d-\n",countcols);
    matpointtemp = matpoint;
    secondmatpointtemp = secondmatpoint;
    while (countcols > 0)
    {
        ligne(*matpointtemp, *secondmatpointtemp, param.win, param.mlx);
        matpointtemp = matpointtemp->next;
        secondmatpointtemp = secondmatpointtemp->next;
        countcols--;
    }
}

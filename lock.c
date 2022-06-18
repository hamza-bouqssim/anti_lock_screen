#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct mlx
{
	void *mlx;
	void *win_ptr;
	void *img;
	int	width;
	int height;
	int act;
} t_mlx;

int	active(void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;

	if (mlx->act == 2)
	{
		sleep(1);
		system("pmset displaysleepnow");
		exit (-42);
	}
	if (mlx->act == 1)
	{
		sleep(1);
		mlx->img = mlx_xpm_file_to_image(mlx->mlx, "./img.xpm",&mlx->width, &mlx->height);
		mlx_put_image_to_window(mlx->mlx, mlx->win_ptr, mlx->img, 0, 0);
		mlx->act = 2;
	}
	return 0;
}

int lock(int key, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	mlx->img = mlx_xpm_file_to_image(mlx->mlx, "./first.xpm",&mlx->width, &mlx->height);
	mlx_put_image_to_window(mlx->mlx, mlx->win_ptr, mlx->img, 0, 0);
	mlx->act = 1;
	return (0);
}

int	mouse_hook(int x, int y, void *param)
{
	return (lock(1, param));
}


int main()
{

	t_mlx mlx;

	mlx.act = 0;
    mlx.mlx = mlx_init();
	mlx.img = mlx_xpm_file_to_image(mlx.mlx, "./black.xpm",&mlx.width, &mlx.height);
    mlx.win_ptr = mlx_new_window(mlx.mlx, mlx.width, mlx.height, "joke on me");
	mlx_put_image_to_window(mlx.mlx, mlx.win_ptr, mlx.img, 0, 0);
    mlx_hook(mlx.win_ptr, 2, 0, lock, &mlx);
	mlx_mouse_hook(mlx.win_ptr, mouse_hook, &mlx);
	mlx_hook(mlx.win_ptr, 6, 0, mouse_hook, &mlx);
	mlx_loop_hook(mlx.mlx, active, &mlx);
    mlx_loop(mlx.mlx);
}

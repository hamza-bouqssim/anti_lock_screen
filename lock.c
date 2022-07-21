#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int lock(int key, void *walo)
{
	system("pmset displaysleepnow");
	exit (-42);
	return (0);
}

int	mouse_hook(int x, int y, void *param)
{
	return (lock(1, NULL));
}

int main()
{
    void *mlx;
    void *win_ptr;

    mlx = mlx_init();
    win_ptr = mlx_new_window(mlx, 0, 0, "joke on me");
    mlx_hook(win_ptr, 2, 0, lock, NULL);
	mlx_mouse_hook(win_ptr, mouse_hook, NULL);
	mlx_hook(win_ptr, 1, 0, lock, NULL);
	mlx_hook(win_ptr, 2, 0, lock, NULL);
	mlx_hook(win_ptr, 3, 0, lock, NULL);
	mlx_hook(win_ptr, 4, 0, lock, NULL);
	mlx_hook(win_ptr, 5, 0, lock, NULL);
	mlx_hook(win_ptr, 6, 0, mouse_hook, NULL);
    mlx_loop(mlx);
}

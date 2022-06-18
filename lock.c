/*copyright©: mjlem - asabbar*/
#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int lock(int key, void *walo)
{
	if (key == 13)
		exit(0);
    walo = NULL;
	system("open ~/Desktop/lock.app");
	system("open ~/Desktop/lock.app");
	return 0;
}

int	mouse_hook(int x, int y, void *param)
{
	param = NULL;
	system("open ~/Desktop/lock.app");
	return 0;
}

int main()
{
    void *mlx;
    void *win_ptr;

    mlx = mlx_init();
    win_ptr = mlx_new_window(mlx, 3000, 2000, "lock");
    mlx_hook(win_ptr, 2, 0, lock, NULL);
	mlx_mouse_hook(win_ptr, mouse_hook, NULL);
	mlx_hook(win_ptr, 6, 0, mouse_hook, NULL);
    mlx_loop(mlx);
}

/*copyright©: mjlem - asabbar*/
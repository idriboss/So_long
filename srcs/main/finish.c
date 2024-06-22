#include "../../includes/so_long.h"

void finish(t_data *data)
{
	static int	*frame;

	frame = 0;
	free_and_exit(NULL, EXIT_SUCCESS, data);
}

void	print_err_and_exit(const char *err, int code)
{
	if (err != NULL)
	{
		ft_putendl_fd((char *)err, STDERR_FILENO);
	}
	exit(code);
}

void	free_and_exit(const char *err, int code, t_data *data)
{
	ft_free((void **)&data->mlx);
	ft_free((void **)&data->player);
	ft_free((void **)&data);
	print_err_and_exit(err, code);
}

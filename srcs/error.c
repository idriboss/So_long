#include "../includes/so_long.h"

void	print_err_and_exit(const char *err, int code, bool errno, t_data *data)
{
	(void)data;
	if (errno == true)
	{
		perror(err);
		exit(code);
	}
	if (err != NULL)
	{
		ft_putendl_fd((char *)err, STDERR_FILENO);
	}
	exit(code);
}

void	free_and_exit(const char *err, int code, t_data *data, bool errno)
{
	print_err_and_exit(err, code, errno, data);
}

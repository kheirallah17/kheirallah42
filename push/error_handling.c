#include "swap.h"
void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
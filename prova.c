#include "fractol.h"
#include <stdio.h>

// unsigned int	ft_atoi_base(unsigned int x)
// {
// 	char *base = "0123456789ABCDEF";


// }

unsigned int	ft_colour(t_pxl x)
{
	unsigned int	colour;

	colour = 0;
	colour |= (unsigned int)(x.b);
	colour |= (unsigned int)(x.g) * (unsigned int)pow(16,2);
	colour |= (unsigned int)(x.r) * (unsigned int)pow(16,4);
	return (colour);
}

int main()
{
	t_pxl x;

	x.r = 12;
	x.g = 50;
	x.b = 135;
	int col = ft_colour(x);
	return (0);
}

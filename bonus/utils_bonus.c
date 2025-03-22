/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 01:58:50 by rel-kass          #+#    #+#             */
/*   Updated: 2025/03/20 22:06:11 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_putstr_fd(char *str, int std)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(std, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		n += 48;
		write(1, &n, 1);
	}
}

void	print_error(char *str, int fd)
{
	ft_putstr_fd(str, fd);
	exit(1);
}

void	reset_state(int *bit, char *byte, int *pos)
{
	*bit = 0;
	*pos = 0;
	*byte = 0;
}

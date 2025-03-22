/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 01:52:36 by rel-kass          #+#    #+#             */
/*   Updated: 2025/03/21 15:48:19 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	rec_cofirm(int signal)
{
	if (signal == SIGUSR1)
		ft_putstr_fd("Message recieved Succesfully\n", 1);
}

static int	extract_pid(char *str)
{
	int	pid;

	if (!is_nbr(str))
		print_error("Error: PID should be a valid number!\n", 2);
	pid = ft_atol(str);
	if (pid > INT_MAX || pid <= 0)
		print_error("Error: PID should be a positive integer!\n", 2);
	return (pid);
}

static void	send_byte(int pid, char byte)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((byte >> i) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				print_error("Error : failed to send signal!\n", 2);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				print_error("Error : failed to send signal!\n", 2);
		}
		usleep(450);
		i++;
	}
}

static void	send_msg(int pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		send_byte(pid, msg[i]);
		i++;
	}
	send_byte(pid, '\0');
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
		print_error("Error: Missing PID or message!\n", 2);
	pid = extract_pid(av[1]);
	if (!av[2][0])
		print_error("Error : The message cannot be empty!\n", 2);
	signal(SIGUSR1, rec_cofirm);
	send_msg(pid, av[2]);
}

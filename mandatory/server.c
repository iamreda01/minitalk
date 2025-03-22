/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:24:50 by rel-kass          #+#    #+#             */
/*   Updated: 2025/03/21 00:27:23 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sig_handler(int signal, siginfo_t *info, void *extra)
{
	static char	byte;
	static int	i;
	static int	prev_pid;

	(void)extra;
	if (prev_pid != info->si_pid)
	{
		prev_pid = info->si_pid;
		byte = 0;
		i = 0;
	}
	if (signal == SIGUSR1)
		byte |= (1 << i);
	i++;
	if (i > 7)
	{
		write(1, &byte, 1);
		i = 0;
		byte = 0;
	}
}

static void	init_sighand(void)
{
	struct sigaction	sig_act;

	sig_act.sa_flags = SA_SIGINFO | SA_NODEFER;
	sig_act.sa_sigaction = sig_handler;
	if (sigaction(SIGUSR1, &sig_act, NULL) == -1 || sigaction(SIGUSR2, &sig_act,
			NULL) == -1)
		print_error("Error : sigaction failed, Something went wrong\n", 2);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putstr_fd("server PID : ", 1);
	ft_putnbr(pid);
	ft_putstr_fd("\nwaiting for a message..\n", 1);
	init_sighand();
	while (1)
		pause();
	return (0);
}

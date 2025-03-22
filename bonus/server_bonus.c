/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:24:50 by rel-kass          #+#    #+#             */
/*   Updated: 2025/03/21 15:40:18 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	send_termsg(int pid)
{
	if (kill(pid, SIGUSR1) == -1)
		print_error("Failed to send signal!\n", 2);
}

static void	porcess_byte(char *buffer, int *pos, char *byte)
{
	char	lead;
	int		len;

	buffer[(*pos)++] = *byte;
	if (*pos == 1 && (*byte & 0b10000000) == 0)
	{
		write (1, buffer, 1);
		*pos = 0;
		return ;
	}
	lead = buffer[0];
	len = 0;
	if ((lead & 0b11100000) == 0b11000000)
		len = 2;
	else if ((lead & 0b11110000) == 0b11100000)
		len = 3;
	else if ((lead & 0b11111000) == 0b11110000)
		len = 4;
	if (len > 0 && *pos == len)
	{
		write (1, buffer, len);
		*pos = 0;
	}
}

static void	sig_handler(int signal, siginfo_t *info, void *extra)
{
	static char	byte;
	static int	bit;
	static int	prev_pid;
	static char	buff[4];
	static int	buff_pos;

	(void)extra;
	if (prev_pid != info->si_pid)
	{
		prev_pid = info->si_pid;
		reset_state(&bit, &byte, &buff_pos);
	}
	if (signal == SIGUSR1)
		byte |= (1 << bit);
	bit++;
	if (bit > 7)
	{
		if (byte == '\0')
			send_termsg(prev_pid);
		porcess_byte(buff, &buff_pos, &byte);
		bit = 0;
		byte = 0;
	}
}

static void	init_sighand(void)
{
	struct sigaction	sig_act;

	sig_act.sa_flags = SA_SIGINFO | SA_NODEFER;
	sig_act.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &sig_act, NULL);
	sigaction(SIGUSR2, &sig_act, NULL);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:24:29 by rel-kass          #+#    #+#             */
/*   Updated: 2025/03/20 22:07:10 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

// libs;
# include <limits.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

// utils;
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr(int n);
long	ft_atol(char *str);
int		is_nbr(char *str);
void	print_error(char *str, int fd);
void	reset_state(int *bit, char *byte, int *pos);

#endif
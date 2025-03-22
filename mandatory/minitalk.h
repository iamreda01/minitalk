/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:22:09 by rel-kass          #+#    #+#             */
/*   Updated: 2025/03/20 21:22:33 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

// libs;
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <limits.h>

// utils;
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr(int n);
long	ft_atol(char *str);
int		is_nbr(char *str);
void	print_error(char *str, int fd);

#endif
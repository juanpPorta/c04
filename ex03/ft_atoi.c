/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 03:53:36 by jporta            #+#    #+#             */
/*   Updated: 2021/07/06 10:12:49 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include <stdio.h>

int	ft_signo(char *signo)
{
	int	i;
	int	a;
	int	w;

	i = 0;
	a = 0;
	while (signo[i] != '\0')
	{
		while (signo[i] == '-' || signo[i] == '+')
		{
			while (signo[i] == 45)
			{
				a++;
				i++;
			}
			i++;
		}
		i++;
	}
	w = a % 2;
	if (w == 0)
	{
		return ('+');
	}
	return ('-');
}

int	ft_size(char *str)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (str[i] != '\0')
	{
		a++;
		i++;
	}
	return (a);
}

int	ft_atoi(char *str)
{
	int		i;
	int		size;
	int		entero;
	int		posicion;
	char	signo;

	posicion = 1;
	entero = 0;
	size = ft_size(str);
	signo = ft_signo(str);
	i = size;
	while (i <= size && i != '\t')
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			entero = entero + ((str[i] - 48) * posicion);
			posicion = posicion * 10;
			i--;
		}
		i--;
	}
	if (signo == '-')
		return (entero = entero * -1);
	else
		return (entero);
}

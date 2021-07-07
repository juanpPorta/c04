/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:18:57 by jporta            #+#    #+#             */
/*   Updated: 2021/07/07 18:43:15 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include <stdio.h>

int	check_error(char *base)
{
	char	*checkbase;
	int		i_base;

	checkbase = base;
	if (*base == 0 || *(base + 1) == 0)
		return (0);
	while (*checkbase)
	{
		if (*checkbase == '+' || *checkbase == '-' || *checkbase <= 32)
			return (0);
		i_base = 1;
		while (*(checkbase + i_base))
		{
			if (*(checkbase + i_base) == *checkbase)
				return (0);
			i_base++;
		}
		checkbase++;
	}
	return (1);
}

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

int	ft_putnbr_base(int str, char *base)
{
	int	leng;
	int	unsigned_nbr;

	if (check_error(base))
	{
		unsigned_nbr = (unsigned int)(str);
		leng = ft_size(base);
		if (unsigned_nbr >= leng)
		{
			ft_putnbr_base(unsigned_nbr / leng, base);
			ft_putnbr_base(unsigned_nbr % leng, base);
		}
		else
		{
			write(1, base + unsigned_nbr, 1);
		}
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int		size;
	int		posicion;
	int		i;
	int		entero;
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
		return (ft_putnbr_base(entero, base) * -1);
	else
		return (ft_putnbr_base(entero, base));
}

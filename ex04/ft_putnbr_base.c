/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 05:38:29 by jporta            #+#    #+#             */
/*   Updated: 2021/07/07 18:44:51 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

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

int	ft_lentbase(char *base)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (base[i] != '\0')
	{
		i++;
		a++;
	}
	return (a);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	unsigned_nbr;
	int	lenbase;

	if (check_error(base))
	{
		if (nbr < 0 && nbr != '\0')
		{
			write(1, "-", 1);
			unsigned_nbr = (unsigned int)(nbr * -1);
		}
		else
		{
			unsigned_nbr = (unsigned int)(nbr);
			lenbase = ft_lentbase(base);
			if (unsigned_nbr >= lenbase)
			{
				ft_putnbr_base(unsigned_nbr / lenbase, base);
				ft_putnbr_base(unsigned_nbr % lenbase, base);
			}
			else
			{
				write(1, base + unsigned_nbr, 1);
			}
		}
	}
}

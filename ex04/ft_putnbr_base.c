/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 05:38:29 by jporta            #+#    #+#             */
/*   Updated: 2021/07/08 15:22:21 by jporta           ###   ########.fr       */
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
	unsigned int	lenbase;
	unsigned int	nbr_unsigned;

	if (check_error(base))
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			nbr_unsigned = (unsigned int)(-1 * nbr);
		}
		else
			nbr_unsigned = (unsigned int)nbr;
		lenbase = ft_lentbase(base);
		if (nbr_unsigned >= lenbase)
		{
			ft_putnbr_base(nbr_unsigned / lenbase, base);
			ft_putnbr_base(nbr_unsigned % lenbase, base);
		}
		else
		{
			write(1, base + nbr_unsigned, 1);
		}
	}
}

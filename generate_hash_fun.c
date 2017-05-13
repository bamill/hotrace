/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_hash_fun.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 12:49:15 by bmiller           #+#    #+#             */
/*   Updated: 2017/05/13 13:21:15 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static int	next_next_prime(int n)
{
    int		next;
    int		current;

    next = 0;
    current = n % 2 == 0 ? n + 1 : n + 2;
    while (!ft_is_prime(current) || next == 0)
    {
        if (ft_is_prime(current))
            next++;
        current += 2;
    }
    return (current);
}

static int	ft_is_prime(int nb)
{
	int test;

	test = 2;
	if (nb < 2)
	{
		return (0);
	}
	if (nb == 2)
	{
		return (1);
	}
	while (((test - 1) * (test - 1)) < nb)
	{
		if ((nb % test) == 0)
		{
			return (0);
		}
		test += 1;
	}
	return (1);
}

f_hash		generate_hash_fun(int table_size)
{
    f_hash		hash_fun;
    int			a;
    int			b;
    int			p;

    p = next_next_prime(table_size);
    hash_fun = (*int)(int key, int table_size) { return
}

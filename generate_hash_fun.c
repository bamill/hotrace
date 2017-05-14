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

static int	get_random_int(int min, int max)
{
    int		rand;
    char	data[4];
    size_t	rand_len;
    int		result;
    int		res;

    rand = open("/dev/urandom", O_RDONLY);
    rand_len = 0;
    while (rand_len < sizeof data)
        {
            result = read(rand, data + rand_len, (sizeof data) - rand_len);
            if (result < 0)
                return (-1);
            rand_len += result;
        }
    close(rand);
    res = data[0];
    res += (data[1] << 8);
    res += (data[2] << 16);
    res += (data[3] << 24);
    return (res % max + min);
}

f_hash		*generate_hash_fun(int table_size)
{
    f_hash		*hash_fun;
    int			a;
    int			b;
    int			p;

    p = next_next_prime(table_size);
    a = get_random_int(1, p - 1);
    b = get_random_int(0, p - 1);
    hash_fun = (f_hash*)(malloc(sizeof(f_hash)));
    if (!hash_fun)
        return (NULL);
    *hash_fun = LAMBDA(int _(int key, int table_size) {
            return ((((a * key) + b) % p) % table_size);
        });
    return (hash_fun);
}

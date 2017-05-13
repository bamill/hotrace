/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 12:07:27 by bmiller           #+#    #+#             */
/*   Updated: 2017/05/13 12:55:13 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_hashmap
{
    int				table_size;
	t_list			**content;
    f_hash			hash_fun;
}					t_hashmap;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef int			(*f_hash)(int, int);

void				read_input(t_hashmap table);
f_hash				generate_hash_fun(int table_size);
t_hashmap			generate_hash_table(int table_size);
void				insert(char *key, char *value);
void				delete(char *key);
void				update(char *key, char *value);
void				*lookup(char *key);
void				free_table(t_hashmap table);


#endif

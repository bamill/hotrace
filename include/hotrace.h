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
# define BUFF_SIZE 32
# define MEMCHK(m) if (!m) return (-1);
# define LAMBDA(c_) ({c_ _;})
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

typedef int			(*f_hash)(int, int);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_hashmap
{
    int				table_size;
	t_list			**table;
    f_hash			hash_fun;
    t_list			*items;
    t_list			*keys;
    t_list			*values;
    int				elems;
}					t_hashmap;

size_t				ft_strlen(const char *str);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strnew(size_t size);
void				*ft_memcpy(void *dst, const void *src, size_t n);
char				*read_input(t_hashmap *map);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_bzero(void *s, size_t n);
t_list				*ft_lstcpy(t_list *lst);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_list_remove_if(t_list **begin, void *d, int (*cmp)());
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_memdel(void **ap);
int					get_next_line(const int fd, char **line);
int					div_hash(int key, int table_size);
f_hash				*generate_hash_fun(int table_size);
t_hashmap			*generate_hash_table(int table_size);
int					prehash(char *str, size_t len);
t_hashmap			*grow_table(t_hashmap *map);
t_hashmap			*shrink_table(t_hashmap *map);
void				destroy_table(t_hashmap *map);
void				insert(t_hashmap *map, char *key, char *value);
void				delet(t_hashmap *map, char *key);
char				*search(t_hashmap* map, char *key);

#endif

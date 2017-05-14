#include "hotrace.h"

static int			lst_content_cmp(t_list *content, char *key)
{
  return (ft_strcmp(content->content, key));
}

void				delet(t_hashmap *map, char *key)
{
  int		index;
  t_list	head;
  t_list	tmp;

  index = map->hash_fun(prehash(key), map->table_size);
  if (!map)
    return ;
  if (map->elems <= map->table_size / 4)
    map = shrink_table(map);
  if (!(map->table[index]))
    return ;
  else if (ft_strcmp(key, map->table[index]->content->content))
    {
      head = map->table[index];
      while (map->table[index]->next && ft_strcmp(key, map->table[index]->next->content))
        map->table[index] = map->table[index]->next;
      if (map->table[index]->next)
        {
          tmp = map->table[index]->next->next ? map->table[index]->next->next : NULL;
          map->table[index]->next->next = NULL;
          ft_lst_remove_if(&map->values, map->table[index]->next->content->next->content, ft_strcmp);
          ft_lstdel(&(map->table[index]->next), ft_bzero);
          map->table[index]->next = tmp;
        }
      map->table[index] = head;
    }
  else
    {
      tmp = map->table[index]->next ? map->table[index]->next : NULL;
      map->table[index]->next = NULL;
      ft_lst_remove_if(&map->values, map->table[index]->content->next->content, ft_strcmp);
      ft_lstdel(&(map->table[index]));
      map->table[index] = tmp;
    }
  ft_lst_remove_if(&map->keys, key, ft_strcmp);
  ft_lst_remove_if(&map->items, key, lst_content_cmp);
  map->elems--;
}

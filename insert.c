#include "hotrace.h"

void		insert(t_hashmap *map, char *key, char *value)
{
  int		index;
  t_list	*list;
  t_list	*head;
  t_list	*rest;

  index = map->hash_fun(prehash(key), map->table_size);
  list = ft_lstnew(key, sizeof key);
  list->next = ft_lstnew(value, sizeof value);
  if (!map)
    return (NULL);
  if (map->elems == map->table_size)
    map = grow_table(map);
  if (!((map->table)[index]))
      (map->table)[index] = ft_lstnew(list, sizeof list);
  else if (ft_strcmp(key, map->table[index]->content->content))
    {
      head = map->table[index];
      while (map->table[index]->next && ft_strcmp(key, map->table[index]->next->content))
        map->table[index] = map->table[index]->next;
      rest = map->table[index]->next ? map->table[index]->next->next : NULL;
      map->table[index]->next = ft_lstnew(list, sizeof list);
      map->table[index]->next->next = rest;
      map->table[index] = head;
    }
  else
    {
      rest = map->table[index]->next ? map->table[index]->next : NULL;
      map->table[index] = ft_lstnew(list, sizeof list);
      map->table[index]->next = rest;
    }
  ft_lstadd(map->keys, ft_lstnew(key, sizeof key));
  ft_lstadd(map->values, ft_lstnew(value, sizeof value));
  ft_lstadd(map->items, ft_lstnew(list, sizeof list));
  map->elems++;
}

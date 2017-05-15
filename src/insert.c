#include "hotrace.h"

void		insert(t_hashmap *map, char *key, char *value)
{
  int		index;
  t_list	*list;
  t_list	*head;
  t_list	*rest;

  index = map->hash_fun(prehash(key, ft_strlen(key)), map->table_size);
  list = ft_lstnew(key, ft_strlen(key) + 1);
  list = ft_lstnew(list, sizeof(t_list));
  ((t_list*)list->content)->next = ft_lstnew(value, ft_strlen(value) +1);
  if (!map)
    return ;
  if (map->elems == map->table_size)
    map = grow_table(map);
  if (search(map, key) == NULL)
      (map->table)[index] = list;
  else if (ft_strcmp(key, ((t_list*)(map->table[index]->content))->content))
    {
      head = map->table[index];
      while (map->table[index]->next && ft_strcmp(key, ((t_list*)map->table[index]->next->content)->content))
        map->table[index] = map->table[index]->next;
      rest = map->table[index]->next ? map->table[index]->next->next : NULL;
      map->table[index]->next = list;
      map->table[index]->next->next = rest;
      map->table[index] = head;
    }
  else
    {
      rest = map->table[index]->next ? map->table[index]->next : NULL;
      map->table[index] = list;
      map->table[index]->next = rest;
    }
  ft_lstadd(&map->keys, ft_lstnew(key, ft_strlen(key) + 1));
  ft_lstadd(&map->values, ft_lstnew(value, ft_strlen(value) + 1));
  ft_lstadd(&map->items, list);
  map->elems++;
}

#include "hotrace.h"

void		destroy_table(t_hashmap *map)
{
  t_list	*head;

  if (!map)
    return ;
  head = map->keys;
  while (map->keys)
    {
      ft_lstdel(&map->table[map->hash_fun(prehash(map->keys->content, ft_strlen(map->keys->content)), map->table_size)], ft_bzero);
      map->keys = map->keys->next;
    }
  map->keys = head;
  ft_lstdel(&map->keys, ft_bzero);
  ft_lstdel(&map->values, ft_bzero);
  ft_lstdel(&map->items, ft_bzero);
  ft_memdel((void**)map->table);
  ft_memdel((void**)&map);
}

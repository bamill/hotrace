#include "hotrace.h"

void		destroy_table(t_hashmap *map)
{
  t_list	*head;

  if (!map)
    return (NULL);
  head = map->keys;
  while (map->keys)
    {
      ft_lstdel(map->table[map->hash_fun(prehash(map->keys->content))]);
      map->keys = map->keys->next;
    }
  map->keys = head;
  ft_lstdel(map->keys);
  ft_lstdel(map->values);
  ft_lstdel(map->items);
  ft_memdel(map->table);
  ft_memdel(&map);
}

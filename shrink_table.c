#include "hotrace.h"

t_hashmap			*shrink_table(t_hashmap *map)
{
  t_hashmap			*new;

  new = generate_hash_table(map->table_size / 2);
  new->items = ft_lstcpy(map->items);
  new->keys = ft_lstcpy(map->keys);
  new->values = ft_lstcpy(map->values);
  while (map->keys)
    {
      insert(new, map->keys->content, search(map, map->keys->content));
      map->keys = map->keys->next;
    }
  destroy_table(map);
  return (new);
}

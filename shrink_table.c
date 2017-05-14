#include "hotrace.h"

t_hashmap			*shrink_table(t_hashmap *map)
{
  t_hashmap			*new;

  new = generate_hash_table(map->table_size / 2);
  new->items = ft_lstcpy(map->items);
  new->keys = ft_lstcpy(map->keys);
  new->values = ft_lstcpy(map->values);
  while (map->values)
    {
      insert(map->values->content, map->values->content->next->content);
      map->values = map->values->next;
    }
  destroy_table(map);
  return (new);
}

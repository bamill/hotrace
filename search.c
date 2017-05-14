#include "hotrace.h"

char				*search(t_hashmap* map, char *key)
{
  int		index;
  t_list	*head;
  char		*res;

  if (!key || !map)
    return (NULL);
  index = map->hash_fun(prehash(key, ft_strlen(key)), map->table_size);
  if (!(map->table[index]))
    return (NULL);
  head = map->table[index];
  while (map->table[index])
    {
      if (!(ft_strcmp(key, map->table[index]->content->content)))
        {
          res = map->table[index]->content->next->content;
          map->table[index] = head;
          return (res);
        }
      map->table[index] = map->table[index]->next;
    }
  return (NULL);
}

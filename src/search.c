#include "hotrace.h"

char				*search(t_hashmap* map, char *key)
{
  int		index;
  t_list	*head;
  char		*res;

  if (!key || !map)
    return (NULL);
  index = map->hash_fun(prehash(key, ft_strlen(key)), map->table_size);
  if (map->table[index] == NULL)
    return (NULL);
  head = map->table[index];
  while (head != map->table[index] && map->table[index]->next != NULL)
    {
      if (!(ft_strcmp(key, ((t_list*)(map->table[index]->content))->content)))
        {
          res = ((t_list*)map->table[index]->content)->next->content;
          map->table[index] = head;
          return (res);
        }
      map->table[index] = map->table[index]->next;
    }
  return (NULL);
}

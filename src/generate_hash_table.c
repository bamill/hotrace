#include "hotrace.h"

t_hashmap			*generate_hash_table(int table_size)
{
  t_hashmap		*map;
  t_list		**buckets;

  map = (t_hashmap*)(malloc(sizeof(t_hashmap)));
  map->table_size = table_size;
  map->hash_fun = &div_hash; //generate_hash_fun(table_size);
  if (!map->hash_fun)
    return (NULL);
  buckets = (t_list**)(malloc(sizeof(t_list*) * table_size));
  if (!buckets)
    return (NULL);
  map->table = buckets;
  return (map);
}

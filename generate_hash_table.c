#include "hotrace.h"

t_hashmap			*generate_hash_table(int table_size)
{
  t_hashmap		*map;
  t_list		**buckets;

  map->table_size = table_size;
  map->hash_fun = generate_hash_fun(table_size);
  buckets = (t_list**)(malloc(sizeof(t_list*) * table_size));
  if (!buckets)
    return (NULL);
  map->table = buckets;
  return (map);
}

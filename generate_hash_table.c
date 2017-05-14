#include "hotrace.h"

static int			div_hash(int key, int table_size)
{
  return (key % table_size);
}

t_hashmap			*generate_hash_table(int table_size)
{
  t_hashmap		*map;
  t_list		**buckets;

  map = (t_hashmap*)(malloc(sizeof(t_hashmap)));
  map->table_size = table_size;
  map->hash_fun = (f_hash*)div_hash; //generate_hash_fun(table_size);
  buckets = (t_list**)(malloc(sizeof(t_list*) * table_size));
  if (!buckets)
    return (NULL);
  map->table = buckets;
  return (map);
}

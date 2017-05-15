#include "hotrace.h"
#include <stdio.h>

int		main()
{
  char			*ret;
  t_hashmap		*map;

  map = generate_hash_table(8);
  ret = read_input(map);
  printf("%s", ret);
  destroy_table(map);
  return (0);
}

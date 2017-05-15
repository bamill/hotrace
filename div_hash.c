#include "hotrace.h"

int			div_hash(int key, int table_size)
{
  return (key % table_size);
}

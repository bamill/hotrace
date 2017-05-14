#include "hotrace.h"

int			prehash(char *str, size_t len)
{
  int	result;
  int	counter;


  if (!str)
    return (0);
  counter = 0;
  result = 0;
  while (counter++ < len)
    result += str[counter];
  return (result);
}

#include "hotrace.h"

char		*read_input(t_hashmap *map)
{
  char		**line;
  int		counter;
  char		*key;
  char		*value;
  int		q_mode;

  line = (char**)(malloc(sizeof(char*)));
  counter = 0;
  q_mode = 0;
  while (get_next_line(0, line) > 0)
    {
      if (!(*line))
        {
          q_mode++;
          value = NULL;
        }
      if (!q_mode)
        {
          if (counter % 2)
            key = ft_strdup(*line);
          else
            {
              value = ft_strdup(*line);
              insert(map, key, value);
            }
        }
      else
        {
          key = value;
          value = ft_strjoin(value, search(map, *line));
          free(key);
          key = NULL;
        }
      counter++;
    }
  ft_memdel((void**)line);
  return (value);
}

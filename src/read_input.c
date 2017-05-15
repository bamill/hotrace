#include "hotrace.h"

char		*read_input(t_hashmap *map)
{
  char		**line;
  int		counter;
  int		status;
  char		*key;
  char		*value;
  int		q_mode;

  line = (char**)(malloc(sizeof(char*) * 2));
  counter = 0;
  q_mode = 0;
  while ((status = get_next_line(0, line)) > 0)
    {
      if (!(**line))
        {
          q_mode++;
          value = NULL;
        }
      if (q_mode == 0)
        {
          if (counter % 2 == 0)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 13:02:29 by ybouzgao          #+#    #+#             */
/*   Updated: 2018/03/08 15:00:38 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int ac, char **av)
{
	char 	*line;
	int 	fd;

	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ft_putendl(line);
		if (line)
			free(line);
	}
	return (0);
}

/*int				main(void)
  {
  char		*line;
  int			fd;
  int			ret;
  int			count_lines;
  char		*filename;
  int			errors;

  filename = "gnl7_1.txt";
  fd = open(filename, O_RDONLY);
  if (fd > 2)
  {
  count_lines = 0;
  errors = 0;
  line = NULL;
  while ((ret = get_next_line(fd, &line)) > 0)
  {
  if (count_lines == 0 && strcmp(line, "12345678") != 0)
  errors++;
  count_lines++;
  if (count_lines > 50)
  break ;
  }
  close(fd);
  if (count_lines != 1)
  printf("-> must have returned '1' once instead of %d time(s)\n", count_lines);
  if (errors > 0)
  printf("-> must have read \"12345678\" instead of \"%s\"\n", line);
  if (count_lines == 1 && errors == 0)
  printf("OK\n");
  }
  else
  printf("An error occured while opening file %s\n", filename);
  return (0);
  }

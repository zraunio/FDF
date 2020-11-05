#include "fdf.h"

int		valid_file(char *file)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY, 0);
	while (get_next_line(fd, &line))
	{
		while (line[i])
		{
			if (ft_isdigit(line[i]) == 0 &&
			line[i] != '-' && ft_isspace(line[i]) == 0)
				return (0);
			else
				i++;
		}
	}
	return (1);
}
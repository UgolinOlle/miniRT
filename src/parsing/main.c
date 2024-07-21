/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:46:44 by arturo            #+#    #+#             */
/*   Updated: 2024/07/22 01:33:16 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	parsing(t_pars **pars, char *line)
{
	if (line == NULL || line[0] == '\0' || line[0] == '#')
		return ;
	else if (line[0] == 'C')
		add_cam_parsing(pars, line);
	else if (line[0] == 's' && line[1] == 'p')
		add_sphere_parsing(pars, line);
	else if (line[0] == 'p' && line[1] == 'l')
		add_plane_parsing(pars, line);
	else if (line[0] == 'c' && line[1] == 'y')
		add_cylinder_parsing(pars, line);
	else if (line[0] == 'A')
		add_amb_light_parsing(pars, line);
	else if (line[0] == 'L')
		add_dif_light_parsing(pars, line);
	else if (line[0] == 'S')
		add_spec_light_parsing(pars, line);
	else
		fprintf(stderr, "Error: Unknown identifier\n");
}

void	parse_file(const char *filename, t_pars **pars)
{
	int		fd;
	char	*line;
	int		tmp;

	fd = open(filename, O_RDONLY);
	tmp = 0;
	if (fd < 0)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	while (tmp != 1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		parsing(pars, line);
		free(line);
	}
	close(fd);
}

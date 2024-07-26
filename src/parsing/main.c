/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:46:44 by arturo            #+#    #+#             */
/*   Updated: 2024/07/26 15:56:32 by uolle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ft_parsing_check(t_pars **pars, char *line)
{
	if (line[0] == 's' && line[1] != 'p' && (line[2] != ' '
				&& line[2] == '\t'))
		pars_error("Error: Invalid identifier 2\n", pars);
	else if (line[0] == 'p' && line[1] != 'l' && (line[2] != ' '
				&& line[2] == '\t'))
		pars_error("Error: Invalid identifier 3\n", pars);
	else if (line[0] == 'c' && line[1] != 'y' && (line[2] != ' '
				&& line[2] == '\t'))
		pars_error("Error: Invalid identifier 4\n", pars);
	else if (!ft_isalpha(line[0]) && line[1] != ' ' && line[1] != '\t')
		pars_error("Error: Invalid identifier 1\n", pars);
}

static void	parsing(t_pars **pars, char *line)
{
	if (line == NULL || line[0] == '\0' || line[0] == '#' || line[0] == '\n')
		return ;
	ft_parsing_check(pars, line);
	if (line[0] == 'C')
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
		return ;
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

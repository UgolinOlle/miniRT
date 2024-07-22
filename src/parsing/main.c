/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:46:44 by arturo            #+#    #+#             */
/*   Updated: 2024/07/22 13:01:04 by uolle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ft_print_vec(t_vec vec)
{
	printf("x: %.2f, y: %.2f, z: %.2f\n", vec[0], vec[1], vec[2]);
}

static void	ft_print_pars_debug(t_pars *pars)
{
	while (pars)
	{
		printf("Element type: %d\n", pars->element.type);
		printf("Orientation: ");
		ft_print_vec(pars->element.orientation);
		printf("Center: ");
		ft_print_vec(pars->element.center);
		printf("Color (range 0-255): ");
		ft_print_vec(pars->element.color_range255);
		printf("Brightness: %.2f\n", pars->element.brightness);
		printf("Shine: %.2f\n", pars->element.shine);
		printf("FOV in degrees: %.2f\n", pars->element.fov_in_deg);
		printf("Diameter: %.2f\n", pars->element.diameter);
		printf("Height: %.2f\n", pars->element.height);
		printf("\n");
		pars = pars->next;
	}
}

static void	parsing(t_pars **pars, char *line)
{
	printf("line: %s\n", line);
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
	ft_print_pars_debug(*pars);
	close(fd);
}

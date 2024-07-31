/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:46:44 by arturo            #+#    #+#             */
/*   Updated: 2024/08/01 00:31:29 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ft_parsing_check(t_pars **pars, char *line)
{
	if (line[0] == 's' && line[1] != 'p' && (line[2] != ' ' && line[2] == '\t'))
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

static void	ft_parsing_values(t_pars **pars, char *line)
{
	int		expected_values;
	int		count;
	char	*tmp;
	char	*token;

	tmp = ft_strdup(line);
	expected_values = 0;
	if (line[0] == 'C' || line[0] == 'L' || (line[0] == 's' && line[1] == 'p'))
		expected_values = 7;
	else if (line[0] == 'p' && line[1] == 'l')
		expected_values = 9;
	else if (line[0] == 'c' && line[1] == 'y')
		expected_values = 11;
	else if (line[0] == 'A')
		expected_values = 4;
	count = -1;
	token = ft_strtok(tmp, " \t,");
	while (token != NULL)
	{
		count++;
		token = ft_strtok(NULL, " \t,");
	}
	if (count != expected_values)
		pars_error("Error: Invalid number of values.\n", pars);
}

static void	ft_multiple_tok_check(t_pars **pars, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ',' && str[i] != '.' && str[i] != '+'\
		&& str[i] != '-' && ++i > 0)
			continue ;
		if (str[i] == ',')
		{
			while (str[++i] && !ft_isdigit(str[i]))
				if (str[i] != ' ' && str[i] != '\t' \
				&& str[i] != '+' && str[i] != '-')
					pars_error("Error: incorrect character (1)\n", pars);
		}
		else if ((str[i] == '+' || str[i] == '-' || str[i] == '.') && \
		(!str[i + 1] || !ft_isdigit(str[i + 1])))
			pars_error("Error: incorrect character (2)\n", pars);
		else if ((str[i] == '+' || str[i] == '-') && (i == 0 || \
		(str[i - 1] != ' ' && str[i - 1] != '\t' && str[i - 1] != ',')))
			pars_error("Error: incorrect character (3)\n", pars);
		else if (str[i] == '.' && (i == 0 || !ft_isdigit(str[i - 1])))
			pars_error("Error: incorrect character (4)\n", pars);
		i++;
	}
}

static void	parsing(t_pars **pars, char *line)
{
	if (line == NULL || line[0] == '\0' || line[0] == '#' || line[0] == '\n')
		return ;
	ft_multiple_tok_check(pars, line);
	ft_parsing_check(pars, line);
	ft_parsing_values(pars, line);
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

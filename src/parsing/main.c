/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:46:44 by arturo            #+#    #+#             */
/*   Updated: 2024/05/30 12:58:29 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void parse_file(char *file, t_pars **scene)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;

    fp = fopen(file, "r");
    if (fp == NULL)
        exit_error("Error\nUnable to open file\n");
    while (getline(&line, &len, fp) != -1)
    {
        parse_line(line, scene);
        free(line);
        line = NULL;
    }
    fclose(fp);
}

static void parse_line(char *line, t_pars **scene)
{
    char **split;

    split = ft_split(line, ' ');
    if (strcmp(split[0], "A") == 0)
        add_ambient_light(split, scene);
    else if (strcmp(split[0], "C") == 0)
        add_camera(split, scene);
    else if (strcmp(split[0], "L") == 0)
        add_light(split, scene);
    else if (strcmp(split[0], "sp") == 0)
        add_sphere(split, scene);
    else if (strcmp(split[0], "pl") == 0)
        add_plane(split, scene);
    else if (strcmp(split[0], "cy") == 0)
        add_cylinder(split, scene);
    else
        exit_error("Error\nUnknown identifier\n");
    free_split(split);
}

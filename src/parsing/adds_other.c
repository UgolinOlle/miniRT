/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:46:44 by arturo            #+#    #+#             */
/*   Updated: 2024/05/30 12:12:26 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void add_sphere(char **split, t_pars **scene)
{
    t_elem elem;

    elem.type = SPHERE;
    elem.center = vec_parse(split[1]);
    elem.diameter = parse_float(split[2]);
    elem.color_range255 = vec_parse(split[3]);
    add_element(scene, elem);
}

void add_plane(char **split, t_pars **scene)
{
    t_elem elem;

    elem.type = PLANE;
    elem.center = vec_parse(split[1]);
    elem.orientation = vec_parse(split[2]);
    elem.color_range255 = vec_parse(split[3]);
    add_element(scene, elem);
}

void add_cylinder(char **split, t_pars **scene)
{
    t_elem elem;

    elem.type = CYLINDER;
    elem.center = vec_parse(split[1]);
    elem.orientation = vec_parse(split[2]);
    elem.diameter = parse_float(split[3]);
    elem.height = parse_float(split[4]);
    elem.color_range255 = vec_parse(split[5]);
    add_element(scene, elem);
}

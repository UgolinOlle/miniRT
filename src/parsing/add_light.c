/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:07:41 by arturo            #+#    #+#             */
/*   Updated: 2024/05/31 08:17:27 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void add_light(char **split, t_pars **scene)
{
    t_elem elem;

    elem.type = LIGHT_H
    elem.center = vec_parse(split[1]);
    elem.brightness = parse_float(split[2]);
    elem.color_range255 = vec_parse(split[3]);
    add_element(scene, elem);
}

void add_ambient_light(char **split, t_pars **scene)
{
    t_elem elem;

    elem.type = AMBIENT;
    elem.brightness = parse_float(split[1]);
    elem.color_range255 = vec_parse(split[2]);
    add_element(scene, elem);
}

void add_camera(char **split, t_pars **scene)
{
    t_elem elem;

    elem.type = CAMERA;
    elem.center = vec_parse(split[1]);
    elem.orientation = vec_parse(split[2]);
    elem.fov_in_deg = parse_float(split[3]);
    add_element(scene, elem);
}


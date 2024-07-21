/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:11:41 by arturo            #+#    #+#             */
/*   Updated: 2024/05/30 13:10:12 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "header.h"

# define CAMERA 0

typedef struct s_elem
{
	int		type;
	t_vec	orientation;
	t_vec	center;
	t_vec	color_range255;
	float	brightness;
	float	shine;
	float	fov_in_deg;
	float	diameter;
	float	height;
}		t_elem;

typedef struct s_pars
{
	t_elem			element;
	struct s_pars	*next;
}		t_pars;

// -- Main
void parse_file(char *file, t_pars **scene);

// -- Utils
// void	add_element_to_pars_list(t_elem elem, t_pars **pars)

// -- Add light
void add_light(char **split, t_pars **scene);
void add_ambient_light(char **split, t_pars **scene);
void add_camera(char **split, t_pars **scene);

// -- Add other
void add_sphere(char **split, t_pars **scene);
void add_plane(char **split, t_pars **scene);
void add_cylinder(char **split, t_pars **scene);

// t_vec vec_parse(char *s);
// float parse_float(char *s);
// int parse_int(char *s);
// void add_element(t_pars **scene, t_elem elem);
// void exit_error(const char *message);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:11:41 by arturo            #+#    #+#             */
/*   Updated: 2024/07/21 21:17:04 by uolle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "header.h"

# define CAMERA 0

typedef struct s_elem
{
	int				type;
	t_vec			orientation;
	t_vec			center;
	t_vec			color_range255;
	float			brightness;
	float			shine;
	float			fov_in_deg;
	float			diameter;
	float			height;
}					t_elem;

typedef struct s_pars
{
	t_elem			element;
	struct s_pars	*next;
}					t_pars;

// -- Main
void				parse_file(const char *filename, t_pars **pars);

// -- Add light
void				add_amb_light_parsing(t_pars **pars, char *line);
void				add_dif_light_parsing(t_pars **pars, char *line);
void				add_spec_light_parsing(t_pars **pars, char *line);

// -- Add other
void				add_cam_parsing(t_pars **pars, char *line);
void				add_cylinder_parsing(t_pars **pars, char *line);
void				add_sphere_parsing(t_pars **pars, char *line);
void				add_plane_parsing(t_pars **pars, char *line);

// -- Add utils
void				ft_parse_vector(char *str, t_vec vec);
void				ft_split_tokens(char *line, char *tokens[], int max_tokens);
void				add_element_to_pars_list(t_elem elem, t_pars **pars);
char				*ft_strtok(char *str, const char *delim);

#endif

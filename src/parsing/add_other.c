/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_other.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:38:31 by uolle             #+#    #+#             */
/*   Updated: 2024/07/22 01:33:59 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	add_cam_parsing(t_pars **pars, char *line)
{
	t_elem	elem;
	float	len;
	char	*tokens[7];

	elem.type = CAMERA;
	ft_split_tokens(line + 2, tokens, 7);
	if (tokens[0])
		ft_parse_vector(&tokens[0], elem.center);
	else
		fprintf(stderr, "Error: Missing camera center\n");
	if (tokens[3])
	{
		ft_parse_vector(&tokens[3], elem.orientation);
		len = sqrtf(dot_product(elem.orientation, elem.orientation));
		if (len > 1 + EPSILON || len < 1 - EPSILON)
		{
			printf("Camera orientation not normalised (%f)\n", len);
			exit(2);
		}
	}
	else
		fprintf(stderr, "Error: Missing camera orientation\n");
	if (tokens[5])
		elem.fov_in_deg = ft_atoi(tokens[5]);
	else
		fprintf(stderr, "Error: Missing camera field of view\n");
	if (elem.fov_in_deg < 0 + EPSILON)
		elem.fov_in_deg += EPSILON;
	if (elem.fov_in_deg > 180 - EPSILON)
		elem.fov_in_deg -= EPSILON;
	add_element_to_pars_list(elem, pars);
}

// CYLINDER
// cy 0,0,0 0,0,1 2 3 0,255,0
void	add_cylinder_parsing(t_pars **pars, char *line)
{
	t_elem	elem;
	float	len;
	char	*tokens[11];

	elem.type = CYLINDER;
	ft_split_tokens(line + 3, tokens,11);
	ft_parse_vector(&tokens[0], elem.center);
	ft_parse_vector(&tokens[3], elem.orientation);
	len = sqrtf(dot_product(elem.orientation, elem.orientation));
	if (len > 1 + EPSILON || len < 1 - EPSILON)
	{
		printf("Cylinder orientation not normalised (%f)\n", len);
		exit(2);
	}
	elem.diameter = ft_atof(tokens[6]);
	elem.height = ft_atof(tokens[7]);
	create_tupple(&elem.color_range255, ft_atoi(tokens[8]),
		ft_atoi(tokens[9]), ft_atoi(tokens[10]));
	add_element_to_pars_list(elem, pars);
}

// SPHERE
// sp 2,0,0 5 0,0,255
void	add_sphere_parsing(t_pars **pars, char *line)
{
	t_elem	elem;
	char	*tokens[7];

	elem.type = SPHERE;
	ft_split_tokens(line + 3, tokens, 7);
	ft_parse_vector(&tokens[0], elem.center);
	elem.diameter = ft_atof(tokens[3]);
	create_tupple(&elem.color_range255, ft_atoi(tokens[4]),
		ft_atoi(tokens[5]), ft_atoi(tokens[6]));
	add_element_to_pars_list(elem, pars);
}

// PLANE
// pl 0,0,-20 0,0,1 255,255,255
void	add_plane_parsing(t_pars **pars, char *line)
{
	t_elem	elem;
	float	len;
	char	*tokens[9];

	elem.type = PLANE;
	ft_split_tokens(line + 3, tokens, 9);
	ft_parse_vector(&tokens[0], elem.center);
	ft_parse_vector(&tokens[3], elem.orientation);
	len = sqrtf(dot_product(elem.orientation, elem.orientation));
	if (len > 1 + EPSILON || len < 1 - EPSILON)
	{
		printf("Plane orientation not normalised (%f)\n", len);
		exit(2);
	}
	create_tupple(&elem.color_range255, ft_atoi(tokens[6]),
		ft_atoi(tokens[7]), ft_atoi(tokens[8]));
	add_element_to_pars_list(elem, pars);
}

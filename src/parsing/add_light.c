/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:41:01 by uolle             #+#    #+#             */
/*   Updated: 2024/07/21 21:41:01 by uolle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	add_amb_light_parsing(t_pars **pars, char *line)
{
	t_elem	elem;
	char	*tokens[2];
	char	*color_tokens[3];

	elem.type = AMBIENT;
	ft_split_tokens(line + 2, tokens, 2);
	elem.brightness = ft_atof(tokens[0]);
	ft_split_tokens(tokens[1], color_tokens, 3);
	create_tupple(&elem.color_range255, ft_atoi(color_tokens[0]),
		ft_atoi(color_tokens[1]), ft_atoi(color_tokens[2]));
	add_element_to_pars_list(elem, pars);
}

// DIFFUSE LIGHT
// L 6 0 0 0.6 255 255 255
void	add_dif_light_parsing(t_pars **pars, char *line)
{
	t_elem	elem;
	char	*tokens[5];
	char	*color_tokens[3];

	elem.type = DIFFUSE;
	ft_split_tokens(line + 2, tokens, 5);
	ft_parse_vector(tokens[0], elem.center);
	elem.brightness = ft_atof(tokens[1]);
	ft_split_tokens(tokens[2], color_tokens, 3);
	create_tupple(&elem.color_range255, ft_atoi(color_tokens[0]),
		ft_atoi(color_tokens[1]), ft_atoi(color_tokens[2]));
	add_element_to_pars_list(elem, pars);
}

// SPECULAR LIGHT
// S 1.0 200.0
void	add_spec_light_parsing(t_pars **pars, char *line)
{
	t_elem	elem;
	char	*tokens[2];

	elem.type = SPECULAR;
	ft_split_tokens(line + 2, tokens, 2);
	elem.brightness = ft_atof(tokens[0]);
	elem.shine = ft_atof(tokens[1]);
	add_element_to_pars_list(elem, pars);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:33:59 by arturo            #+#    #+#             */
/*   Updated: 2024/07/23 14:48:35 by uolle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	check_limit_color(t_vec value, t_pars **pars)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if (value[i] < 0.00f || value[i] > 255.0f)
			pars_error("Colors need to be within range [0-255]\n", pars);
	}
}

void	check_limit_value(int type, float value, t_pars **pars)
{
	if (type == CAMERA && (value < 0 || value > 180))
		pars_error("Camera fov needs to be between 0 and 180\n", pars);
	else if (type == SPECULAR && (value < 0 || value > 250))
		pars_error("Light specular shine needs to be between 0 and 250\n",
			pars);
	else if (type == -42 && (value < 0 || value > 1))
		pars_error("Light brigthness needs to be between 0 and 1\n", pars);
}

void	pars_error(char *error_message, t_pars **par)
{
	t_pars	*temp;
	int		i;

	i = -1;
	while (error_message && error_message[++i])
		write(2, &error_message[i], 1);
	if (par == NULL)
		exit(EXIT_FAILURE);
	while (*par)
	{
		temp = *par;
		free(*par);
		*par = temp->next;
	}
	exit(EXIT_FAILURE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:33:59 by arturo            #+#    #+#             */
/*   Updated: 2024/07/22 17:48:01 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_limit_color(t_vec value)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if (value[i]  < 0.00f || value[i] > 255.0f)
		{
			perror("Colors need to be within range [0-255]");
			return (0);
		}
	}
	return (1);
}

int	check_limit_value(float upper, float lower, int type, float value)
{
	if (value < upper && value > lower)
		return (1);
	else if (type == CAMERA)
		perror("Camera fov needs to be between 0 and 180\n");
	else if (type == SPECULAR)
		perror("Light specular shine needs to be between 0 and 250\n");
	else
		perror("Light brigthness needs to be between 0 and 1\n");
	return (0);
}
	
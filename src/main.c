/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:36:04 by arturo            #+#    #+#             */
/*   Updated: 2024/05/31 08:38:31 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(int argc, char **argv) 
{
	t_mlx	mlx;
	t_pars	*pars;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <scene.rt>\n", argv[0]);
        return (1);
    }

	initialize_mlx(&mlx);
	pars = NULL;
    parse_file(argv[1], &pars);
	lexer(&mlx, pars);
	init_scene(&mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.image.img, 0, 0);
	mlx_loop(mlx.mlx);
	clean(&mlx);
	return (0);
}

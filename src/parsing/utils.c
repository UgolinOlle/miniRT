/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:11:47 by uolle             #+#    #+#             */
/*   Updated: 2024/07/21 18:25:36 by uolle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	*ft_find_next_token(char *str, const char *delim)
{
	while (*str && ft_strchr(delim, *str))
		str++;
	if (*str)
		return (str);
	else
		return (NULL);
}

void	add_element_to_pars_list(t_elem elem, t_pars **pars)
{
	t_pars	*list;
	t_pars	*new;

	new = malloc(sizeof(t_pars));
	if (!new)
	{
		printf("malloc error\n");
		return ;
	}
	new->element = elem;
	new->next = NULL;
	list = *pars;
	if (*pars == NULL)
		*pars = new;
	else
	{
		while (list->next)
			list = list->next;
		list->next = new;
	}
}

void	ft_parse_vector(char *str, t_vec vec)
{
	char	*token;

	token = ft_strtok(str, ",");
	vec[0] = ft_atof(token);
	token = ft_strtok(NULL, ",");
	vec[1] = ft_atof(token);
	token = ft_strtok(NULL, ",");
	vec[2] = ft_atof(token);
}

void	ft_split_tokens(char *line, char *tokens[], int max_tokens)
{
	int	i;

	i = 0;
	tokens[i++] = ft_strtok(line, " ");
	while (i < max_tokens)
	{
		tokens[i] = ft_strtok(NULL, " ");
		if (tokens[i] == NULL)
			break ;
		i++;
	}
}

char	*ft_strtok(char *str, const char *delim)
{
	static char	*static_str;
	char		*token;

	if (str)
		static_str = str;
	static_str = ft_find_next_token(static_str, delim);
	if (!static_str)
		return (NULL);
	token = static_str;
	while (*static_str && !ft_strchr(delim, *static_str))
		static_str++;
	if (*static_str)
	{
		*static_str = '\0';
		static_str++;
	}
	else
		static_str = NULL;
	return (token);
}

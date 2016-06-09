/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths_vars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 15:19:57 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/09 15:19:59 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_paths_vars(t_list *env_l)
{
	char	**path;
	char	*tmp;

	path = NULL;
	tmp = NULL;
	while (env_l)
	{
		if (ft_strstr(((t_shell*)(env_l->content))->str, "PATH="))
			break;
		env_l = env_l->next;
	}
	if (!(tmp = ft_strsub(((t_shell*)(env_l->content))->str, 5,
		ft_strlen(((t_shell*)(env_l->content))->str) - 5)))
		return (NULL);
	if (!(path = ft_strsplit(tmp, ':')))
	{
		free(tmp);
		return (NULL);
	}
	return (path);
}

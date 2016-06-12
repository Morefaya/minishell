/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_a_pwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 14:11:09 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/12 14:51:08 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_stop(char *pwd)
{
	int		len;
	int		i;

	len = ft_strlen(pwd);
	i = len;
	if (pwd[i] == '/')
		i--;
	while (i >= 0)
	{
		if (pwd[i] == '/')
			break ;
		i--;
	}
	if (!i)
		i++;
	return (i);
}

char		*get_a_pwd(void)
{
	char	*pwd;
	int		stop;
	char	*a_pwd;

	if (!(pwd = get_pwd()))
		return (NULL);
	if (!ft_strcmp(pwd, "/"))
		return (ft_strdup("/"));
	if (!(stop = get_stop(pwd)))
		return (NULL);
	if (!(a_pwd = ft_strsub(pwd, 0, stop)))
		return (NULL);
	return (a_pwd);
}

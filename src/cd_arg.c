/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 12:28:13 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/03 12:29:40 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/stat.h>

static int	check_opt(char *str, int *opt)
{
	if (!str)
		return (0);
	if (*str != '-')
		return (0);
	str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str == 'P')
			*opt = 1;
		else if (!ft_check_charset(*str, "PL"))
			*opt = -1;
		str++;
	}
	return (1);
}

static char	*not_in_pwd(char **cd_split, int i)
{
	ft_putstr("cd: string not in pwd: ");
	ft_putendl(cd_split[i]);
	free_tab2d(cd_split);
	return (NULL);
}

static char	*too_arg(char **cd_split)
{
	ft_putendl("cd: too many arguments");
	free_tab2d(cd_split);
	return (NULL);
}

char		*cd_arg(char *str, int *opt)
{
	char	**cd_split;
	int		i;
	char	*ret;

	i = 1;
	ret = NULL;
	if (!(cd_split = ft_strsplit(str, ' ')))
		return (NULL);
	while (check_opt(cd_split[i], opt))
		i++;
	if (tablen(cd_split + i) == 2)
		return (not_in_pwd(cd_split, i));
	else if (tablen(cd_split + i) > 2)
		return (too_arg(cd_split));
	if (!cd_split[i])
		ret = ft_strdup("\0");
	else
		ret = ft_strdup(cd_split[i]);
	free_tab2d(cd_split);
	return (ret);
}

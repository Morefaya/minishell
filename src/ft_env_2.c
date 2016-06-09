/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 12:21:42 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/09 14:28:11 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		putillegal_opt_env(char a)
{
	ft_putstr("env: illegal option --");
	ft_putchar(a);
	ft_putchar('\n');
	ft_putstr("usage: env [-i] [-u name]\n");
	ft_putstr("[name=value ...] [utility [argument ...]]\n");
	exit(1);
}

void		delete_env(char **str, t_list **env_c)
{
	(*str)++;
}


static char	*get_arg_unset(char **str)
{
	
}

void		unset_ft_env(char **str, t_list **env_c)
{
	char	*tmp;
	int		i;
	char	*unset;

	i = 0;
	(*str)++;
	unset = NULL;
	while (**str && ft_check_charset(**str, " \t\n"))
		(*str)++;
	tmp = *str;
	while (tmp[i] && !ft_check_charset(tmp[i], " \t\n"))
		i++;
	if (!(tmp = ft_strsub(*str, 0, i)))
		return ;
	if (!(unset = ft_strjoin(tmp, "=")))
		return ;
	free(tmp);
	if (check_arg(unset))
	{
		ft_putstr("env: unsetenv ");
		ft_putstr(unset);
		ft_putstr(" Invalid argument\n");
	}
}

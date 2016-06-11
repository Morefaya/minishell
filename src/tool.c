/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 20:30:49 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/11 16:27:31 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unsetenv_format(void)
{
	ft_putstr("unsetenv: Invalid argument\n");
}

void	putillegal_opt_env(char a)
{
	ft_putstr("env: illegal option --");
	ft_putchar(a);
	ft_putchar('\n');
	ft_putstr("usage: env [-i] [-u name]\n");
	ft_putstr("[name=value ...] [utility [argument ...]]\n");
}

void	freed(t_list **to_free)
{
	if (!to_free)
		return ;
	free((*to_free)->content);
	free(*to_free);
	*to_free = NULL;
}

void	freed_all(t_list **to_free)
{
	t_list	*tmp;

	while (*to_free)
	{
		tmp = (*to_free)->next;
		freed(to_free);
		*to_free = tmp;
	}
}

int		check_arg(char *str)
{
	if (!str)
		return (0);
	while (*str && !ft_check_charset(*str, " \t\n"))
	{
		if (*str == '=')
			return (1);
		str++;
	}
	return (0);
}

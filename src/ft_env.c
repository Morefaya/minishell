/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 16:12:11 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/09 14:15:57 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_arg(char *str)
{
	while (*str && !ft_check_charset(*str, " \t\n"))
	{
		if (*str == '=')
			return (1);
		str++;
	}
	return (0);
}

static int	check_opt(char **str, t_list **env_c)
{
	(*str)++;
	if (**str == 'u')
		unset_ft_env(str, env_c);
	else if (**str == 'i')
		delete_ft_env(str, env_c);
	else
		putillegal_opt_env(**str);
	return (0);
}

static int	parse(char *str, t_list **env_c)
{
	char	*tmp

		tmp = NULL;
	while (*str && !ft_check_charset(*str, " \t\n"))
		str++;
	while (*str)
	{
		while (*str && ft_check_charset(*str, " \t\n"))
			str++;
		if (*str == '-')
			exe = check_opt(&str, env_c);
		else if ((exe = check_arg(str)))
			set_env(&str, env_c);
	}
	if (exe)
		execute(str, env_c);
}

void	ft_env(t_list *cmd_l, t_list *env_l)
{
	t_list	*env_cpy;

	if (!(env_c = lstenv_cpy(env_l)))
		return ;
	parse(((t_shell*)(cmd_l->content))->str, &env_c);
}

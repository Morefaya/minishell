/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 16:12:11 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/10 20:23:38 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			check_arg(char *str)
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
	{
		//ft_putendl(*str);
		if (env_c)
			unset_ft_env(str, env_c);
	}
	else if (**str == 'i')
	{
		freed_all(env_c);
		check_opt(str, env_c);
	}
	else if (**str)
		putillegal_opt_env(**str);
	return (0);
}

static void	parse(char *str, t_list **env_c)
{
	char	*tmp;
	int		exe;

	tmp = NULL;
	exe = 0;
	while (*str && !ft_check_charset(*str, " \t\n"))
		str++;
	while (*str)
	{
		while (*str && ft_check_charset(*str, " \t\n"))
			str++;
		if (*str == '-')
			exe = check_opt(&str, env_c);
		else if ((exe = check_arg(str)))
			set_env(str, env_c);
		ft_putchar('@');
	}
	if (exe)
		ft_putendl("execute_now");
		//execute(str, env_c);
}

int			ft_env(t_list *cmd_l, t_list *env_l)
{
	t_list	*env_c;

	if (!(env_c = lstenv_cpy(env_l)))
		return (1);
	parse(((t_shell*)(cmd_l->content))->str, &env_c);
	print_lst(env_c);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 16:12:11 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/10 22:11:34 by jcazako          ###   ########.fr       */
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

static int	setting(char *str, t_list **env_c)
{
	char	*set_var;
	int		i;

	i = 0;
	while (str[i] && !ft_check_charset(str[i], " \t\n"))
		i++;
	if (!(set_var = ft_strsub(str, 0, i)))
		return (0);
	set_env(set_var, env_c);
	free(set_var);
	return (i);
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
			str += setting(str, env_c);
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

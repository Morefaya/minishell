/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 16:12:11 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/04 19:47:01 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	putillegal_env(char a)
{
	ft_putstr("env: illegal option --");
	ft_putchar(a);
	ft_putchar('\n');
	ft_putstr("usage: env [-i] [-u name]\n");
	ft_putstr("[name=value ...] [utility [argument ...]]\n");
	exit(1);
}

static void	delete_env(char **str, t_list *env_l)
{
	(*str)++;
	env_l->content->str = NULL;
	env_l-next = NULL;
}

static void	unset_env(char **str, t_list *env_l)
{
	char	*tmp;
	int	i;

	i = 0;
	(*str)++;
	tmp = *str;
	while (tmp[i] && ft_check_charset(tmp[i], " \t\n"))
	{
		i++;
	}
}

static int	check_arg(char *str)
{
	while (*str && !ft_check_charset(*str, " \t\n"))
	{
		if (*str == '=')
			return (1);
		str++;
	}
	return (0);
}

static int	check_opt(char **str, t_list *env_l)
{
	(*str)++;
	if (**str == 'u')
		unset_env(str, env_l);
	else if (**str == 'i')
		delete_env(str, env_l);
	else
		putillegal_env(**str);
	return (0);
}

static int	parse(char *str, t_list *env_l)
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
			exe = check_opt(&str, env_l);
		else if ((exe = check_arg(str)))
			set_env();
	}
	if (exe)
		execute(str, env_l);
}

void	ft_env(t_list *cmd_l, t_list *env_l)
{
	t_list	*env_cpy;

	if (!(env_cpy = ft_lstcpy(env_l)))
		return ;
	parse(((t_shell*)(cmd_l->content))->str, env_cpy);



}

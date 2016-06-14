/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 16:12:11 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/14 18:22:28 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_opt(char **str, t_list **env_c)
{
	(*str)++;
	if (**str == 'u')
	{
		if (env_c)
			unset_ft_env(str, env_c);
	}
	else if (**str == 'i')
	{
		freed_all(env_c);
		check_opt(str, env_c);
	}
	else if (**str && !ft_check_charset(**str, " \t\n"))
	{
		putillegal_opt_env(**str);
		(*str)++;
		return (1);
	}
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

static char	*parse_str(t_list *cmd_l, t_list **env_c, int *ret)
{
	char	*str;

	str = NULL;
	if (!cmd_l)
		return (NULL);
	str = ((t_shell*)(cmd_l->content))->str;
	while (*str && !ft_check_charset(*str, " \t\n"))
		str++;
	while (*str)
	{
		while (*str && ft_check_charset(*str, " \t\n"))
			str++;
		if (*str == '-')
			*ret = check_opt(&str, env_c);
		else if (check_arg(str))
			str += setting(str, env_c);
		else
			break ;
	}
	return (str);
}

static int	parse(t_list *cmd_l, t_list **env_c, char **path_t)
{
	int		ret;
	t_list	*cmd_c;
	int		ret_b;
	char	*str;

	cmd_c = NULL;
	ret_b = 0;
	ret = 0;
	if (!(str = parse_str(cmd_l, env_c, &ret)))
		return (0);
	if (!(cmd_c = ft_lstnew(cmd_l->content, cmd_l->content_size)))
		return (0);
	if (!(((t_shell*)(cmd_c->content))->str = ft_strdup(str)))
		return (0);
	if (*str && !ret)
	{
		ret_b = builtins(cmd_c, env_c, path_t);
		free(cmd_c->content);
		free(cmd_c);
		if (!ret_b)
			exe_cmd(str, *env_c, path_t);
		ret = 1;
	}
	return (ret);
}

int			ft_env(t_list *cmd_l, t_list *env_l, char **path_t)
{
	t_list	*env_c;

	if (!(env_c = lstenv_cpy(env_l)))
		return (1);
	if (!parse(cmd_l, &env_c, path_t))
		print_lst(env_c);
	return (1);
}

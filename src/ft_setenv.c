/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 17:38:27 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/09 21:56:13 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*gt_env_var(char *str)
{
	int		i;
	char	*env_v;

	env_v = NULL;
	i = 0;
	while (str[i] && !ft_check_charset(str[i], " =\t\n"))
		i++;
	if (!(env_v = ft_strsub(str, 0, i)))
		return (NULL);
	return (env_v);
}

static int	check_env_name(char *str, t_list *env_l)
{
	int		ret;
	char	*u_env;
	char	*tmp;

	ret = 0;
	if (!(u_env = gt_env_var(str)))
		return (0);
	while (env_l)
	{
		if (ft_strnstr(((t_shell*)(env_l->content))->str,
			u_env, ft_strlen(u_env)))
		{
			ret = 1;
			break;
		}
		env_l = env_l->next;
	}
	if (ret)
	{
		tmp = ((t_shell*)(env_l->content))->str;
		((t_shell*)(env_l->content))->str = str;
		free(u_env);
	}
	return (ret);
}

static char	*gt_arg(char *str)
{
	char	*s_env;
	int		i;

	i = 0;
	while (*str && !ft_check_charset(*str, " \t\n"))
		str++;
	while (*str && ft_check_charset(*str, " \t\n"))
		str++;
	if (!(s_env = ft_strtrim(str)))
		return (NULL);
	if (ft_strchr(s_env, ' ') || ft_strchr(s_env, '\t'
		|| ft_strchr(s_env, '\n')))
	{
		free(s_env);
		return (NULL);
	}
	return (s_env);
}

int			ft_setenv(t_list *cmd_l, t_list **env_l)
{
	t_shell	content;
	t_list	*new;

	if (!ft_strchr(((t_shell*)(cmd_l->content))->str, '='))
		return (1);
	if (!(content.str = gt_arg(((t_shell*)(cmd_l->content))->str)))
		return (1);
	if (check_env_name(content.str, *env_l))
	{
		print_lst(*env_l);
		return (1);
	}
	if (!(new = ft_lstnew(&content, sizeof(content))))
	{
		free(content.str);
		return (1);
	}
	ft_lstadd_back(*env_l, new);
	print_lst(*env_l);
	return (1);
}

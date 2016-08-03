/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 17:38:27 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/03 12:40:23 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ret_check(int ret, t_list *env_l, char *str)
{
	char	*tmp;

	if (ret)
	{
		tmp = ((t_shell*)(env_l->content))->str;
		((t_shell*)(env_l->content))->str = str;
		free(tmp);
	}
	return (ret);
}

static int	check_env_name(char *str, t_list *env_l)
{
	int		ret;
	char	*u_env;
	char	*tmp;

	ret = 0;
	if (!(u_env = gt_env_var(str)))
		return (0);
	if (!(tmp = ft_strjoin(u_env, "=")))
	{
		free(u_env);
		return (0);
	}
	while (env_l)
	{
		if (!ft_strncmp(tmp, ((t_shell*)(env_l->content))->str, ft_strlen(tmp)))
		{
			ret = 1;
			break ;
		}
		env_l = env_l->next;
	}
	free(u_env);
	free(tmp);
	return (ret_check(ret, env_l, str));
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
		unsetenv_format();
		free(s_env);
		return (NULL);
	}
	return (s_env);
}

void		set_env(char *str, t_list **env_l)
{
	t_list	*new;
	t_shell	content;

	content.str = str;
	if (check_env_name(content.str, *env_l))
		return ;
	if (!(new = ft_lstnew(&content, sizeof(content))))
	{
		free(str);
		return ;
	}
	if (*env_l)
		ft_lstadd_back(*env_l, new);
	else
		ft_lstadd(env_l, new);
}

int			ft_setenv(t_list *cmd_l, t_list **env_l)
{
	char	*str;

	if (!ft_strchr(((t_shell*)(cmd_l->content))->str, '='))
		return (1);
	else if (!(str = gt_arg(((t_shell*)(cmd_l->content))->str)))
		return (1);
	set_env(str, env_l);
	return (1);
}

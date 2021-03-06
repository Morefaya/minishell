/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 13:41:09 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/30 18:58:30 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*gt_env_name_2(char *tmp)
{
	char	*u_env;

	u_env = NULL;
	if (ft_strchr(tmp, '='))
	{
		unsetenv_format();
		free(tmp);
		return (NULL);
	}
	if (!(u_env = ft_strjoin(tmp, "=")))
	{
		free(tmp);
		return (NULL);
	}
	free(tmp);
	return (u_env);
}

static char	*gt_env_name(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	while (*str && !ft_check_charset(*str, " \t\n"))
		str++;
	while (*str && ft_check_charset(*str, " \t\n"))
		str++;
	tmp = str;
	while (tmp[i] && !ft_check_charset(tmp[i], " \t\n"))
		i++;
	if (!(tmp = ft_strsub(str, 0, i)))
		return (NULL);
	return (gt_env_name_2(tmp));
}

void		del_linkenv(char *u_env, t_list **env_l)
{
	t_list	*tmp;
	t_list	*box;
	int		len;

	len = ft_strlen(u_env);
	tmp = *env_l;
	if (ft_strnstr(((t_shell*)(tmp->content))->str, u_env, len))
	{
		tmp = *env_l;
		*env_l = (*env_l)->next;
		ft_lstdelone(&tmp, (void(*)(void*, size_t))del_content);
		return ;
	}
	while (tmp->next)
	{
		if (ft_strnstr(((t_shell*)(tmp->next->content))->str, u_env, len))
		{
			box = tmp->next;
			tmp->next = tmp->next->next;
			ft_lstdelone(&box, (void(*)(void*, size_t))del_content);
			return ;
		}
		tmp = tmp->next;
	}
}

int			ft_unsetenv(t_list *cmd_l, t_list **env_l)
{
	char	*u_env;

	if (!(u_env = gt_env_name(((t_shell*)(cmd_l->content))->str)))
		return (1);
	if (u_env)
		del_linkenv(u_env, env_l);
	free(u_env);
	return (1);
}

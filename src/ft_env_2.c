/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 14:18:58 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/20 14:22:18 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_it(char *arg, t_list **env_c)
{
	t_shell	content;
	t_list	*cmd;
	char	*str;

	if (!(str = ft_strjoin("setenv ", arg)))
		return ;
	content.str = str;
	if (!(cmd = ft_lstnew(&content, sizeof(content))))
		return ;
	ft_setenv(cmd, env_c);
	ft_lstdelone(&cmd, (void(*)(void*, size_t))del_content);
}

char	*execute_2(char **cmd)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	i = 0;
	j = 0;
	len = 0;
	while (cmd[i])
	{
		len += ft_strlen(cmd[i]);
		i++;
	}
	if (!(str = ft_strnew(len + i)))
		return (NULL);
	while (cmd[j])
	{
		ft_strcat(str, cmd[j]);
		if (j != i + 1)
			str[ft_strlen(str)] = ' ';
		j++;
	}
	return (str);
}

void	execute(char **cmd, t_list **env_c)
{
	t_shell content;
	t_list	*cmd_l;

	cmd_l = NULL;
	if (!cmd)
		return ;
	if (!(content.str = execute_2(cmd)))
		return ;
	if (!(cmd_l = ft_lstnew(&content, sizeof(content))))
		return ;
	minishell(cmd_l, env_c);
	ft_lstdel(&cmd_l, (void(*)(void*, size_t))del_content);
}

int		unset_it(t_list *unset, t_list **env_c)
{
	t_list	*cmd;
	t_shell	content;
	char	*str;

	cmd = NULL;
	while (unset)
	{
		str = ((t_shell*)(unset->content))->str;
		if (!(content.str = ft_strjoin("unsetenv ", str)))
			return (0);
		if (!(cmd = ft_lstnew(&content, sizeof(content))))
			return (0);
		ft_unsetenv(cmd, env_c);
		ft_lstdel(&cmd, (void(*)(void*, size_t))del_content);
		unset = unset->next;
	}
	return (1);
}

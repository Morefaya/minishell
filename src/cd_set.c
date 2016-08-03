/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 12:30:04 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/03 12:30:22 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			cd_set(char *owd, char *awd, char *cmd, t_list **env_l)
{
	t_shell	content;
	t_list	*cmd_pwd;
	char	*wd;

	if (ft_strcmp("setenv PWD=", cmd))
		wd = owd;
	else
		wd = awd;
	if (!(content.str = ft_strjoin(cmd, wd)))
	{
		free(awd);
		free(owd);
		return (1);
	}
	if (!(cmd_pwd = ft_lstnew(&content, sizeof(content))))
		return (1);
	ft_setenv(cmd_pwd, env_l);
	ft_lstdelone(&cmd_pwd, (void(*)(void*, size_t))del_content);
	return (0);
}

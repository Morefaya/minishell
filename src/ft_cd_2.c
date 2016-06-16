/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 20:47:00 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/16 20:51:29 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/stat.h>

char		*chdir_cd(char *str)
{
	char	*owd;

	if (!(owd = get_pwd()))
	{
		free(str);
		return (NULL);
	}
	if (chdir(str))
	{
		free(owd);
		free(str);
		return (NULL);
	}
	return (owd);
}

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
	ft_setenv(cmd_pwd, env_l, 1);
	return (0);
}

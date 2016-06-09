/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 15:19:13 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/09 15:19:17 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*make_cmd_path(char *path, t_list *cmd_l)
{
	char	*tmp;
	char	*cmd;
	char	*cmd_path;

	tmp = NULL;
	cmd_path = NULL;
	if (!(cmd = get_cmd(((t_shell*)(cmd_l->content))->str)))
		return (NULL);
	if (!(tmp = ft_strjoin(path, "/")))
	{
		free(cmd);
		return (NULL);
	}
	if (!(cmd_path = ft_strjoin(tmp, cmd)))
	{
		free(tmp);
		free(cmd);
		return (NULL);
	}
	return (cmd_path);
}

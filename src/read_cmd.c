/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 13:19:00 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/04 19:00:54 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**trim_split(char **cmd_tab)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = 0;	 
	while (cmd_tab[i])
	{
		tmp = cmd_tab[i];
		if (!(cmd_tab[i] = ft_clean(cmd_tab[i])))
		{
			free_tab2d(cmd_tab);
			return (NULL);
		}
		free(tmp);
		i++;
	}
	return (cmd_tab);
}

t_list		*read_cmd(void)
{
	char	*line;
	char	**cmd_t;
	t_list	*cmd_l;

	cmd_t = NULL;
	cmd_l = NULL;
	if (get_next_line(0, &line) <= 0)
		return (NULL);
	if (ft_strstr(line, "exit"))
		exit(0);
	if (!(cmd_t = ft_strsplit(line, ';')))
		return (NULL);
	free(line);
	if (!(cmd_t = trim_split(cmd_t)))
		return (NULL);
	if (!(cmd_l = lst_tab2d(cmd_t)))
	{
		free_tab2d(cmd_t);
		return (NULL);
	}
	free_tab2d(cmd_t);
	return (cmd_l);
}

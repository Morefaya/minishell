/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 13:41:09 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/09 14:28:03 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*unset(char *str, t_list **env_l)
{
	char	*tmp;
	int		i;
	char	*u_env;

	i = 0;
	while (*str && !ft_check_charset(*str, " \t\n"))
		str++;
	while (*str && ft_check_charset(*str, " \t\n"))
		str++;
	tmp = str;
	while (tmp[i] && ft_check_charset(temp[i], " \t\n"))
		i++;
	if (!(tmp = ft_strsub(str, 0, i)))
		return (NULL);
	if (!(u_env = ft_strjoin(tmp, "=")))
	{
		free(tmp);
		return (NULL);
	}
	free(tmp);
	return (u_env);
}

void		

void		ft_unsetenv(t_list *cmd_l, t_list **env_l)
{
	char	*u_env;
	
	if (!(u_env = unset(((t_shell*)(cmd_l->content))->str, env_)))
		return (NULL);
	
	print_lst(*env_l);
}

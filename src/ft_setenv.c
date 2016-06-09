/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 17:38:27 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/09 19:33:07 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*static void	check_env(char *str, )
{
	int	i
}*/

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
		return (0);
	if (!(content.str = gt_arg(((t_shell*)(cmd_l->content))->str)))
		return (1);
	if (!(new = ft_lstnew(&content, sizeof(content))))
	{
		free(content.str);
		return (0);
	}
	ft_lstadd_back(*env_l, new);
	print_lst(*env_l);
	return (1);
}

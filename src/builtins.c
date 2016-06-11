/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 14:10:32 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/11 15:35:07 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtins(t_list *lst, t_list **env_l)
{
	if (ft_strnstr(((t_shell*)(lst->content))->str, "unsetenv",
		ft_strlen("unsetenv")))
		return (ft_unsetenv(lst, env_l));
	else if (ft_strnstr(((t_shell*)(lst->content))->str, "setenv",
		ft_strlen("setenv")))
		return (ft_setenv(lst, env_l));
	else if (ft_strnstr(((t_shell*)(lst->content))->str, "env",
		ft_strlen("env")))
		return (ft_env(lst, *env_l));
	return (0);
}

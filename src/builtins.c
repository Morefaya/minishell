/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 14:10:32 by jcazako           #+#    #+#             */
/*   Updated: 2016/07/09 17:42:13 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	built_2(t_list *lst, t_list **env_l)
{
	char	*str;
	int		len;

	len = 0;
	str = ((t_shell*)(lst->content))->str;
	if ((ft_strnstr(str, ENV, len = ft_strlen(ENV)) && !str[len])
			|| (ft_strnstr(str, ENV, len) && ft_strchr(" \t\n", str[len])))
	{
		ft_env(lst, *env_l);
		return (1);
	}
	else if ((ft_strnstr(str, CD, len = ft_strlen(CD)) && !str[len])
			|| (ft_strnstr(str, CD, len) && ft_strchr(" \t\n", str[len])))
	{
		ft_cd(lst, env_l);
		return (1);
	}
	else if ((ft_strnstr(str, ECHO, len = ft_strlen(ECHO)) && !str[len])
			|| (ft_strnstr(str, ECHO, len) && ft_strchr(" \t\n", str[len])))
	{
		ft_echo(lst, env_l);
		return (1);
	}
	return (0);
}

int			builtins(t_list *lst, t_list **env_l)
{
	char	*str;
	int		len;

	len = 0;
	str = ((t_shell*)(lst->content))->str;
	if ((ft_strnstr(str, UNSET, len = ft_strlen(UNSET)) && !str[len])
			|| (ft_strnstr(str, UNSET, len) && ft_strchr(" \t\n", str[len])))
	{
		ft_unsetenv(lst, env_l);
		print_lst(*env_l);
		return (1);
	}
	else if ((ft_strnstr(str, SET, len = ft_strlen(SET)) && !str[len])
			|| (ft_strnstr(str, SET, len) && ft_strchr(" \t\n", str[len])))
	{
		ft_setenv(lst, env_l);
		print_lst(*env_l);
		return (1);
	}
	else if ((ft_strnstr(str, EXIT, len = ft_strlen(EXIT)) && !str[len])
			|| (ft_strnstr(str, EXIT, len) && ft_strchr(" \t\n", str[len])))
		return (ft_exit());
	else
		return (built_2(lst, env_l));
}

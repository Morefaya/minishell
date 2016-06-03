/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 14:10:32 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/03 14:22:51 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ret_ft(void(*)(t_list*) ft, t_list *arg,int ret)
{
	ft(arg);
	return (ret);
}

int	builtins(t_list	*lst)
{
	if (ft_strncmp(((t_shell*)(lst->content))->str, "env", ft_strlen("env")))
		return (ret_ft(ft_env, 1));
}

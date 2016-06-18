/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstenv_cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 11:19:45 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/11 16:25:55 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define T_SHELL ((t_shell*)(env->content))->str

t_list	*lstenv_cpy(t_list *env)
{
	t_list	*env_tmp;
	t_list	*env_cpy;
	t_shell	content;

	env_tmp = NULL;
	env_cpy = NULL;
	while (env)
	{
		if (!env_cpy)
		{
			content.str = ft_strdup(T_SHELL);
			env_cpy = ft_lstnew(&content, sizeof(content));
		}
		else
		{
			content.str = ft_strdup(T_SHELL);
			env_tmp = ft_lstnew(&content, sizeof(content));
			ft_lstadd_back(env_cpy, env_tmp);
		}
		env = env->next;
	}
	return (env_cpy);
}

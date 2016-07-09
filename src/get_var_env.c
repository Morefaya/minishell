/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 18:47:51 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/14 21:09:01 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_var_env(char *env_var, t_list *env_l)
{
	char	*var_value;
	int		len_var;
	int		len_env;

	if (!env_l)
		return (NULL);
	var_value = NULL;
	len_env = ft_strlen(((t_shell*)(env_l->content))->str);
	len_var = ft_strlen(env_var);
	while (env_l)
	{
		if (ft_strnstr(((t_shell*)(env_l->content))->str, env_var, len_var)
			&& ((t_shell*)(env_l->content))->str[len_var] == '=')
		{
			if (!(var_value = ft_strsub(((t_shell*)(env_l->content))->str,
				len_var + 1, len_env - len_var)))
				return (NULL);
			return (var_value);
		}
		env_l = env_l->next;
	}
	return (NULL);
}

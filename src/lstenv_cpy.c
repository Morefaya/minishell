/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstenv_cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 11:19:45 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/09 11:55:24 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list	*lstenv_cpy(t_list *env)
{
	t_list	*env_tmp;
	t_list	*env_cpy;

	env_tmp = NULL;
	env_cpy = NULL;
	while (*env)
	{
		if (!env_cpy)
		{
			if (!(env_cpy = ft_lstnew(env->content, env->content_size)))
				return (NULL);
		}
		else
		{
			if (!(env_tmp = ft_lstnew(env->content, env->content_size)))
				return (NULL);
			ft_lstadd_back(env_cpy, env_tmp);
		}
		env->next;
	}
	return (env_cpy);
}

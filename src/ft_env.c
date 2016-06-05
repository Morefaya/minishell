/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 16:12:11 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/04 19:47:01 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*static void	check_env_opt(char *cmd, t_opt_env *opt_env)
{
	if (*cmd == 'u')
		opt_env->u = 1;
	else if (*cmd == 'i')
		opt_env->i = 1;
}*/

void	ft_env(t_list *cmd_l, t_list *env_l)
{
	print_lst(env_l);
	cmd_l++;
}

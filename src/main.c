/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 20:38:42 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/09 16:35:19 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_list	*env_l;
	t_list	*cmd_l;

	ac = 0;
	av++;
	cmd_l = NULL;
	if (!(env_l = lst_tab2d(env)))
		ft_putstr("NULL");
	signal(SIGINT, SIG_IGN);
	while (42)
	{
		ft_putstr("jcazako> ");
		cmd_l = read_cmd();
		minishell(cmd_l, &env_l);
		ft_lstdel(&cmd_l, (void(*)(void*, size_t))del_content);
	}
	ft_lstdel(&env_l, (void(*)(void*, size_t))del_content);
	return (0);
}

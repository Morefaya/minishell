/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 20:38:42 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/14 12:17:55 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_list	*env_l;
	t_list	*cmd_l;
	char	**path_t;

	ac = 0;
	av++;
	cmd_l = NULL;
	if (!(env_l = lst_tab2d(env)))
		ft_putstr("ENV_NULL");
	if (!(path_t = get_paths_vars(env_l)))
		ft_putendl("PATH_NULL");
	signal(SIGINT, SIG_IGN);
	while (42)
	{
		ft_putstr("\033[32mjcazako> \033[0m");
		cmd_l = read_cmd();
		minishell(cmd_l, &env_l, path_t);
		//ft_lstdel(&cmd_l, (void(*)(void*, size_t))del_content);
	}
	return (0);
}

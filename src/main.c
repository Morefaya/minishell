/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 20:38:42 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/03 13:34:05 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*line;
	pid_t	pid;
	int	i;
	t_list	*env_l;
	t_list	*cmd_l;

	i = 0;
	ac = 0;
	cmd_l = NULL;
	if (!(env_l = lst_tab2d(env)))
		ft_putstr("NULL");
	signal(SIGINT, SIG_IGN);
	while (42)
	{
		ft_putstr("jcazako> ");
		print_lst((cmd_l = read_cmd()));	
		if (!(pid = fork()))
		{
			signal(SIGINT, SIG_DFL);
			execve("/bin/ls", av, env);
		}
		else if (pid > 0)
		{
			signal(SIGINT, SIG_IGN);
			wait(&i);
		}
		ft_lstdel(&cmd_l, (void(*)(void*, size_t))del_content);
	}
	ft_lstdel(&env_l, (void(*)(void*, size_t))del_content);
	free(line);
	return (0);
}

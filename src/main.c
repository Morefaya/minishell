/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 20:38:42 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/01 18:41:31 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*line;
	pid_t	pid;
	int		i;
	t_list	*lst;

	i = 0;
	ac = 0;
	signal(SIGINT, SIG_IGN);
	if (!(lst = lst_tab2d(env)))
		ft_putstr("NULL");
	print_lst(lst);
	while (42)
	{
		ft_putstr("jcazako> ");
		get_next_line(0, &line);
		if (ft_strstr(line, "exit"))
			exit(0);
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
	}
	free(line);
	return (0);
}

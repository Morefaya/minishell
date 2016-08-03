/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 20:38:42 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/03 15:01:04 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <termios.h>

void	sig_handler(int sig)
{
	if (sig == 2)
	{
		ft_putstr("\033[2D");
		ft_putendl("  ");
		ft_putstr("\033[32mjcazako> \033[0m");
	}
}

int		main(int ac, char **av, char **env)
{
	t_list			*env_l;
	t_list			*cmd_l;
	struct termios	term;

	(void)ac;
	(void)av;
	tcgetattr(0, &term);
	term.c_cc[VEOF] = 0;
	tcsetattr(0, TCSANOW, &term);
	signal(SIGINT, sig_handler);
	cmd_l = NULL;
	if (!(env_l = lst_tab2d(env)))
		ft_putstr("ENV_NULL");
	while (42)
	{
		ft_putstr("\033[32mjcazako> \033[0m");
		cmd_l = read_cmd();
		minishell(cmd_l, &env_l);
		ft_lstdel(&cmd_l, (void(*)(void*, size_t))del_content);
	}
	ft_lstdel(&env_l, (void(*)(void*, size_t))del_content);
	return (0);
}

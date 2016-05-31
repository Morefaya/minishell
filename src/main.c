/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 20:38:42 by jcazako           #+#    #+#             */
/*   Updated: 2016/05/31 20:00:21 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>

int	main(int ac, char **av, char **env)
{
	int		i;
	char	*line;

	i = 0;
	ac = 0;
	/*?while (env[i])
	{
		ft_putendl(env[i]);
		i++;
	}*/
	while (42)
	{
		ft_putstr("jcazako> ");
		get_next_line(0, &line);
		if (ft_strstr(line, "ls"))
		{
			i = execve("/bin/ls", av, env);
			break ;
		}
		free(line);
	}
	free(line);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 16:51:03 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/11 21:17:18 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/stat.h>

static int	check_opt(char **str)
{
	int		opt;

	opt = 0;
	while (*str)
	{
		if (**str != '-')
			return (0);
		(*str)++;
		while (**str && !ft_check_charset(**str, " \t\n"))
		{
			if (**str == 'P')
				opt = 1;
			else if (**str == 'L' && !opt)
				opt = 0;
			else if (**str != 'P' && **str != 'L')
				opt = -42;
			(*str)++;
		}
		while (**str && ft_check_charset(**str, " \t\n"))
			(*str)++;
	}
	return (opt);
}

int		ft_cd(t_list *lst, t_list *env_l)
{

	char		pwd[256];
	char		path[] = "./src";
	struct stat	buff;
	int			(*f)(const char *, struct stat *);
	int			opt;
	char		**cd_split;
	int			ret;

	char	*str;

	
	if (!(cd_split = ft_strsplit(((t_shell*)(lst->content))->str, ' ')))
		return (1);
	if ((ret = tablen(cd_split)) == 3)
	{
		ft_putstr("cd: string not in pwd: ");
		ft_putendl(cd_split[1]);
	}
	else if (ret > 3)
		ft_putendl("cd: too many arguments");
	free_tab2d(cd_split);



	str = ((t_shell*)(lst->content))->str;
	str += 3;

	ft_putnbr(opt = check_opt(&str));
	ft_putchar('\n');

	getcwd(pwd, 256);
	ft_putendl(((t_shell*)(lst->content))->str);
	ft_putendl(pwd);
	opt = 1;
	f = (opt) ? stat : lstat;
	if (!access(path, F_OK) && !access(path, R_OK | X_OK))
	{
		ft_putendl("ACCESS");
		if (stat(path, &buff) != -1)
		{
			ft_putendl("STAT");
			if (((buff.st_mode) & S_IFMT) == S_IFDIR)
			{
				ft_putendl("ISDIR");
				chdir(path);
			}
		}
	}
	getcwd(pwd, 256);
	ft_putendl(pwd);
	lst = lst->next;
	env_l = env_l->next;
	return (1);
}

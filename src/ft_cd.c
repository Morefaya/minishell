/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 16:51:03 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/14 18:18:06 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/stat.h>

static int	check_opt(char *str, int *opt)
{
	if (!str)
		return (0);
	if (*str != '-')
		return (0);
	str++;
	while (*str)
	{
		if (*str == 'P')
			*opt = 1;
		else if (!ft_check_charset(*str, "PL"))
			*opt = -1;
		str++;
	}
	return (1);
}

static char	*cd_arg(char *str, int *opt)
{
	char	**cd_split;
	int		i;
	int		nb_arg;

	i = 1;
	if (!(cd_split = ft_strsplit(str, ' ')))
		return (NULL);
	while (check_opt(cd_split[i], opt))
		i++;
	if ((nb_arg = tablen(cd_split + i)) == 2)
	{
		ft_putstr("cd: string not in pwd: ");
		ft_putendl(cd_split[i]);
		free_tab2d(cd_split);
		return (NULL);
	}
	if (nb_arg > 2)
	{
		ft_putendl("cd: too many arguments");
		free_tab2d(cd_split);
		return (NULL);
	}
	if (!cd_split[i])
		return (ft_strdup("\0"));
	return (cd_split[i]);
}

static char	*deal_arg(char *str, int opt)
{
	struct stat	f_stat;

	if (!ft_strcmp(str, ".") || !ft_strcmp(str, "\0"))
		return (get_pwd());
	else if (!ft_strcmp(str, ".."))
		return (get_a_pwd());
	if (access(str, F_OK))
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(str);
		return (NULL);
	}
	if (lstat(str, &f_stat) == -1)
	{
		ft_putendl("error lstat");
		return (NULL);
	}
	
	if (access(str, X_OK))
	{
		ft_putstr("cd: permission denied");
		ft_putendl(str);
		return (NULL);
	}
	opt++;
	return (str);
}

int		ft_cd(t_list *lst, t_list *env_l)
{

	/*char		pwd[256];
	char		path[] = "./src";
	struct stat	buff;
	int			(*f)(const char *, struct stat *);
	int			opt;
	int			ret;*/
	char	*str;
//	char	*pwd;
//	char	*a_pwd;
	int		opt;

	ft_putendl("MON CD");
	opt	= 0;
	if (!(str = cd_arg(((t_shell*)(lst->content))->str, &opt)))
		return (1);
	deal_arg(str, opt);
	chdir(str);
/*	pwd = get_pwd();
	a_pwd = get_a_pwd();
	ft_putendl(pwd);
	ft_putendl(a_pwd);


	pwd = get_pwd();
	a_pwd = get_a_pwd();
	ft_putendl(pwd);
	ft_putendl(a_pwd);*/



	env_l++;
	opt++;

	/*if ((ret = tablen(cd_split)) == 3)
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
	env_l = env_l->next;*/
	return (1);
}

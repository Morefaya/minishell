/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 16:51:03 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/12 13:07:28 by jcazako          ###   ########.fr       */
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
	else if (nb_arg > 2)
	{
		ft_putendl("cd: too many arguments");
		free_tab2d(cd_split);
		return (NULL);
	}
	return (cd_split[i]);
}

static char	*deal_arg(char *str)
{
	char	*pwd;
	char	*a_pwd;

	if (!(pwd = ft_strnew(BUFF_SIZE)))
		return (NULL);
	getcwd(pwd, BUFF_SIZE);
	if (!(a_wd = get_a_pwd()))
	if (ft_strcmp(str, "."))
		return (pwd);

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
	int		opt;

	opt	= 0;
	if (!(str = cd_arg(((t_shell*)(lst->content))->str, &opt)))
		return (1);

	ft_putendl(str);
	env_l++;

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

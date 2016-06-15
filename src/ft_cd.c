/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 16:51:03 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/14 21:07:55 by jcazako          ###   ########.fr       */
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

static char	*deal_arg(char *str)
{
	struct stat	f_stat;

	if (access(str, F_OK))
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(str);
		return (NULL);
	}
	if (lstat(str, &f_stat) == -1)
		return (NULL);
	if (access(str, X_OK))
	{
		ft_putstr("cd: permission denied");
		ft_putendl(str);
		return (NULL);
	}
	return (str);
}

int		ft_cd(t_list *lst, t_list **env_l)
{
	char	*str;
	int	opt;
	char	*home_var;
	char	*owd;
	t_shell	content;
	t_list	*cmd_pwd;
	char	*path;

	opt	= 0;
	home_var = NULL;
	if (!(str = cd_arg(((t_shell*)(lst->content))->str, &opt)))
		return (1);
	if (!(ft_strcmp(str, "\0") || !(ft_strcmp(str, "~"))))
	{
		if (!(home_var = get_var_env("HOME", *env_l)))
		{
			ft_putendl("/usr/bin/cd: line 4: cd: HOME not set");
			return (1);
		}
		else
		{
			free(str);
			str = home_var;
		}
	}
	deal_arg(str);
	if (!(owd = get_pwd()))
		return (1);
	if (!(path = ft_strjoin(ft_strjoin(owd, "/"), str)))
		return (1);
	ft_putendl(path);
	if (chdir(path))
	{
		free(str);
		return (1);
	}
	if (!(content.str = ft_strjoin("setenv OLDPWD=", owd)))
	{
		free(owd);
		return (1);
	}
	free(owd);
	if (!(owd = get_pwd()))
		return (1);
	ft_putendl(owd);
	if (!(cmd_pwd = ft_lstnew(&content, sizeof(content))))
		return (1);
	ft_setenv(cmd_pwd, env_l, 1);
	free(((t_shell*)(cmd_pwd->content))->str);
	if (!(((t_shell*)(cmd_pwd->content))->str = ft_strjoin("setenv PWD=", owd)))
	{
		free(owd);
		return (1);
	}
	free(owd);
	ft_setenv(cmd_pwd, env_l, 1);
	ft_lstdelone(&cmd_pwd, (void(*)(void*, size_t))del_content);
	return (1);
}

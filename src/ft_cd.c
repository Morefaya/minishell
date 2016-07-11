/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 16:51:03 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/30 19:34:21 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/stat.h>

static void	free_cd(char *owd, char *awd, char *str)
{
	free(owd);
	free(awd);	
	free(str);
}

static int	deal_arg(char *str)
{
	struct stat	f_stat;

	if (access(str, F_OK))
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(str);
		free(str);
		return (0);
	}
	if (lstat(str, &f_stat) == -1)
	{
		free(str);
		return (0);
	}
	if (access(str, X_OK))
	{
		ft_putstr("cd: permission denied");
		ft_putendl(str);
		free(str);
		return (0);
	}
	return (1);
}

int			ft_cd(t_list *lst, t_list **env_l)
{
	char	*str;
	char	*owd;
	char	*awd;

	str = NULL;
	if (!(str = check_cd(lst, env_l)))
		return (1);
	if (!deal_arg(str))
		return (1);
	if (!(owd = chdir_cd(str)))
		return (1);
	if (!(awd = get_pwd()))
	{
		free (owd);
		free(str);
		return (1);
	}
	if ((cd_set(owd, awd, "setenv OLDPWD=", env_l))
		|| (cd_set(owd, awd, "setenv PWD=", env_l)))
	{
		free_cd(owd, awd, str);
		return (1);
	}
	free_cd(owd, awd, str);
	return (1);
}

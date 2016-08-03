/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 12:32:54 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/03 12:32:57 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/stat.h>

static int	deal_home(char **str, t_list *env_l)
{
	char	*home_var;

	free(*str);
	if (!(home_var = get_var_env("HOME", env_l)))
	{
		ft_putendl("/usr/bin/cd: line 4: cd: HOME not set");
		return (2);
	}
	else if (!(*str = ft_strjoin(home_var, *str + 1)))
		return (1);
	free(home_var);
	return (0);
}

static int	deal_old(char **str, t_list *env_l)
{
	char	*old_var;

	free(*str);
	if (!(old_var = get_var_env("OLDPWD", env_l)))
	{
		ft_putendl("/usr/bin/cd: line 4: cd: OLDPWD not set");
		return (1);
	}
	else
		*str = old_var;
	return (0);
}

static int	deal_var(char **str, t_list *env_l)
{
	char	*var;

	if (!(var = get_var_env(*str + 1, env_l)))
	{
		ft_putstr("/usr/bin/cd: line 4: cd: ");
		ft_putstr(*str + 1);
		ft_putendl(" not set");
		free(*str);
		return (1);
	}
	else
	{
		free(*str);
		*str = var;
	}
	return (0);
}

char		*check_cd(t_list *lst, t_list **env_l)
{
	char	*str;
	int		opt;

	opt = 0;
	str = NULL;
	if (!(str = cd_arg(((t_shell*)(lst->content))->str, &opt)))
		return (NULL);
	if (!ft_strcmp(str, "\0") || *str == '~')
	{
		if (deal_home(&str, *env_l))
			return (NULL);
	}
	else if (!ft_strcmp(str, "-"))
	{
		if (deal_old(&str, *env_l))
			return (NULL);
	}
	else if (*str == '$')
	{
		if (deal_var(&str, *env_l))
			return (NULL);
	}
	return (str);
}

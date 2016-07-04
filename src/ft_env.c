/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 14:09:01 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/20 14:30:05 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	no_arg_env(char **arg, t_list **env_c, int i)
{
	if (!arg[i])
	{
		free_tab2d(arg);
		print_lst(*env_c);
		ft_lstdel(env_c, (void(*)(void*, size_t))del_content);
		return (0);
	}
	return (1);
}

static void	get_set(char **arg, int *i, t_list **env_c)
{
	while (arg[*i])
	{
		if (!ft_strchr(arg[*i], '='))
			break ;
		set_it(arg[*i], env_c);
		(*i)++;
	}
}

static int	start_env(t_list *env_l, t_list **env_c, char ***arg, t_list *cmd_l)
{
	if (!(*env_c = lstenv_cpy(env_l)))
		return (0);
	if (!(*arg = ft_strstr_split(((t_shell*)(cmd_l->content))->str, " \t\n")))
	{
		ft_lstdel(env_c, (void(*)(void*, size_t))del_content);
		return (0);
	}
	return (1);
}

int			ft_env(t_list *cmd_l, t_list *env_l)
{
	t_list	*env_c;
	char	**arg;
	t_list	*unset;
	int		i;
	int		illegal;


	i = 1;
	illegal = 0;
	if (!(start_env(env_l, &env_c, &arg, cmd_l)))
		return (1);
	if (!(no_arg_env(arg, &env_c, i)))
	{
		ft_lstdel(&env_c, (void(*)(void*, size_t))del_content);
		return (1);
	}
	unset = checkout(arg, &i, env_c, &illegal);
	if (!(unset_it(unset, &env_c)))
	{
		ft_lstdel(&env_c, (void(*)(void*, size_t))del_content);
		return (1);
	}
	get_set(arg, &i, &env_c);
	if (arg[i])
		execute(arg + i, &env_c);
	else if (!illegal)
		print_lst(env_c);
	ft_lstdel(&unset, (void(*)(void*, size_t))del_content);
	free_tab2d(arg);
	ft_lstdel(&env_c, (void(*)(void*, size_t))del_content);
	return (1);
}

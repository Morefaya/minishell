/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkout.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 11:02:17 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/18 13:46:41 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*check_u(char *str)
{
	char	*cpy;

	if (!*str)
		return (NULL);
	if (!(cpy = ft_strdup(str)))
		return (NULL);
	return (cpy);
}

static char	*trim_name(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '=')
		i++;
	if (!(tmp = ft_strsub(str, 0, i)))
		return (NULL);
	return (tmp);
}

static void	add_all(t_list **first_l, t_list *env_c)
{
	t_shell	content;
	t_list	*tmp;

	tmp = NULL;
	if (!env_c)
		return ;
	while (env_c)
	{
		content.str = trim_name(((t_shell*)(env_c->content))->str);
		if (!(tmp = ft_lstnew(&content, sizeof(content))))
			return ;
		ft_lstadd(first_l, tmp);
		env_c = env_c->next;
	}
}

/*static t_list	*deal_u(char **arg, int *i, t_list **first_l)
{
	t_shell	content;
	t_list	*unset_l;

	unset_l = NULL;
	if (!(content.str = check_u(arg[++(*i)])))
	{
		ft_putendl("env: option requires an argument -- u");
		ft_lstdel(first_l, (void(*)(void*, size_t))del_content);
		return (NULL);
	}
	if (!(unset_l = ft_lstnew(&content, sizeof(content))))
	{
		free(content.str);
		return (NULL);
	}
	ft_lstadd(first_l, unset_l);
	return (unset_l);
}*/


t_list	*checkout(char **arg, int *i, t_list *env_c)
{
	t_list	*unset_l;
	t_list	*first_l;
	t_shell	content;

	unset_l = NULL;
	first_l = NULL;
	while (arg[*i])
	{
		if (arg[*i][0] != '-')
			break ;
		if (arg[*i][1] == 'u')
		{
			if (!(content.str = check_u(arg[*i] + 2)))
			{
				if (!(content.str = check_u(arg[++(*i)])))
				{
					ft_putendl("env: option requires an argument -- u");
					ft_lstdel(&first_l, (void(*)(void*, size_t))del_content);
					return (NULL);
				}
				if (!(unset_l = ft_lstnew(&content, sizeof(content))))
				{
					free(content.str);
					return (NULL);
				}
				ft_lstadd(&first_l, unset_l);
				//return (deal_u(arg, i, &first_l));
			}
		}
		else if (arg[*i][1] == 'i')
		{
			add_all(&first_l, env_c);
		}
		else
		{
			putillegal_opt_env(arg[*i][1]);
			ft_lstdel(&first_l, (void(*)(void*, size_t))del_content);
			return (NULL);
		}
		(*i)++;
	}
	print_lst(first_l);
	return (first_l);
}

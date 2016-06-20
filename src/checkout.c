/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkout.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 11:02:17 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/20 12:56:06 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		add_all(t_list **first_l, t_list *env_c)
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

static t_list	*deal_u(char **arg, int *i, t_list **first_l, int *illegal)
{
	t_shell	content;
	t_list	*unset_l;

	unset_l = NULL;
	if (!(content.str = check_u(arg[++(*i)])))
	{
		ft_putendl("env: option requires an argument -- u");
		*illegal = 1;
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
}

static t_list	*stack_u(char **arg, int *i, t_list **first_l, int *illegal)
{
	t_shell	content;
	t_list	*unset;

	unset = NULL;
	if (!(content.str = check_u(arg[*i] + 2)))
	{
		if (!deal_u(arg, i, first_l, illegal))
			return (NULL);
	}
	else
	{
		if (!(unset = ft_lstnew(&content, sizeof(content))))
			return (NULL);
		ft_lstadd(first_l, unset);
	}
	return (*first_l);
}

t_list			*checkout(char **arg, int *i, t_list *env_c, int *illegal)
{
	t_list	*first_l;

	first_l = NULL;
	while (arg[*i])
	{
		if (arg[*i][0] != '-')
			break ;
		if (arg[*i][1] == 'u')
		{
			if (!stack_u(arg, i, &first_l, illegal))
				return (NULL);
		}
		else if (arg[*i][1] == 'i')
			add_all(&first_l, env_c);
		else
		{
			putillegal_opt_env(arg[*i][1]);
			ft_lstdel(&first_l, (void(*)(void*, size_t))del_content);
			return (NULL);
		}
		(*i)++;
	}
	return (first_l);
}

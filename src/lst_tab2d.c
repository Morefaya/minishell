/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tab2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 16:49:40 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/01 18:41:04 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list	*get_link(char **tab)
{
	t_list	*lst;
	t_shell	content;

	if (!(content.str = ft_strdup(*tab)))
		return (NULL);
	if (!(lst = ft_lstnew(&content, sizeof(content))))
	{
		free(content.str);
		return (NULL);
	}
	return (lst);
}

static void		make_link(t_list **lst, char **tab)
{
	t_list	*lst_tmp;

	if ((lst_tmp = get_link(tab)))
		ft_lstadd(lst, lst_tmp);
}

t_list			*lst_tab2d(char **tab)
{
	t_list	*lst;

	lst = NULL;
	while (*tab)
	{
		make_link(&lst, tab);
		tab++;
	}
	return (lst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab2d_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 15:18:57 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/11 16:27:09 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**tab2d_lst(t_list *lst)
{
	int		nb_el;
	char	**tab;
	int		i;

	nb_el = 0;
	tab = NULL;
	i = 0;
	nb_el = ft_lstcount(lst);
	if (!(tab = (char**)malloc(sizeof(*tab) * nb_el + 1)))
		return (NULL);
	while (lst)
	{
		if (!(tab[i] = ft_strdup(((t_shell*)(lst->content))->str)))
		{
			free_tab2d(tab);
			return (NULL);
		}
		i++;
		lst = lst->next;
	}
	return (tab);
}

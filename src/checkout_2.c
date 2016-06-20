/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkout_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 12:46:47 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/20 12:51:22 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*check_u(char *str)
{
	char	*cpy;

	if (!str)
		return (NULL);
	if (!*str)
		return (NULL);
	if (!(cpy = ft_strdup(str)))
		return (NULL);
	return (cpy);
}

char	*trim_name(char *str)
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

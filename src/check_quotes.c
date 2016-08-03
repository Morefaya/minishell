/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 12:32:20 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/03 12:32:23 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_quotes(char *str, char *tmp_1)
{
	int		len;
	int		dist;
	int		nb_l;
	int		nb_r;

	nb_l = 0;
	nb_r = 0;
	len = ft_strlen(str);
	dist = tmp_1 - str;
	while (dist >= 0)
	{
		if (str[dist] == '\'')
			nb_l++;
		dist--;
	}
	while (*tmp_1)
	{
		if (*tmp_1 == '\'')
			nb_r++;
		tmp_1++;
	}
	if (nb_l % 2 && nb_r % 2)
		return (0);
	else
		return (1);
}

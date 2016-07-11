/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 22:17:02 by jcazako           #+#    #+#             */
/*   Updated: 2016/07/09 23:10:57 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	help_echo(char **str)
{
	char	a;

	if (ft_strchr("\"\'", **str))
	{
		a = **str;
		(*str)++;
		while (**str && **str != a)
		{
			ft_putchar(**str);
			(*str)++;
		}
		if (**str)
			(*str)++;
	}
}

void		put_echo(char *str)
{
	int		cond;

	cond = 0;
	if (!str)
		return ;
	while (*str)
	{
		while (*str && ft_strchr(" \t", (int)*str))
			str++;
		if (!cond)
			cond++;
		else if (*str)
			ft_putchar(' ');
		while (*str && !ft_strchr(" \t\"\'", (int)*str))
			ft_putchar(*str++);
		if (*str)
			help_echo(&str);
	}
}

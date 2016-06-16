/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 21:02:14 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/16 22:03:18 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *gt_env_var(char *str)
{
	int     i;
	char    *env_v;

	env_v = NULL;
	i = 0;
	while (str[i] && !ft_check_charset(str[i], " =\t\n"))
		i++;
	if (!(env_v = ft_strsub(str, 0, i)))
		return (NULL);
	return (env_v);
}

int		cmp_env(char *str1, char *str2)
{
	char	*tmp;
	int		ret;

	ret = 0;
	if (!str1 || !str2)
		return (0);
	if (!(tmp = gt_env_var(str1)))
		return (0);
	if (ft_strcmp(tmp, str2))
		ret = 1;
	free(tmp);
	return (0);
}

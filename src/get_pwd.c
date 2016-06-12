/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 14:14:02 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/12 14:20:06 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_pwd(void)
{
	char	*tmp;
	char	*ret;

	if (!(tmp = ft_strnew(BUFF_SIZE)))
		return (NULL);
	getcwd(tmp, BUFF_SIZE);
	if (!(ret = ft_strdup(tmp)))
	{
		free(tmp);
		return (NULL);
	}
	return (ret);
}

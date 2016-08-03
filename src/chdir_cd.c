/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chdir_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 12:32:02 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/03 12:32:06 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*chdir_cd(char *str)
{
	char	*owd;

	if (!(owd = get_pwd()))
	{
		free(str);
		return (NULL);
	}
	if (chdir(str))
	{
		free(owd);
		free(str);
		return (NULL);
	}
	return (owd);
}

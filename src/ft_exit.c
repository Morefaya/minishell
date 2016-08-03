/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 16:43:36 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/11 16:47:40 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <termios.h>

int	ft_exit(void)
{
	struct termios term;

	tcgetattr(0, &term);
	term.c_cc[VINTR] = 3;
	term.c_cc[VEOF] = 4;
	tcsetattr(0, TCSANOW, &term);
	exit(0);
	return (1);
}

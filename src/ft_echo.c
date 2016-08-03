/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 16:57:02 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/03 12:37:42 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_quote(char *str)
{
	int		ret;

	ret = 0;
	while (*str)
		ret += (ft_strchr("\"\'", (int)*str++)) ? 1 : 0;
	return (ret);
}

static void	join_echo(char **str)
{
	char	*line;
	char	*tmp_1;

	if (get_next_line(0, &line) <= 0)
		return ;
	tmp_1 = ft_strjoin(*str, "\n");
	free(*str);
	*str = ft_strjoin(tmp_1, line);
	free(tmp_1);
	free(line);
}

int			ft_echo(t_list *lst, t_list **env_l)
{
	char	*str;
	char	*tmp;
	int		len;

	len = ft_strlen(((t_shell*)(lst->content))->str);
	if (!(tmp = ft_strsub(((t_shell*)(lst->content))->str, 4, len - 4)))
		return (1);
	if (!(str = ft_strtrim(tmp)))
	{
		free(tmp);
		return (1);
	}
	free(tmp);
	while (count_quote(str) % 2)
	{
		ft_putstr("dquote>");
		join_echo(&str);
	}
	if (ft_strchr(str, (int)'$'))
		insert_var(&str, *env_l);
	put_echo(str);
	ft_putchar('\n');
	free(str);
	return (1);
}

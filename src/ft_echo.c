/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 16:57:02 by jcazako           #+#    #+#             */
/*   Updated: 2016/07/09 17:57:17 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	put_echo(char *str)
{
	int	cond;

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
		if (ft_strchr("\"\'", (int)*str))
		{
			if (*str == '\'')
				while (*str && *str != '\'')
					ft_putchar(*str++);
			else if (*str == '\"')
				while (*str && *str != '\"')
					ft_putchar(*str++);
			str++;
			/*while (*str && !ft_strchr("\"\'", (int)*str))
				ft_putchar(*str++);
			str = (!ft_strchr("\"\'", (int)*str)) ? ++str : str;*/
		}
	}
}

static int	count_quote(char *str)
{
	int	ret;

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

static char	*get_str_ins(char *str)
{
	int		i;
	char	*link_1;
	char	*link_2;
	char 	*new;

	i = 0;
	while (str[i] && str[i] != '$')
		i++;
	if (!(link_1 = ft_strsub(str, 0, i)))
		return (NULL);
	str += i;
	while (*str && !ft_strchr(" \t\n", *str))
		str++;
	if (!*str)
		return (link_1);
	i = 0;
	while (str[i])
		i++;
	if (!(link_2 = ft_strsub(str, 0, i)))
		return (NULL);
	if (!(new = ft_strjoin(link_1, link_2)))
		return (NULL);
	free(link_1);
	free(link_2);
	return (new);
}

static char	*next_env_var(char *str, int nb)
{
	int	i;

	i = 0;
	while (*str && *str != '$' && i < nb)
	{
		if (*str == '$')
			i++;
		str++;
	}
	if (!*str)
		return (NULL);
	else
		return (str);
}

static void	insert_var(char **str, t_list *env_l)
{
	char	*tmp_1;
	char	*tmp_2;
	int		len;
	char	*var;
	char	*env_v;
	char	*str_ins;
	int	nb_env;

	tmp_1 = *str;
	tmp_2 = NULL;
	nb_env = 1;
	while ((tmp_1 = next_env_var(*str, nb_env++)))
	{
		len = 0;
		tmp_1++;
		while (!ft_strchr(" \t\"\'", (int)tmp_1[len]))
			len++;
		if (!(env_v = ft_strsub(tmp_1, 0, len)))
			return ;
		if (!(var = get_var_env(env_v, env_l)))
			if (!(var = ft_strdup("")))
				return ;
		if (!(str_ins = get_str_ins(*str)))
			return ;
		tmp_2 = *str;
		*str = ft_strinsert(str_ins, var, tmp_1 - *str - 1);
		free(tmp_2);
		free(env_v);
		free(var);
		free(str_ins);
	}
}

int		ft_echo(t_list *lst, t_list **env_l)
{
	char	*str;
	char	*tmp;
	int	len;

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

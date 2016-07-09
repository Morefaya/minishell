/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 22:52:18 by jcazako           #+#    #+#             */
/*   Updated: 2016/07/09 22:56:56 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_str_ins(char *str)
{
	int		i;
	char	*link_1;
	char	*link_2;
	char	*new;

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
	int		i;
	int		nb_s;

	i = 0;
	nb_s = 0;
	while (str[i])
	{
		if (str[i++] == '$')
			nb_s++;
	}
	i = 0;
	while (*str && *str != '$' && i < nb)
	{
		if (*str == '$')
			i++;
		str++;
	}
	if (!*str || nb > nb_s)
		return (NULL);
	else
		return (str);
}

static int	check_quotes(char *str, char *tmp_1)
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

static void	deal_insert(char *tmp_1, char **tmp_2, char **str, t_list *env_l)
{
	int		len;
	char	*var;
	char	*env_v;
	char	*str_ins;

	len = 0;
	while (!ft_strchr(" \t\"\'", (int)tmp_1[len]))
		len++;
	if (!(env_v = ft_strsub(tmp_1, 0, len)))
		return ;
	if (!(var = get_var_env(env_v, env_l)))
		if (!(var = ft_strdup("")))
			return ;
	if (!(str_ins = get_str_ins(*str)))
		return ;
	*tmp_2 = *str;
	*str = ft_strinsert(str_ins, var, tmp_1 - *str - 1);
	free(*tmp_2);
	free(env_v);
	free(var);
	free(str_ins);
}

void		insert_var(char **str, t_list *env_l)
{
	char	*tmp_1;
	char	*tmp_2;
	int		nb_env;

	tmp_1 = *str;
	tmp_2 = NULL;
	nb_env = 1;
	while ((tmp_1 = next_env_var(*str, nb_env++)))
	{
		if (check_quotes(*str, tmp_1))
		{
			tmp_1++;
			deal_insert(tmp_1, &tmp_2, str, env_l);
		}
	}
}

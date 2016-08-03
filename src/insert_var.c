/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 22:52:18 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/03 12:35:46 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_str_ins(char *str, char *env_v)
{
	char	*tmp;
	char	*link_1;
	char	*link_2;
	char	*new;

	if (!(tmp = ft_strstr(str, env_v)))
		return (str);
	if (!(link_1 = ft_strsub(str, 0, tmp - str)))
		return (NULL);
	str += (tmp - str);
	while (*str && !ft_strchr(" \t\n\"", *str))
		str++;
	if (!*str)
		return (link_1);
	if (!(link_2 = ft_strsub(str, 0, ft_strlen(str))))
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

	i = 0;
	while (*str)
	{
		if (*str == '$')
		{
			if (i == nb)
				break ;
			else
				i++;
		}
		str++;
	}
	if (!*str)
		return (NULL);
	else
		return (str);
}

static void	deal_insert(char *env_v, char **str, t_list *env_l)
{
	char	*var;
	char	*str_ins;
	char	*tmp;

	if (!(var = get_var_env(env_v + 1, env_l)))
		if (!(var = ft_strdup("")))
			return ;
	if (!(str_ins = get_str_ins(*str, env_v)))
		return ;
	tmp = ft_strstr(*str, env_v);
	free(*str);
	*str = ft_strinsert(str_ins, var, tmp - *str);
	free(var);
	free(str_ins);
}

static char	*get_var(char *tmp_1)
{
	int		len;
	char	*env_v;

	len = 0;
	env_v = NULL;
	while (!ft_strchr(" \t\"\'", tmp_1[len]))
		len++;
	if (!(env_v = ft_strsub(tmp_1, 0, len)))
		return (NULL);
	return (env_v);
}

void		insert_var(char **str, t_list *env_l)
{
	char	*tmp_1;
	int		nb_env;
	char	*env_v;

	tmp_1 = *str;
	nb_env = 0;
	env_v = NULL;
	while ((tmp_1 = next_env_var(*str, nb_env++)))
	{
		if (check_quotes(*str, tmp_1))
		{
			env_v = get_var(tmp_1);
			deal_insert(env_v, str, env_l);
			free(env_v);
			nb_env--;
		}
	}
}

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
	//ft_putendl(new);
	return (new);
}

/*static int	count_nb_s(char *str)
{
	int	i;
	int	nb_s;

	i = 0;
	nb_s = 0;
	while (str[i])
	{
		if (str[i++] == '$')
			nb_s++;
	}
	return (nb_s);
}*/

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
	/*ft_putnbr(nb_l);
	ft_putchar('\t');
	ft_putnbr(nb_r);
	ft_putchar('\n');
	ft_putendl(str);
	ft_putendl(tmp_1);*/
	if (nb_l % 2 && nb_r % 2)
		return (0);
	else
		return (1);
}

static void	deal_insert(char *env_v, char **str, t_list *env_l)
{
	char	*var;
	char	*str_ins;
	char	*tmp;

	//ft_putendl(tmp_1);
	/*while (!ft_strchr(" \t\"\'", (int)tmp_1[len]))
		len++;
	if (!(env_v = ft_strsub(tmp_1, 0, len)))
		return ;*/
	if (!(var = get_var_env(env_v + 1, env_l)))
		if (!(var = ft_strdup("")))
			return ;
	if (!(str_ins = get_str_ins(*str, env_v)))
		return ;
	//ft_putendl(str_ins);
	//tmp = *str;
	tmp = ft_strstr(*str, env_v);
	free(*str);
	*str = ft_strinsert(str_ins, var, tmp - *str);
	free(var);
	free(str_ins);
}

static char	*get_var(char *tmp_1)
{
	int	len;
	char	*env_v;

	len = 0;
	env_v = NULL;
	while (!ft_strchr(" \t\"\'", tmp_1[len]))
		len++;
	if (!(env_v = ft_strsub(tmp_1, 0, len)))
		return (NULL);
	//ft_putendl(env_v);
	return (env_v);
}

void		insert_var(char **str, t_list *env_l)
{
	char	*tmp_1;
	int	nb_env;
	char	*env_v;

	tmp_1 = *str;
	nb_env = 0;
	env_v = NULL;
	while ((tmp_1 = next_env_var(*str, nb_env++)))
	{
		//ft_putendl(tmp_1);
		if (check_quotes(*str, tmp_1))
		{
			//tmp_1++;
			//ft_putendl(*str);
			env_v = get_var(tmp_1);
			//ft_putendl(var);
			deal_insert(env_v, str, env_l);
			free(env_v);
			nb_env--;
		}
	}
}

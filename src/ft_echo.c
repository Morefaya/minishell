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
			str++;
			while (*str && !ft_strchr("\"\'", (int)*str))
				ft_putchar(*str++);
			str = (!ft_strchr("\"\'", (int)*str)) ? ++str : str;
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

int		ft_echo(t_list *lst, t_list **env_l)
{
	char	*str;
	int	len;

	len = ft_strlen(((t_shell*)(lst->content))->str);
	if (!(str = ft_strsub(((t_shell*)(lst->content))->str, 4, len - 4)))
		return (1);
	while (count_quote(str) % 2)
	{
		ft_putstr("dquote>");
		join_echo(&str);
	}
	put_echo(str);
	ft_putchar('\n');
	free(str);
	env_l++;
	return (1);
}

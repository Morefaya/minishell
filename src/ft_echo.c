#include "minishell.h"

/*static void	put_echo(char *str)
{
	if (!str)
		return ;
	ft_putstr(str);
	ft_putendl("@");
	while (*str)
	{
		while (*str && ft_strchr(" \t", (int)*str))
			str++;
		if (*str == '"')
		{
			//ft_putchar('&');
			str++;
			while (*str && *str != '"')
				ft_putchar(*str++);
			//str = (*str == '"') ? ++str : str;
		}
		//if (*str && *str != '"')
		//	ft_putchar(' ');
		//while (*str && !ft_strchr(" \t\"", (int)*str))
		//	ft_putchar(*str++);
	}
}

static int	count_quote(char *str)
{
	int	ret;

	ret = 0;
	while (*str)
		ret += (*str++ == '"') ? 1 : 0;
	return (ret);
}

static void	join_echo(char **str)
{
	char	*tmp_1;
	char	*tmp_2;
	char	*line;
	
	tmp_1 = NULL;
	tmp_2 = NULL;
	if (!(line = ft_strnew(BUFF_SIZE)))
		return ;
	if (get_next_line(0, &line) <= 0)
		return ;
	tmp_2 = ft_strjoin((tmp_1 = ft_strjoin(*str, "\n")), line);
	*str = tmp_2;
	free(tmp_1);
	free(line);	
}*/

int		ft_echo(t_list *lst, t_list **env_l)
{
	char	*str;
	/*int	len;

	len = ft_strlen(((t_shell*)(lst->content))->str);
	if (!(str = ft_strsub(((t_shell*)(lst->content))->str, 4, len - 4)))
		return (1);*/
	str = ((t_shell*)(lst->content))->str;
	ft_putstr(str);
	ft_putendl("@");
	/*while (count_quote(str) % 2)
	{
		ft_putstr("dquote>");
		join_echo(&str);
	}*/
	//put_echo(str);
	//ft_putstr(str);
	ft_putchar('\n');
	//free(str);
	env_l++;
	return (1);
}

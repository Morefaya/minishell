
#include "minishell.h"

static void	fill_arg_t(char *str, char **arg)	
{
	size_t	j;
	int	i;

	i = 0;
	if (!str)
		return ;
	while (*str)
	{
		j = 0;
		while (*str && ft_check_charset(*str, " /t/n"))
			str++;
		while (str[j] && !ft_check_charset(str[j], " /t/n"))
			j++;
		if (!(arg[i] = ft_strsub(str, 0, j)))
		{
			free_tab2d(arg);
			return ;
		}
		else
		{
			str += j;
			i++;
		}
	}
}

char		**get_arg(char *str)
{
	char	**arg;
	int	nb_wd;
	int	i;

	arg = NULL;
	nb_wd = 0;
	i = 0;
	nb_wd = ft_wordnb(str);
	if (!(arg = (char**)malloc(sizeof(*arg) * nb_wd + 1)))
		return (NULL);
	while (i < nb_wd + 1)
	{
		arg[i] = NULL;
		i++;
	}
	fill_arg_t(str, arg);
	print_tab2d(arg);
	return (arg);
}

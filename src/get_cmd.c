
#include "minishell.h"

char	*get_cmd(char *str)
{
	size_t	i;
	char	*cmd;

	i = 0;
	cmd = NULL;
	while (str[i] && ft_check_charset(str[i], " \t\n"))
		i++;
	if (!(cmd = ft_strnew(i)))
		return (NULL);
	ft_strncpy(cmd, str, i);
	return (cmd);
}

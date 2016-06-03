#include "minishell.h"

static char	**trim_split(char **cmd_tab)
{
	int	i;
	char	*tmp;

	tmp = NULL;
	i = 0;	 
	while (cmd_tab[i])
	{
		tmp = cmd_tab[i];
		if (!(cmd_tab[i] = ft_strtrim(cmd_tab[i])))
		{
			i = 0;
			while (cmd_tab[i])
			{
				free(cmd_tab[i]);
				i++;
			}
			free(cmd_tab);
			return (NULL);
		}
		free(tmp);
		i++;
	}
	return (cmd_tab);
}

char		**read_cmd(void)
{
	char	*line;
	char	**cmd_tab;

	cmd_tab = NULL;
	if (get_next_line(0, &line) <= 0)
		return (NULL);
	if (ft_strstr(line, "exit"))
		exit(0);
	free(line);
	if (!(cmd_tab = ft_strsplit(line, ';')))
		return (NULL);
	if (!(cmd_tab = trim_split(cmd_tab)))
		return (NULL);
	return (cmd_tab);
}

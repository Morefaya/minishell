#include "minishell.h"

char	**get_paths_vars(t_list *env_l)
{
	char	**path;
	char	*tmp;

	path = NULL;
	tmp = NULL;
	while (env_l)
	{
		if (ft_strncmp(((t_shell*)(env_l->content))->str, "PATH=", 5))
			break;
		env_l = env_l->next;
	}
	if (!(tmp = ft_strsub(((t_shell*)(env_l->content))->str, 5,
		ft_strlen(((t_shell*)(env_l->content))->str) - 5)))
		return (NULL);
	if (!(path = ft_strsplit(tmp, ';')))
	{
		free(tmp);
		return (NULL);
	}
	return (path);
}

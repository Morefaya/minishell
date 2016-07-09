

#include "minishell.h"

static void	free_son(char **arg, char **env_t)
{
	free_tab2d(arg);
	free_tab2d(env_t);
}

static void	exe_file(char *str, char **arg, char **env_t, int ret)
{
	char	*cmd;

	cmd = NULL;
	if (!(cmd = get_cmd(str)))
		return (free_son(env_t, arg));
	if ((ret == -1) && (execve(cmd, arg, env_t) == -1))
	{
		ft_putstr("minishell: command not found: ");
		ft_putstr(cmd);
	}
	free(cmd);
	free_son(arg, env_t);
}

static void	son_process(char *cmd, t_list *env_l)
{
	int		ret;
	char	*cmd_path;
	char	**arg;
	char	**env_t;
	int		i;
	char	**path_t;

	i = 0;
	ret = -1;
	signal(SIGINT, SIG_DFL);
	if (!(env_t = tab2d_lst(env_l)))
		return ;
	if (!(arg = ft_strstr_split(cmd, " \t\n")))
	{
		free_tab2d(env_t);
		return ;
	}
	path_t = get_paths_vars(env_l);
	if (path_t)
	{
		while (path_t[i])
		{
			if (!(cmd_path = make_cmd_path(path_t[i], cmd)))
			{
				free_tab2d(arg);
				free_tab2d(env_t);
				return ;
			}
			ret = execve(cmd_path, arg, env_t);
			free(cmd_path);
			i++;
		}
	}
	free_tab2d(path_t);
	exe_file(cmd, arg, env_t, ret);
	ft_putchar('\n');
	exit(ret);
}

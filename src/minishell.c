
#include "minishell.h"

int	minishell(t_list *cmd_l, t_list *env_l)
{
	pid_t	pid;

	while (cmd_l)
	{
		if (!builtins(cmd_l))
			path_cmd(cmd_l, env_l);
		cmd_l = cmd_l->next;
	}
	if (!(pid = fork()))
	{
		signal(SIGINT, SIG_DFL);
		execve("/bin/ls", av, env);
	}
	else if (pid > 0)
	{
		signal(SIGINT, SIG_IGN);
		wait(&i);
	}
	ft_lstdel(&cmd_l, (void(*)(void*, size_t))del_content);
	return (0);
}

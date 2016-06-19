#include "minishell.h"

static void	set_it(char *arg, t_list **env_c)
{
	t_shell	content;
	t_list	*cmd;
	char	*str;

	if (!(str = ft_strjoin("setenv ", arg)))
		return ;
	content.str = str;
	if (!(cmd = ft_lstnew(&content, sizeof(content))))
		return ;
	ft_setenv(cmd, env_c);
	ft_lstdelone(&cmd, (void(*)(void*, size_t))del_content);
}

static void	execute(char **cmd, t_list **env_c, char **path_t)
{
	char	*str;
	int	i;
	int	j;
	int	len;
	t_shell content;
	t_list	*cmd_l;

	i = 0;
	j = 0;
	len = 0;
	cmd_l = NULL;
	if (!cmd)
		return ;
	while (cmd[i])
	{
		len += ft_strlen(cmd[i]);
		i++;
	}
	if (!(str = ft_strnew(len + i)))
		return ;
	while (cmd[j])
	{
		ft_strcat(str, cmd[j]);
		if (j != i + 1)
			str[ft_strlen(str)] = ' ';
		j++;
	}
	content.str = str;
	if (!(cmd_l = ft_lstnew(&content, sizeof(content))))
		return ;
	minishell(cmd_l, env_c, path_t);
}

static int	unset_it(t_list *unset, t_list **env_c)
{
	t_list	*cmd;
	t_shell	content;
	char	*str;

	cmd = NULL;
	while (unset)
	{
		str = ((t_shell*)(unset->content))->str;
		if (!(content.str = ft_strjoin("unsetenv ", str)))
			return (0);
		if (!(cmd = ft_lstnew(&content, sizeof(content))))
			return (0);
		ft_unsetenv(cmd, env_c);
		ft_lstdel(&cmd, (void(*)(void*, size_t))del_content);
		unset = unset->next;
	}
	return (1);
}

int		rt_env(t_list *cmd_l, t_list *env_l, char **path_t)
{
	t_list	*env_c;
	char	**arg;
	t_list	*unset;
	int	i;

	i = 1;
	if (!(env_c = lstenv_cpy(env_l)))
		return (1);
	if (!(arg = ft_strstr_split(((t_shell*)(cmd_l->content))->str, " \t\n")))
	{
		ft_lstdel(&env_c, (void(*)(void*, size_t))del_content);
		return (1);
	}
	if (!arg[i])
	{
		free_tab2d(arg);
		print_lst(env_c);
		ft_lstdel(&env_c, (void(*)(void*, size_t))del_content);
		return (1);
	}
	unset = checkout(arg, &i, env_c);
	if (!(unset_it(unset, &env_c)))
		return (1);
	while (arg[i])
	{
		if (!ft_strchr(arg[i], '='))
			break ;
		set_it(arg[i], &env_c);
		i++;
	}
	if (arg[i])
		execute(arg + i, &env_c, path_t);
	else
		print_lst(env_c);
	free_tab2d(arg);
	ft_lstdel(&env_c, (void(*)(void*, size_t))del_content);
	return (1);
}

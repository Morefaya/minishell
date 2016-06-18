#include "minishell.h"

/*static t_list	*checkout(char **arg, int *i)
{
	t_list	*unset_l;
	t_list	*first_l;
	t_shell	content;

	unset_l = NULL;
	first_l = NULL;
	while (arg[*i])
	{
		if (arg[*i][0] != '-')
			break ;
		if (arg[*i][1] == 'u')
		{
			if (!(content.str = check_u(arg[*i])))
			{
				if (!(content.str = check_u(arg[++(*i)])))
				{
					ft_putendl("env: option requires an argument -- u");
					//del
					return (NULL);
				}
			}
			
		}

		(*i)++;
	}
}*/
/*
static char	*check_option(char *str, t_list **env_c, int *illegal)
{
	int	len;

	if (*str++ != '-')
		return (NULL);
	len = ft_strlen(str);
	if (*str == 'u')
	{
		str++;
		return (ft_strsub(str, 0, len - 1));
	}
	else if (*str == 'i')
	{
		ft_lstdel(env_c, (void(*)(void*, size_t))del_content);
		return (NULL);
	}
	else if (*str)
	{
		putillegal_opt_env(*str);
		*illegal = 1;
		return (NULL);
	}
	return (NULL);
}

static void	unset_it(char *arg, t_list **env_c)
{
	t_shell	content;
	t_list	*cmd;
	char	*str;

	if (!(str = ft_strjoin("unsetenv ", arg)))
		return ;
	content.str = str;
	if (!(cmd = ft_lstnew(&content, sizeof(content))))
		return ;
	ft_unsetenv(cmd, env_c);
	ft_lstdelone(&cmd, (void(*)(void*, size_t))del_content);
}

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
	t_shell	content;
	t_list	*cmd_c;

	content.str = ft_strdup(*cmd);
	cmd_c = ft_lstnew(&content, sizeof(content));
	if (builtins())
	while (*cmd)
	{
		ft_putendl(*cmd);
		cmd++;
	}
	env_c++;
	path_t++;
}*/

int		rt_env(t_list *cmd_l, t_list *env_l, char **path_t)
{
	t_list	*env_c;
	char	**arg;
	//char	*unset;
	int	i;
	int	illegal;

	i = 1;
	illegal = 0;
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
	checkout(arg, &i, env_c);
	/*if ((unset = check_option(arg[i], &env_c, &illegal)))
	{
		if (!*unset)
		{
			i++;
			if (arg[i])
				unset_it(arg[i], &env_c);
		}
		else
			unset_it(unset, &env_c);
	}
	if (illegal)
	{
		ft_lstdel(&env_c, (void(*)(void*, size_t))del_content);
		free_tab2d(arg);
		return (1);
	}
	i = (unset) ? ++i : i;
	while (arg[i])
	{
		if (!ft_strchr(arg[i], '='))
			break ;
		set_it(arg[i], &env_c);
		i++;
	}
	if (arg[i])
		execute(arg + i, &env_c, path_t);
	print_lst(env_c);*/
	ft_lstdel(&env_c, (void(*)(void*, size_t))del_content);
	path_t++;
	return (1);
}

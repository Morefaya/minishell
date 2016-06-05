#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <signal.h>
# include <unistd.h>

typedef struct	s_shell
{
	char	*str;
}		t_shell;

typedef struct	s_opt_env
{
	int	i;
	int	u;
}		t_opt_env;

t_list		*lst_tab2d(char **tab);
void		print_lst(t_list *lst);
void		del_content(t_shell *content, size_t size);
t_list		*read_cmd(void);
void		print_tab2d(char **tab);
void		free_tab2d(char **tab);
int		builtins(t_list *lst);
char		**get_paths_vars(t_list *env_l);
char		*make_cmd_path(char *path, t_list *cmd_l);
char		**get_arg(char *str);
char		*get_cmd(char *str);
char		**tab2d_lst(t_list *lst);
int		minishell(t_list *cmd_l, t_list *env_l);
#endif

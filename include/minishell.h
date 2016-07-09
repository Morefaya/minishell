/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 16:31:43 by jcazako           #+#    #+#             */
/*   Updated: 2016/07/09 23:02:24 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define UNSET "unsetenv"
# define SET "setenv"
# define CD "cd"
# define ECHO "echo"
# define ENV "env"
# define EXIT "exit"

# include "libft.h"
# include <signal.h>
# include <unistd.h>

typedef struct	s_shell
{
	char		*str;
}				t_shell;

t_list			*lst_tab2d(char **tab);
void			print_lst(t_list *lst);
void			del_content(t_shell *content, size_t size);
t_list			*read_cmd(void);
void			print_tab2d(char **tab);
void			free_tab2d(char **tab);
int				builtins(t_list *lst, t_list **env_l);
char			**get_paths_vars(t_list *env_l);
char			*make_cmd_path(char *path, char *str);
char			**get_arg(char *str);
char			*get_cmd(char *str);
char			**tab2d_lst(t_list *lst);
int				minishell(t_list *cmd_l, t_list **env_l);
t_list			*lstenv_cpy(t_list *env);
void			putillegal_opt_env(char a);
void			delete_env(char **m, t_list **env_c);
int				ft_unsetenv(t_list *cmd_l, t_list **env_l);
int				check_arg(char *str);
void			del_linkenv(char *u_env, t_list **env_l);
int				ft_setenv(t_list *cmd_l, t_list **env_l);
int				ft_env(t_list *cmd_l, t_list *env_l);
void			unset_ft_env(char **str, t_list **env_c);
void			set_env(char *str, t_list **env_l);
void			freed(t_list **to_free);
void			freed_all(t_list **begin_free);
void			unsetenv_format(void);
void			exe_cmd(char *cmd, t_list *env_l);
int				ft_exit(void);
int				ft_cd(t_list *lst, t_list **env_l);
int				tablen(char **tab);
char			*get_a_pwd(void);
char			*get_pwd(void);
char			*get_var_env(char *env_var, t_list *env_l);
char			*chdir_cd(char *str);
int				cd_set(char *owd, char *awd, char *cmd, t_list **env_l);
int				cmp_env(char *str1, char *str2);
char			*gt_env_var(char *str);
t_list			*checkout(char **arg, int *i, t_list *env_c, int *illegal);
char			*check_u(char *str);
char			*trim_name(char *str);
void			set_it(char *arg, t_list **env_c);
char			*execute_2(char **cmd);
void			execute(char **cmd, t_list **env_c);
int				unset_it(t_list *unset, t_list **env_c);
int				ft_echo(t_list *lst, t_list **env_l);
void			put_echo(char *str);
void			insert_var(char **str, t_list *env_l);
#endif

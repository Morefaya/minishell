/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 16:31:43 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/14 10:43:14 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <signal.h>
# include <unistd.h>

# define BUFF_SIZE 1024

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
int				builtins(t_list *lst, t_list **env_l, char **path_t);
char			**get_paths_vars(t_list *env_l);
char			*make_cmd_path(char *path, char *str);
char			**get_arg(char *str);
char			*get_cmd(char *str);
char			**tab2d_lst(t_list *lst);
int				minishell(t_list *cmd_l, t_list **env_l, char **path_t);
t_list			*lstenv_cpy(t_list *env);
void			putillegal_opt_env(char a);
void			delete_env(char **m, t_list **env_c);
int				ft_unsetenv(t_list *cmd_l, t_list **env_l);
int				check_arg(char *str);
void			del_linkenv(char *u_env, t_list **env_l);
int				ft_setenv(t_list *cmd_l, t_list **env_l);
int				ft_env(t_list *cmd_l, t_list *env_l, char **path_t);
void			unset_ft_env(char **str, t_list **env_c);
void			set_env(char *str, t_list **env_l);
void			freed(t_list **to_free);
void			freed_all(t_list **begin_free);
void			unsetenv_format(void);
void			exe_cmd(char *cmd, t_list *env_l, char **path_t);
int				ft_exit(void);
int				ft_cd(t_list *lst, t_list *env_l);
int				tablen(char **tab);
char			*get_a_pwd(void);
char			*get_pwd(void);
#endif

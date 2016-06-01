#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <signal.h>
# include <unistd.h>

typedef struct	s_shell
{
	char		*str;
}				t_shell;

t_list	*lst_tab2d(char **tab);
void	print_lst(t_list *lst);

#endif

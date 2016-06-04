#include "minishell.h"

void	ft_env(t_list *cmd_l, t_list *env_l)
{
	print_list(cmd_l);
	print_list(env_l);
}

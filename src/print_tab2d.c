#include "minishell.h"

void	print_tab2d(char **tab)
{
	if (!tab)
		return ;
	while (*tab)
	{
		ft_putendl(*tab);
		tab++;
	}
}

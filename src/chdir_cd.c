
#include "minishell.h"

char		*chdir_cd(char *str)
{
	char	*owd;

	if (!(owd = get_pwd()))
	{
		free(str);
		return (NULL);
	}
	if (chdir(str))
	{
		free(owd);
		free(str);
		return (NULL);
	}
	return (owd);
}

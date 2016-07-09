#include "libft.h"

char	*ft_strinsert(char *str, char *insert, size_t pos)
{
	int	len_s;
	int	len_i;
	char	*new;

	len_s = 0;
	len_i = 0;
	if (!str)
		return (NULL);
	else
	{
		len_s = ft_strlen(str);
		if (insert)
			len_i = ft_strlen(insert);
	}
	if (!(new = ft_strnew(len_s + len_i)))
		return (NULL);
	ft_strncat(new, str, pos);
	ft_strcat(new, insert);
	ft_strcat(new, str + pos);
	return (new);
}

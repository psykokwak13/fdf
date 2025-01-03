typedef struct valuestruct // structure pour les valeurs collectés de split -> color = valeur hexidecimal apres la virgule SI IL Y EN A
{
	int color;
	int z_value;
}v_struct;

int hex_to_int(const char *hex_str)
{
	int result;
	int digit;
	char c;

	result = 0;
	while (*hex_str != ',')
		hex_str++;
	hex_str = hex_str + 3;
	while (*hex_str != '\0') {
		c = *hex_str;
		if (c >= '0' && c <= '9')
			digit = c - '0';
		else if (c >= 'A' && c <= 'F')
			digit = c - 'A' + 10;
		else if (c >= 'a' && c <= 'f')
			digit = c - 'a' + 10;
		else
			return (-1);
		result = result * 16 + digit;
		hex_str++;
	}

	return (result);
}


int	ft_atoi(const char *str)
{
	int	i ;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

v_struct    parsenbr(char *charnbr)
{
	int i;
	v_struct valuestruct;

	valuestruct.color = 0;
	valuestruct.z_value = 0;
	if (!charnbr)
		return (valuestruct);
	i = 0;
	while (charnbr[i] != '\0')
	{
		if (charnbr[i] == ',')
			valuestruct.color = hex_to_int(charnbr);
		i++;
	}
	valuestruct.z_value = ft_atoi(charnbr);
	return (valuestruct);
}

void ligne(int x1, int y1, int x2, int y2, void *win, void *mlx) {
     int dx = abs(x2 - x1);
     int dy = abs(y2 - y1);
     int sx = (x1 < x2) ? 1 : -1;
     int sy = (y1 < y2) ? 1 : -1;
     int err = dx - dy;

     while (1) {
         mlx_pixel_put(mlx, win, x1, y1, 0x3498DB); // Place un pixel

         if (x1 == x2 && y1 == y2)
             break;

         int e2 = 2 * err;

         if (e2 > -dy) {
             err -= dy;
             x1 += sx;
         }
         if (e2 < dx) {
             err += dx;
             y1 += sy;
         }
     }
 }
static void iso(int *x, int *y, int z)
 {
     int previous_x;
     int previous_y;

     previous_x = *x;
     previous_y = *y;
     *x = (previous_x - previous_y) * cos(0.523599);
     *y = -z + (previous_x + previous_y) * sin(0.523599);
 }
int main ()
{
	v_struct test;

	test.z_value = 0;
	test.color = 0;
	test = parsenbr("123");
	printf("z : %d\ncolor : %d",test.z_value,test.color);
}






t_list *ft_lstnew(void *content)
{
    t_list *node;
    node = malloc(sizeof(t_list));
    if (!node)
        return (NULL);
    node->content = content;
    node ->next = NULL;
    return (node);
}

void ft_lstadd_front(t_list **alst, t_list *new)
{
    if (alst)
    {
        if (*alst)
            new->next = *alst;
        *alst = new;
    }
}

int ft_lstsize(t_list *lst)
{
    size_t  i;

    i = 0;
    while (lst)
    {
        lst = lst->next;
        i++;
    }
    return i;
}
t_list *ft_lstlast(t_list *lst)
{
    if (lst == NULL)
        return (NULL);
    while (lst->next)
        lst = lst->next;
    return (lst);
}

void ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (alst)
	{
		if (*alst)
		{
			last = ft_lstlast(*alst);
			last->next = new;
		}
		else
			*alst = new;
	}
}

void ft_lstdelone(t_list *lst, void (*del)(void*))
{
    if (!del)
		return;
	if (lst)
	{
		(*del)(lst->content);
		free(lst);
	}
}

void ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!del || !lst || !*lst)
		return ;
	while (lst && *lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}

void ft_lstiter(t_list *lst, void (*f)(void *))
{
    if (!lst)
        return;
    while (lst)
    {
        f(lst->content);
        lst = lst->next;
    }
}


t_list *ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;

	if (!f || !del)
		return (NULL);
	first = NULL;
	while (lst)
	{
		if (!(new = ft_lstnew((*f)(lst->content))))
		{
			while (first)
			{
				new = first->next;
				(*del)(first->content);
				free(first);
				first = new;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	return (first);
}

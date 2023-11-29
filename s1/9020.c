#include <stdio.h>

void    goldbach(int nb);
int	    ft_is_prime(int nb);

int main(void)
{
    int tc;
    int n;
    int i;
    
    scanf("%d", &tc); 
    while (tc-- > 0)
    {
        scanf("%d", &n); 
        goldbach(n);
    }
    return (0);
}

void    goldbach(int nb)
{
    int n1;
    int n2;

    n1 = 2;
    while (n1 <= nb / 2)
    {
        if (ft_is_prime(n1) == 1 && ft_is_prime(nb - n1) == 1)
            n2 = nb - n1;
        n1++;
    }
    printf("%d %d\n", nb - n2, n2);
}

int	ft_is_prime(int nb)
{
	int i;

	i = 2;
	if (nb == 2)
		return (1);
    if (nb == 1 || nb % 2 == 0)
        return (0);
	while (i <= nb / i)
	{	
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}
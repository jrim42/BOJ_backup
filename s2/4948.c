#include <stdio.h>

int	ft_is_prime(int nb);

int main(void)
{
    int n;
    int i;
    int cnt;
    int flag;
    
    scanf("%d", &n); 
    while (n != 0)
    {
        cnt = 0;
        i = n + 1;
        while (i <= 2*n)
        {
            if (ft_is_prime(i) == 1)
                cnt++;
            i++;
        }
        printf("%d\n", cnt);
        scanf("%d", &n); 
    }
    return (0);
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
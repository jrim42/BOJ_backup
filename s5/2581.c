#include <stdio.h>

int	ft_sqrt(int nb);
int	ft_is_prime(int nb);

int main(void)
{
    int M;
    int N;
    int prime_sum;
    int prime_min;
    int flag;

    scanf("%d", &M);   
    scanf("%d", &N);
    prime_sum = 0;
    flag = 0;
    while (M <= N)
    {
        if (ft_is_prime(M) == 1 && flag == 0)
        {
            prime_sum += M;
            prime_min = M;
            flag = 1;
        }
        else if (ft_is_prime(M) == 1 && flag == 1)
            prime_sum += M;
        M++;
    }
    if (prime_sum == 0)
        printf("-1\n");
    else
    {
        printf("%d\n", prime_sum);
        printf("%d\n", prime_min);
    }
    return (0);
}

int	ft_sqrt(int nb)
{
	int rt;

	rt = 0;
	while (rt * rt < nb && rt < 46341)
		rt++;
	return (rt);
}

int	ft_is_prime(int nb)
{
	int i;
    int limit;

	i = 2;
    limit = ft_sqrt(nb);
	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	while (i <= limit)
	{	
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}
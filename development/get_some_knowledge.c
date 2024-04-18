#include "get_next_line.h"

/*
int     main(void)
{
        int     fd; 
        int     fd1;

        fd = open("42 Support.txt", O_RDONLY);
        close(fd);
        fd1 = open("/Users/patchy/Desktop/Test.txt", O_RDONLY);
        printf("fd = %d\n", fd);
        printf("fd1 = %d\n", fd1);
        return (0);
}*/
/*
int	main()
{
	int	fd;
	int	sz;
	char	*s;

	s = (char *)malloc(100 * sizeof(char));

	fd = open("42 Support.txt", O_RDONLY);
	
	sz = read(fd, s, 100);
	printf("Called read(%d, c, 10). Returned that"
		    	" %d bytes were read. \n", fd, sz);
	s[sz] = '\0';
	printf("Those bytes are as follows: %s\n", s);
	return (0);
}*/
/*
int	ft_count()
{
	static int count = 0;

	count++;
	return (count);
}

int	main(void)
{
	printf("%d", ft_count());
	printf("%d", ft_count());
	printf("%d", ft_count());
	return (0);
}
*/
/*
char	*ft_get_anything()
{
	static char str[] = "Hello World, please help me!";

	return (str);
}

int	main()
{
	printf("%s\n", ft_get_anything());
	printf("%s\n", ft_get_anything());
	return (0);
}*/

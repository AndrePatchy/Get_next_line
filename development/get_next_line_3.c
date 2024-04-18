#include "get_next_line.h"

// Simplest solution with a lot of memory leaks 

char    *get_next_line(int fd) 
{
        static char     *text;
        int     bytes_r;

        if (BUFFER_SIZE <= 0 || fd < 0)
                return (NULL);
        text = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
        while ((bytes_r = read(fd, text, 1)) > 0)
        {   
                return (text);
        }
	free(text);	
        if (bytes_r == 0 || bytes_r == -1) 
                return(NULL);
        return(text);
}
/*
int     main(void)
{
        int     fd;
        char    *tutti;

        fd = open("42Support.txt", O_RDONLY);
        while((tutti = ft_get_next_line(fd)))
        {
                printf("%s", tutti);
                free(tutti);
        }
        return (0);
}
*/

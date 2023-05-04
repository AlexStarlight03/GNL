#include <stdio.h>

char *get_next_line(int fd)
{
    static  t_list  *text_box;
    int     beenread;
    char    *line;

    text_box = NULL;
    line = NULL;
    beenread = 1;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    


}


int main()
{

}
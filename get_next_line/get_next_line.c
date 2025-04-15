#include "get_next_line.h"

char *ft_strjoin(char *s, char c)
{
    char *result;
    int i = 0;
    if(s == NULL)
    {
        result = malloc(2);
        result[0] = c;
        result[1] = 0;
        return(result);
    }
    while(s[i])
        i++;
    result = malloc(i + 2);
    i = 0;
    while(s[i])
    {
        result[i] = s[i];
        i++;
    }
    result[i] = c;
    result[i + 1] = 0;
    free(s);
    return(result);
}

char *get_next_line(int fd)
{
    static int index;
    static int readed;
    static char buffer[BUFFER_SIZE];
    char *line = NULL;
    char c;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return(NULL);
    while(1)
    {
        if(index >= readed)
        {
            index = 0;
            readed = read(fd, buffer, BUFFER_SIZE);
            if(readed <= 0)
                break;
        }
        c = buffer[index];
        index += 1;
        line = ft_strjoin(line, c);
        if(!line || c == '\n')
            break;
    }
    return(line);
}

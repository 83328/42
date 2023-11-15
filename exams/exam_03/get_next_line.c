/* 
Assignment name : get_next_line
Expected files : get_next_line.c, get_next_line.h
Allowed functions: read, free, malloc
--------------------------------------------------------------------------------

Write a function named get_next_line which prototype should be:
char *get_next_line(int fd);


Your function must return a line that has been read from the file descriptor passed as parameter. What we call a "line that has been read" is a succession of 0 to n characters that end with '\n' (ascii code 0x0a) or with End Of File (EOF).

The line should be returned including the '\n' in case there is one at the end of the line that has been read. When you've reached the EOF, you must store the current buffer in a char * and return it. If the buffer is empty you must return NULL.

In case of error return NULL. In case of not returning NULL, the pointer should be free-able. Your program will be compiled with the flag -D BUFFER_SIZE=xx, which has to be used as the buffer size for the read calls in your functions.

Your function must be memory leak free. When you've reached the EOF, your function should keep 0 memory allocated with malloc, except the line that has been returned.

Calling your function get_next_line() in a loop will therefore allow you to read the text available on a file descriptor one line at a time until the end of the text, no matter the size of either the text or one of its lines.

Make sure that your function behaves well when it reads from a file, from the standard output, from a redirection, etc...

No call to another function will be done on the file descriptor between 2 calls of get_next_line(). Finally we consider that get_next_line() has an undefined behaviour when reading from a binary file. 
*/

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BURRER_SIZE 1000
# endif

char	*read_save_all(int fd, char *static_buffer);
char	*oneline(char *static_buffer);
char	*next_line(char *static_buffer);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *buff);
int	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);

char	*ft_strjoin(char *s1, char *s2)
{
	int	i;
	int	j;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == (char) c)
			return ((char *)str + i);
		i++;
	}
	return (0);
}

char	*read_save_all(int fd, char *static_buffer)
{
	char	*buffer;
	int		size;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	size = 1;
	while (!ft_strchr(static_buffer, '\n') && size)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
		{
			free(static_buffer);
			free(buffer);
			return (NULL);
		}
		buffer[size] = '\0';
		static_buffer = ft_strjoin(static_buffer, buffer);
	}
	free(buffer);
	return (static_buffer);
}

char	*oneline(char *static_buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!static_buffer[i])
		return (NULL);
	while (static_buffer[i] && static_buffer[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (static_buffer[i] && static_buffer[i] != '\n')
	{
		line[i] = static_buffer[i];
		i++;
	}
	if (static_buffer[i] == '\n')
	{
		line[i] = static_buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*next_line(char *static_buffer)
{
	int		i;
	int		j;
	char	*nextline;

	i = 0;
	while (static_buffer[i] && static_buffer[i] != '\n')
		i++;
	if (!static_buffer[i])
	{
		free(static_buffer);
		return (NULL);
	}
	nextline = malloc(sizeof(char) * (BUFFER_SIZE));
	if (!nextline)
		return (NULL);
	i++;
	j = 0;
	while (static_buffer[i])
		nextline[j++] = static_buffer[i++];
	nextline[j] = '\0';
	free(static_buffer);
	return (nextline);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*static_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	static_buffer = read_save_all(fd, static_buffer);
	if (!static_buffer)
		return (NULL);
	line = oneline(static_buffer);
	static_buffer = next_line(static_buffer);
	return (line);
}

int	main(void)
{
	char	*line;
	int		linenumber;
	int		fd;

	linenumber = 1;
	fd = open("test.txt", O_RDONLY);
	while (linenumber < 10)
	{
		line = get_next_line(fd);
		printf("@line %d: %s", linenumber, line);
		linenumber++;
	}
	close(fd);
	return (0);
}
/* 
#include <unistd.h>
#include <stdlib.h>

int	ft_str_length(char *string)
{
	int	index;
#include <stdarg.h>
#include <unistd.h>

int ft_putchar(char c, int *len)
{
	*len = *len + 1;
	return(write(1, &c, 1));
}

void ft_putstr(char *str, int *len)
{
	long unsigned int i = 0;
	
	 if(!str)
	 	ft_putstr("(null)", len);
	 else
	 {
		while(str[i])
		{
			ft_putchar(str[i], len);
			i++;
		}
	 }
}

void ft_putnbr(int n, int *len)
{
	if(n == -2147483648)
		ft_putstr("-2147483648", len);
	else
	{
		if(n < 0)
		{
			ft_putchar('-', len);
			n = -n;
		}
		if (n > 9)
			ft_putnbr(n / 10, len);
		ft_putchar((n%10) + '0', len);
	}
}

void ft_puthex(int n, int *len)
{
	unsigned int	u = (unsigned int)n;	
	if (n > 15)
		ft_puthex(n / 16, len);
	ft_putchar("0123456789abcdef"[u % 16], len);
}

void conditions(const char *next, va_list *args, int *len)
{
	if(*next == 's')
		ft_putstr(va_arg(*args, char *), len);
	else if (*next == 'd')
		ft_putnbr(va_arg(*args, int), len);
	else
		ft_puthex(va_arg(*args, int), len);
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	int len = 0;
	int i = 0;

	va_start(args, str);
	
	while (str[i]) 
	{
		if (str[i] == '%')
			conditions(&str[++i], &args, &len);
		else
			ft_putchar(str[i], &len);
		i++;
	}
	va_end(args);
	return(len);
}

int main()
{
	ft_printf("%s\n", "toto");
	printf("%s\n", "toto");
	printf("\n");
	ft_printf("Magic %s is %d\n", "number", 42);
	printf("Magic %s is %d\n", "number", 42);
	printf("\n");
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("Hexadecimal for %d is %x\n", 42, 42);
}

/* #include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int ft_putchar(char c, int *len)
{
	*len = *len + 1;
	return(write(1, &c, 1));
}

int ft_putstr(char *str, int *len)
{
	long unsigned int i = 0;
	int res = 0;
	
	if(!str)
		ft_putstr("(null)", len);
	else
	{
		while(str[i])
		{
			ft_putchar(str[i], len);
			i++;
		}
	}
	return(res);
}

int ft_putnbr(int n, int *len)
{
	int res = 0;
	
	if(n == -2147483648)
		res = ft_putstr("-2147483648", len);
	else
	{
		if(n < 0)
		{
			res = ft_putchar('-', len);
			n = -n;
		}
		if(n > 9)
		{
			ft_putnbr(n / 10, len);
			ft_putnbr(n % 10, len);			
		}
		if(n < 10)
		{
			res = ft_putchar((n%10)+'0', len);
		}
	}
	return(res);
}

int ft_puthex(int n, char c, int *len)
{
	unsigned int	u = (unsigned int)n;
	int		ret = 0;
	
	if (u >= 16)
	{
		ft_puthex(u / 16, c, len);
		ft_puthex(u % 16, c, len);
	}
	else
	{
		if (c == 'x')
			ret = ft_putchar("0123456789abcdef"[u % 16], len);
	}
	return (ret);
}

int conditions(const char *next, va_list *a, int *len)
{
	int res = 0;
	
	if(*next == 's')
		res = ft_putstr(va_arg(*a, char *), len);
	else if (*next == 'd')
		res = ft_putnbr(va_arg(*a, int), len);
	else
		res = ft_puthex(va_arg(*a, int), *next, len);
	return(res);
}

int	ft_printf(const char *str, ...)
{
	va_list ap; //ap = argument pointer
	int len = 0;
	int error = 0;

	va_start(ap, str);
	while(*str)
	{
		if(*str== '%')#include <stdarg.h>
#include <unistd.h>

int ft_putchar(char c, int *len)
{
	*len = *len + 1;
	return(write(1, &c, 1));
}

void ft_putstr(char *str, int *len)
{
	long unsigned int i = 0;
	
	 if(!str)
	 	ft_putstr("(null)", len);
	 else
	 {
		while(str[i])
		{
			ft_putchar(str[i], len);
			i++;
		}
	 }
}

void ft_putnbr(int n, int *len)
{
	if(n == -2147483648)
		ft_putstr("-2147483648", len);
	else
	{
		if(n < 0)
		{
			ft_putchar('-', len);
			n = -n;
		}
		if (n > 9)
			ft_putnbr(n / 10, len);
		ft_putchar((n%10) + '0', len);
	}
}

void ft_puthex(int n, int *len)
{
	unsigned int	u = (unsigned int)n;	
	if (n > 15)
		ft_puthex(n / 16, len);
	ft_putchar("0123456789abcdef"[u % 16], len);
}

void conditions(const char *next, va_list *args, int *len)
{
	if(*next == 's')
		ft_putstr(va_arg(*args, char *), len);
	else if (*next == 'd')
		ft_putnbr(va_arg(*args, int), len);
	else
		ft_puthex(va_arg(*args, int), len);
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	int len = 0;
	int i = 0;

	va_start(args, str);
	
	while (str[i]) 
	{
		if (str[i] == '%')
			conditions(&str[++i], &args, &len);
		else
			ft_putchar(str[i], &len);
		i++;
	}
	va_end(args);
	return(len);
}

int main()
{
	ft_printf("%s\n", "toto");
	printf("%s\n", "toto");
	printf("\n");
	ft_printf("Magic %s is %d\n", "number", 42);
	printf("Magic %s is %d\n", "number", 42);
	printf("\n");
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("Hexadecimal for %d is %x\n", 42, 42);
}

/* #include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int ft_putchar(char c, int *len)
{
	*len = *len + 1;
	return(write(1, &c, 1));
}

int ft_putstr(char *str, int *len)
{
	long unsigned int i = 0;
	int res = 0;
	
	if(!str)
		ft_putstr("(null)", len);
	else
	{
		while(str[i])
		{
			ft_putchar(str[i], len);
			i++;
		}
	}
	return(res);
}

int ft_putnbr(int n, int *len)
{
	int res = 0;
	
	if(n == -2147483648)
		res = ft_putstr("-2147483648", len);
	else
	{
		if(n < 0)
		{
			res = ft_putchar('-', len);
			n = -n;
		}
		if(n > 9)
		{
			ft_putnbr(n / 10, len);
			ft_putnbr(n % 10, len);			
		}
		if(n < 10)
		{
			res = ft_putchar((n%10)+'0', len);
		}
	}
	return(res);
}

int ft_puthex(int n, char c, int *len)
{
	unsigned int	u = (unsigned int)n;
	int		ret = 0;
	
	if (u >= 16)
	{
		ft_puthex(u / 16, c, len);
		ft_puthex(u % 16, c, len);
	}
	else
	{
		if (c == 'x')
			ret = ft_putchar("0123456789abcdef"[u % 16], len);
	}
	return (ret);
}

int conditions(const char *next, va_list *a, int *len)
{
	int res = 0;
	
	if(*next == 's')
		res = ft_putstr(va_arg(*a, char *), len);
	else if (*next == 'd')
		res = ft_putnbr(va_arg(*a, int), len);
	else
		res = ft_puthex(va_arg(*a, int), *next, len);
	return(res);
}

int	ft_printf(const char *str, ...)
{
	va_list ap; //ap = argument pointer
	int len = 0;
	int error = 0;

	va_start(ap, str);
	while(*str)#include <stdarg.h>
#include <unistd.h>

int ft_putchar(char c, int *len)
{
	*len = *len + 1;
	return(write(1, &c, 1));
}

void ft_putstr(char *str, int *len)
{
	long unsigned int i = 0;
	
	 if(!str)
	 	ft_putstr("(null)", len);
	 else
	 {
		while(str[i])
		{
			ft_putchar(str[i], len);
			i++;
		}
	 }
}

void ft_putnbr(int n, int *len)
{
	if(n == -2147483648)
		ft_putstr("-2147483648", len);
	else
	{
		if(n < 0)
		{
			ft_putchar('-', len);
			n = -n;
		}
		if (n > 9)
			ft_putnbr(n / 10, len);
		ft_putchar((n%10) + '0', len);
	}
}

void ft_puthex(int n, int *len)
{
	unsigned int	u = (unsigned int)n;	
	if (n > 15)
		ft_puthex(n / 16, len);
	ft_putchar("0123456789abcdef"[u % 16], len);
}

void conditions(const char *next, va_list *args, int *len)
{
	if(*next == 's')
		ft_putstr(va_arg(*args, char *), len);
	else if (*next == 'd')
		ft_putnbr(va_arg(*args, int), len);
	else
		ft_puthex(va_arg(*args, int), len);
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	int len = 0;
	int i = 0;

	va_start(args, str);
	
	while (str[i]) 
	{
		if (str[i] == '%')
			conditions(&str[++i], &args, &len);
		else
			ft_putchar(str[i], &len);
		i++;
	}
	va_end(args);
	return(len);
}

int main()
{
	ft_printf("%s\n", "toto");
	printf("%s\n", "toto");
	printf("\n");
	ft_printf("Magic %s is %d\n", "number", 42);
	printf("Magic %s is %d\n", "number", 42);
	printf("\n");
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("Hexadecimal for %d is %x\n", 42, 42);
}

/* #include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int ft_putchar(char c, int *len)
{
	*len = *len + 1;
	return(write(1, &c, 1));
}

int ft_putstr(char *str, int *len)
{
	long unsigned int i = 0;
	int res = 0;
	
	if(!str)
		ft_putstr("(null)", len);
	else
	{
		while(str[i])
		{
			ft_putchar(str[i], len);
			i++;
		}
	}
	return(res);
}

int ft_putnbr(int n, int *len)
{
	int res = 0;
	
	if(n == -2147483648)
		res = ft_putstr("-2147483648", len);
	else
	{
		if(n < 0)
		{
			res = ft_putchar('-', len);
			n = -n;
		}
		if(n > 9)
		{
			ft_putnbr(n / 10, len);
			ft_putnbr(n % 10, len);			
		}
		if(n < 10)
		{
			res = ft_putchar((n%10)+'0', len);
		}
	}
	return(res);
}

int ft_puthex(int n, char c, int *len)
{
	unsigned int	u = (unsigned int)n;
	int		ret = 0;
	
	if (u >= 16)
	{
		ft_puthex(u / 16, c, len);
		ft_puthex(u % 16, c, len);
	}
	else
	{
		if (c == 'x')
			ret = ft_putchar("0123456789abcdef"[u % 16], len);
	}
	return (ret);
}

int conditions(const char *next, va_list *a, int *len)
{
	int res = 0;
	
	if(*next == 's')
		res = ft_putstr(va_arg(*a, char *), len);
	else if (*next == 'd')
		res = ft_putnbr(va_arg(*a, int), len);
	else
		res = ft_puthex(va_arg(*a, int), *next, len);
	return(res);
}

int	ft_printf(const char *str, ...)
{
	va_list ap; //ap = argument pointer
	int len = 0;
	int error = 0;

	va_start(ap, str);
	while(*str)
	{
		if(*str== '%')
			error = conditions(++str, &ap, &len);#include <stdarg.h>
#include <unistd.h>

int ft_putchar(char c, int *len)
{
	*len = *len + 1;
	return(write(1, &c, 1));
}

void ft_putstr(char *str, int *len)
{
	long unsigned int i = 0;
	
	 if(!str)
	 	ft_putstr("(null)", len);
	 else
	 {
		while(str[i])
		{
			ft_putchar(str[i], len);
			i++;
		}
	 }
}

void ft_putnbr(int n, int *len)
{
	if(n == -2147483648)
		ft_putstr("-2147483648", len);
	else
	{
		if(n < 0)
		{
			ft_putchar('-', len);
			n = -n;
		}
		if (n > 9)
			ft_putnbr(n / 10, len);
		ft_putchar((n%10) + '0', len);
	}
}

void ft_puthex(int n, int *len)
{
	unsigned int	u = (unsigned int)n;	
	if (n > 15)
		ft_puthex(n / 16, len);
	ft_putchar("0123456789abcdef"[u % 16], len);
}

void conditions(const char *next, va_list *args, int *len)
{
	if(*next == 's')
		ft_putstr(va_arg(*args, char *), len);
	else if (*next == 'd')
		ft_putnbr(va_arg(*args, int), len);
	else
		ft_puthex(va_arg(*args, int), len);
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	int len = 0;
	int i = 0;

	va_start(args, str);
	
	while (str[i]) 
	{
		if (str[i] == '%')
			conditions(&str[++i], &args, &len);
		else
			ft_putchar(str[i], &len);
		i++;
	}
	va_end(args);
	return(len);
}

int main()
{
	ft_printf("%s\n", "toto");
	printf("%s\n", "toto");
	printf("\n");
	ft_printf("Magic %s is %d\n", "number", 42);
	printf("Magic %s is %d\n", "number", 42);
	printf("\n");
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("Hexadecimal for %d is %x\n", 42, 42);
}

/* #include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int ft_putchar(char c, int *len)
{
	*len = *len + 1;
	return(write(1, &c, 1));
}

int ft_putstr(char *str, int *len)
{
	long unsigned int i = 0;
	int res = 0;
	
	if(!str)
		ft_putstr("(null)", len);
	else
	{
		while(str[i])
		{
			ft_putchar(str[i], len);
			i++;
		}
	}
	return(res);
}

int ft_putnbr(int n, int *len)
{
	int res = 0;
	
	if(n == -2147483648)
		res = ft_putstr("-2147483648", len);
	else
	{
		if(n < 0)
		{
			res = ft_putchar('-', len);
			n = -n;
		}
		if(n > 9)
		{
			ft_putnbr(n / 10, len);
			ft_putnbr(n % 10, len);			
		}
		if(n < 10)
		{
			res = ft_putchar((n%10)+'0', len);
		}
	}
	return(res);
}

int ft_puthex(int n, char c, int *len)
{
	unsigned int	u = (unsigned int)n;
	int		ret = 0;
	
	if (u >= 16)
	{
		ft_puthex(u / 16, c, len);
		ft_puthex(u % 16, c, len);
	}
	else
	{
		if (c == 'x')
			ret = ft_putchar("0123456789abcdef"[u % 16], len);
	}
	return (ret);
}

int conditions(const char *next, va_list *a, int *len)
{
	int res = 0;
	
	if(*next == 's')
		res = ft_putstr(va_arg(*a, char *), len);
	else if (*next == 'd')
		res = ft_putnbr(va_arg(*a, int), len);
	else
		res = ft_puthex(va_arg(*a, int), *next, len);
	return(res);
}

int	ft_printf(const char *str, ...)
{
	va_list ap; //ap = argument pointer
	int len = 0;
	int error = 0;

	va_start(ap, str);
	while(*str)
	{
		if(*str== '%')
			error = conditions(++str, &ap, &len);#include <stdarg.h>
#include <unistd.h>

int ft_putchar(char c, int *len)
{
	*len = *len + 1;
	return(write(1, &c, 1));
}

void ft_putstr(char *str, int *len)
{
	long unsigned int i = 0;
	
	 if(!str)
	 	ft_putstr("(null)", len);
	 else
	 {
		while(str[i])
		{
			ft_putchar(str[i], len);
			i++;
		}
	 }
}

void ft_putnbr(int n, int *len)
{
	if(n == -2147483648)
		ft_putstr("-2147483648", len);
	else
	{
		if(n < 0)
		{
			ft_putchar('-', len);
			n = -n;
		}
		if (n > 9)
			ft_putnbr(n / 10, len);
		ft_putchar((n%10) + '0', len);
	}
}

void ft_puthex(int n, int *len)
{
	unsigned int	u = (unsigned int)n;	
	if (n > 15)
		ft_puthex(n / 16, len);
	ft_putchar("0123456789abcdef"[u % 16], len);
}

void conditions(const char *next, va_list *args, int *len)
{
	if(*next == 's')
		ft_putstr(va_arg(*args, char *), len);
	else if (*next == 'd')
		ft_putnbr(va_arg(*args, int), len);
	else
		ft_puthex(va_arg(*args, int), len);
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	int len = 0;
	int i = 0;

	va_start(args, str);
	
	while (str[i]) 
	{
		if (str[i] == '%')
			conditions(&str[++i], &args, &len);
		else
			ft_putchar(str[i], &len);
		i++;
	}
	va_end(args);
	return(len);
}

int main()
{
	ft_printf("%s\n", "toto");
	printf("%s\n", "toto");
	printf("\n");
	ft_printf("Magic %s is %d\n", "number", 42);
	printf("Magic %s is %d\n", "number", 42);
	printf("\n");
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("Hexadecimal for %d is %x\n", 42, 42);
}

/* #include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int ft_putchar(char c, int *len)
{
	*len = *len + 1;
	return(write(1, &c, 1));
}

int ft_putstr(char *str, int *len)
{
	long unsigned int i = 0;
	int res = 0;
	
	if(!str)
		ft_putstr("(null)", len);
	else
	{
		while(str[i])
		{
			ft_putchar(str[i], len);
			i++;
		}
	}
	return(res);
}

int ft_putnbr(int n, int *len)
{
	int res = 0;
	
	if(n == -2147483648)
		res = ft_putstr("-2147483648", len);
	else
	{
		if(n < 0)
		{
			res = ft_putchar('-', len);
			n = -n;
		}
		if(n > 9)
		{
			ft_putnbr(n / 10, len);
			ft_putnbr(n % 10, len);			
		}
		if(n < 10)
		{
			res = ft_putchar((n%10)+'0', len);
		}
	}
	return(res);
}

int ft_puthex(int n, char c, int *len)
{
	unsigned int	u = (unsigned int)n;
	int		ret = 0;
	
	if (u >= 16)
	{
		ft_puthex(u / 16, c, len);
		ft_puthex(u % 16, c, len);
	}
	else
	{
		if (c == 'x')
			ret = ft_putchar("0123456789abcdef"[u % 16], len);
	}
	return (ret);
}

int conditions(const char *next, va_list *a, int *len)
{
	int res = 0;
	
	if(*next == 's')
		res = ft_putstr(va_arg(*a, char *), len);
	else if (*next == 'd')
		res = ft_putnbr(va_arg(*a, int), len);
	else
		res = ft_puthex(va_arg(*a, int), *next, len);
	return(res);
}

int	ft_printf(const char *str, ...)
{
	va_list ap; //ap = argument pointer
	int len = 0;
	int error = 0;

	va_start(ap, str);
	while(*str)
	{
		if(*str== '%')
			error = conditions(++str, &ap, &len);
		else
			error = ft_putchar(*str,  &len);
		if(error < 0)
			return(error);
		str++;
	}
	va_end(ap);
	return(len);
}

int main()
{
	ft_printf("%s\n", "toto");
	printf("%s\n", "toto");
	printf("\n");
	ft_printf("Magic %s is %d\n", "number", 42);
	printf("Magic %s is %d\n", "number", 42);
	printf("\n");
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("Hexadecimal for %d is %x\n", 42, 42);
} */
		else
			error = ft_putchar(*str,  &len);
		if(error < 0)
			return(error);
		str++;
	}
	va_end(ap);
	return(len);
}

int main()
{
	ft_printf("%s\n", "toto");
	printf("%s\n", "toto");
	printf("\n");
	ft_printf("Magic %s is %d\n", "number", 42);
	printf("Magic %s is %d\n", "number", 42);
	printf("\n");
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("Hexadecimal for %d is %x\n", 42, 42);
} */
		else
			error = ft_putchar(*str,  &len);
		if(error < 0)
			return(error);
		str++;
	}
	va_end(ap);
	return(len);
}

int main()
{
	ft_printf("%s\n", "toto");
	printf("%s\n", "toto");
	printf("\n");
	ft_printf("Magic %s is %d\n", "number", 42);
	printf("Magic %s is %d\n", "number", 42);
	printf("\n");
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("Hexadecimal for %d is %x\n", 42, 42);
} */
	{
		if(*str== '%')
			error = conditions(++str, &ap, &len);
		else
			error = ft_putchar(*str,  &len);
		if(error < 0)
			return(error);
		str++;
	}
	va_end(ap);
	return(len);
}

int main()
{
	ft_printf("%s\n", "toto");
	printf("%s\n", "toto");
	printf("\n");
	ft_printf("Magic %s is %d\n", "number", 42);
	printf("Magic %s is %d\n", "number", 42);
	printf("\n");
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("Hexadecimal for %d is %x\n", 42, 42);
} */
			error = conditions(++str, &ap, &len);
		else
			error = ft_putchar(*str,  &len);
		if(error < 0)
			return(error);
		str++;
	}
	va_end(ap);
	return(len);
}

int main()
{
	ft_printf("%s\n", "toto");
	printf("%s\n", "toto");
	printf("\n");
	ft_printf("Magic %s is %d\n", "number", 42);
	printf("Magic %s is %d\n", "number", 42);
	printf("\n");
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("Hexadecimal for %d is %x\n", 42, 42);
} */
	index = 0;
	while (string[index] != '\0')
		index++;
	return (index);
}

char	*ft_str_duplicate(char *string)
{
	int		index;
	int		length;
	char	*duplicate;

	length = ft_str_length(string);
	index = 0;
	duplicate = (char *)malloc(sizeof(char) * length + 1);
	if (!duplicate)
		return (NULL);
	while (string[index] != '\0')
	{
		duplicate[index] = string[index];
		index++;
	}
	duplicate[index] = '\0';
	return (duplicate);
}

char	*get_next_line(int fd)
{
	int		n;
	int		index;
	char	character;
	char	buffer[7000000];

	index = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	n = read(fd, &character, 1);
	while (n > 0)
	{
		buffer[index++] = character;
		if (character == '\n')
			break ;
		n = read(fd, &character, 1);
	}
	if (n <= 0 && index == 0)
		return (NULL);
	buffer[index] = '\0';
	return (ft_str_duplicate(buffer));
} 
*/
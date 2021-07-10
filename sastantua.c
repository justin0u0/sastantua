#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void print_line(int space, int halfW)
{
	int i;
	
	i = 0;
	while (i++ < space)
		ft_putchar(' ');
	i = 0;
	ft_putchar('/');
	while (i++ < (halfW - space - 2) * 2 + 1)
		ft_putchar('*');
	ft_putchar('\\');
	ft_putchar('\n');
} 

void print_door(int space, int halfW, int door_width, int is_lock)
{
	int i;

	i = 0;
	while (i++ < space)
		ft_putchar(' ');
	i = 0;
	ft_putchar('/');
	while (i++ < halfW - space - 2 - door_width / 2)
		ft_putchar('*');
	i = 0;
	while (i++ < door_width - 2)
		ft_putchar('|');
	if (is_lock)
		ft_putchar('$');
	else if (door_width > 1)
		ft_putchar('|');
	ft_putchar('|');
	i = 0;
	while (i++ < halfW -space - 2 - door_width / 2)
		ft_putchar('*');
	ft_putchar('\\');
	ft_putchar('\n');
}

void handle_last_level(int size, int width, int space)
{
	int i;
	int j;
	int door_width;

	i = 0;
	j = 0;
	door_width = (size - (!(size & 1)));
	while (i++ < 2 - (size & 1))
		print_line(--space, width);
	while (i++ < 3 - (size & 1) + door_width)
		print_door(--space, width, door_width, door_width > 4 && (j++) == door_width / 2);
}

void sastantua(int size)
{
	int i;
	int j;
	int width;
	int space;

	i = 0;
	width = 4;
	while (++i < size)
		width += 3 * ((i + 1) / 2 + 1) + (!(i & 1));
	i = 2;
	space = width - 2;
	print_line(space, width);
	while (++i < size + 2)
	{
		j = 0;
		while (++j <= i)
			print_line((space -= (1 + ((i + 1) / 2) * (j == i))), width);
	}
	handle_last_level(size, width, space);
}

int main(int argc, char **argv)
{
	int val = 0;
	if (argc == 2) {
		int idx = 0;
		while (argv[1][idx] != '\0')
			val = val * 10 + argv[1][idx++] - '0';
	}
	sastantua(val);
	return 0;
}


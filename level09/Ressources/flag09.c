#include <unistd.h>

int main(int ac, char** av) {
	char* s = av[1];

	int i = 0;
	while (s[i] != 0) {
		char tmp = s[i] - i;
		write(1, &tmp, 1);
		i++;
	}
	return 0;
}

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int main(void)
{
	int *p = (int *) 0x12345678;
  	unsigned char *cp = (unsigned char *) &p;

  	int i;
	printf("0x");
  	for (i = sizeof(p) - 1; i >= 0; i--){
  		if(cp[i] != 0x00) printf("%x", cp[i]);
	}
	printf("\npritnf result: %p\n", p);
  	return 0;
}


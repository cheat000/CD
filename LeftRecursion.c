#include <stdio.h>
#include <string.h>
#define SIZE 10
int main()
{
	char nt;
	char b, a[10];
	int num;
	int i;
	char p[10][SIZE];
	int index = 3;
	printf("Enter Number of productions:");
	scanf("%d", &num);
	printf("Enter the grammar as E->E-A:\n");
	for (i = 0; i < num; i++)
		scanf("%s", p[i]);
	for (i = 0; i < num; i++)
	{
		printf("\nGRAMMAR:%s", p[i]);
		nt = p[i][0];
		if (nt == p[i][index])
		{
			printf("is left recursive:\n");
			int k = 0;
			index++;
			while (p[i][index] != 0 && p[i][index] != '|')
			{
				a[k++] = p[i][index];
				index++;
			}
			a[k] = '\0';
			if (p[i][index] != 0)
			{
				b = p[i][index + 1];
				printf("Grammar without left recursion;\n");
				printf("%c->%c%c\'\n", nt, b, nt);
				printf("\n%c\'->%s%c\'|E\n", nt, a, nt);
			}
			else
				printf("can't be reduced\n");
		}
		else
			printf("is not left recursive\n");
		index = 3;
	}
}

// Enter Number of productions:1
// Enter the grammar as E->E-A:
// A->A+B/B

// GRAMMAR:A->A+B/B is left recursive:
// Grammar without left recursion;
// A->BA'
// A'->+BA'/E

// GRAMMAR:E->A|Bis not left recursive
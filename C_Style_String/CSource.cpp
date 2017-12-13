#include<stdio.h> 
#include<string.h>
#include<cctype>

int main()
{
	char name[100];
	fgets(name, 100, stdin);
	int m = 0;
	int n = strlen(name);

	/*delete the front spaces*/
	while (isspace(name[0]))
	{
		for (int j = 0; j<n - 1; j++)
		{
			name[j] = name[j + 1];
		}
		n--;
	}

	/*delete unnecessary ones*/
	int i = 0;
	while (i<n)
	{
		if (isspace(name[i]))
		{
			if (i == n - 1)
			{
				n--;
				i++;
			}
			else
			{
				if (isspace(name[i + 1]))
				{

					for (int j = i; j<n - 1; j++)
					{
						name[j] = name[j + 1];
					}
					n--;

				}
				else
				{
					i++;
				}
			}

		}
		else
		{
			i++;
		}
	}

	/*uppercase the first character of the word in the string*/
	if (islower(name[0]))
	{
		name[0] -= 32;
	}

	for (int i = 1; i<n - 1; i++)
	{
		if (isspace(name[i]))
		{
			if (islower(name[i + 1]))
			{
				name[i + 1] -= 32;
			}
			else
			{
				continue;
			}
		}
	}
	//removespaceBefore(name,n);
	//removespaceAmongChar(name,n);
	//uppercase(name,n);
	for (int i = 0; i<n; i++)
	{
		printf("%c", name[i]);
	}
}
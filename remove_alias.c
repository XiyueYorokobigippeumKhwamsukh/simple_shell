#include "shell.c"

/**
  * removeAlias - Removes aliases
  * @name: Pointer  to the aliases to be removed
  * return: void
  */

void removeAlias(const char *name)
{
	int j;
	int aliasCount = 0;

	for( j = 0; j < aliasCount; j++)
	{
		if (strcmp(aliases[j].name, name) == 0)
		{
			for (; j < aliasCount - 1; j++)
			{
				aliases[j] = aliases[j + 1];
			}
			aliasCount--;

			return;
		}
	}
	fprintf(stderr, "Alias not found: %s\n", name);
}

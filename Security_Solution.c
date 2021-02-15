#include <stdio.h>
#include <string.h>

int IsSecure(char floor[]);

int main() 
{
	char floor[50];
	
	scanf("%s",floor);
	
	if(IsSecure(floor))
		printf("quiet");
	else
		printf("ALARM");
	
    return 0;
}
//Check if there is at least one guard between the money and the thief
int IsSecure(char floor[])
{
	int i, j, len, guards = 0;
	
	len = strlen(floor);
	
	for(i = 0; i < len; i++)
	{
		if(floor[i] == '$' || floor[i] == 'T')
		{
			for(j = i+1; j < len ; j++)
			{
				if(floor[j] == '$' || floor[j] == 'T')
				{
					i = len;
					break;
				}
					
				if(floor[j] == 'G')
					guards++;
				
				if(guards > 0)
					return 1;	
			}	
		}	
	}
	
	return 0;
}

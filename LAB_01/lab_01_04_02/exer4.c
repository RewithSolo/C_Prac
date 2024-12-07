#include <stdio.h>

int main()
{
	int sec, hours, min, remaining_seconds;
	scanf("%d", &sec);
	
	hours = sec / 3600;
	min = (sec % 3600) / 60;
	remaining_seconds = sec % 60;
	
	printf("%d %d %d", hours, min, remaining_seconds);
}


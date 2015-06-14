/*
this is function generating log message .
*/
#define _LOG_H

#ifndef _STDIO_H
#include <stdio.h>
#endif

#ifndef _TIME_H
 #include <time.h>
#endif

void messageGenerator(char logMessage[],char message[])
{
	char timeString[20]="";
	struct tm *localTime;
	time_t rawTime; 
	time(&rawTime);
	localTime = localtime(&rawTime);
	strftime(timeString ,22, "[%Y-%m-%d %H:%M:%S]",localTime);
	sprintf(logMessage , "[%s] : %s", timeString , message);
	printf("%s\n",logMessage);
}

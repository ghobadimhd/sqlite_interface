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

#ifndef _FILE_H
#include <file.h>
#endif

#define LOGTOSTDOUT 0
#define LOGTOFILE 1

void messageGenerator(char logMessage[],char message[])
{
	char timeString[20]="";
	struct tm *localTime;
	time_t rawTime; 
	time(&rawTime);
	localTime = localtime(&rawTime);
	strftime(timeString ,22, "%Y-%m-%d %H:%M:%S",localTime);
	sprintf(logMessage , "[%s] : %s", timeString , message);
}

/*
this is function loging messages .
*/
void logger(char message[] , int destination , char data[])
{
	char log[500]="" ;
	messageGenerator(log , message);
	switch(destination)
	{
		case 0:
			printf("%s\n",log);
		break;
		case 1:
			stringWriter(log, data);	
		break;
		default:
			printf("logging failed\n");
	}
	
}

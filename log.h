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

#ifndef _FILE_H
#include <unistd.h>
#endif



#define LOGTOSTDOUT 0
#define LOGTOFILE 1
#define HOSTNAMELENGH 50
#define PROCESSNAME "sqlite_interface"
/*
this is function generating log message .
*/
void messageGenerator(char logMessage[],char message[])
{
	char timeString[20]="" , hostname[HOSTNAMELENGH] ;
	gethostname(hostname,HOSTNAMELENGH);
	struct tm *localTime;
	time_t rawTime; 
	time(&rawTime);
	localTime = localtime(&rawTime);
	strftime(timeString ,22, "%b %d %H:%M:%S",localTime);// time string : year-month-day hour:minute:secend
	sprintf(logMessage , "%s %s %s[%d] : %s", timeString , hostname, PROCESSNAME, (long)getpid() , message);
}

/*
this is function loging messages .
*/
void logger(char message[] , int destination , char data[])
{
	char log[500]="" ;
	messageGenerator(log , message);//generating messages 
	switch(destination)
	{
		case 0:
			printf("%s\n",log);// print message to stdout
		break;
		case 1:
			stringWriter(log, data);// save message to file 
		break;
		default:
			printf("logging failed\n");
	}
	
}

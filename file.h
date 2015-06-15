#ifndef _FILE_H
#define _FILE_H
#endif

#ifndef _STDIO_H
#include <stdio.h>
#endif
//
// this function save a string in end of file 
int stringWriter(char string[], char addr[])
{
	FILE *fptr ;
	fptr = fopen(addr , "a");
	if(fptr == NULL)
		return 0 ;
	fprintf(fptr, "%s\n",string);
	fclose(fptr);
}

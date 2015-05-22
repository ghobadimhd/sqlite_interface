/*
sqlite_interface	2015-04-29 19:04
Program name : sqlite interface
Author : Mohammad Ghobadi
Email : ghobadi.mhd@outlook.com
describtion : This is program for implementing simple interface for sqlite3 .
*/
#include <stdio.h>
#include <string.h>
#include <sqlite3.h>
#include <stdio.h>
#include <shared_data.h>
#include <db_manager.h>
#include <query_gen.h>
#include <menu.h>
int main(int argc, const char *argv[])
{
	//connecting to database 
	int success = connectToDb();
	if(success)
		mainMenu();
	else 
		printf("Connecting to database failed .\n");
	return 0;
}

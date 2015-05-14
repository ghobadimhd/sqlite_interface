/*
sqlite_interface	2015-04-29 19:04
Program name : sqlite interface
Author : Mohammad Ghobadi
Email : ghobadi.mhd@outlook.com
describtion : This is program for implementing simple interface for sqlite3 .
*/
//include data structures 
//data base files and query generators 
//user interface
#include <stdio.h>
#include <string.h>
#include <sqlite3.h>
#include <db_manager.h>
#include <query_gen.h>
#include <menu.h>
int main(int argc, const char *argv[])
{
	//connecting to database 
	connectToDb();
	mainMenu();
	//menu and user interface
	return 0;
}

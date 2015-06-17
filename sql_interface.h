/*
sql_interface	2015-06-11 13:06
Program name : sql interface
Author : Mohammad Ghobadi
Email : ghobadi.mhd@outlook.com
describtion : multiple function that implement interface for query_gen.h .
*/

#ifndef _SQL_INTERFACE_H
#define _SQL_INTERFACE_H
#endif

#ifndef _STDIO_H
#include <stdio.h>
#endif

#ifndef _QUERY_GEN_H
#include <query_gen.h>
#endif

#ifndef _LOG_H
#include <log.h>
#endif

/*
this is function that implement interface for insert query .
*/
void insert_dialog()	
{
	char tableName[20] , columns[10][20] , values[10][20] , sql[500];
	int count ;
	printf("Enter table name :");
	scanf("%s",tableName);
	printf("how many column your record has ? :");
	scanf("	%d",&count);
	for (int i = 0; i <count; i++) 
	{
		printf("enter column name :");
		scanf(" %s",columns[i]);
		printf("enter value for %s :",columns[i]);
		scanf(" %s",values[i]);
	}
	insertQuery(sql , tableName , count , columns , values ) ;// generating query string 
	int success = query(sql , simpleCallback);// executing query string
	if( ! success)
	{	
		char message[500]="";
		sprintf(message, "Operation failed : %s\n",errorMessage);
		printf("%s%s%s\n",RED,message,RESET);
		logger(message ,LOGTOFILE , "error.log");
	}
}
//
//this function show dialog for update query 
//
void update_dialog()
{
	char tableName[20] , columns[10][20] , values[10][20] , keyColumn[20] , keyValue[20]  , sql[500] ;
	int count ;
	printf("Enter table name :");
	scanf("%s",tableName);
	printf("how many column you want to update ? :");
	scanf("	%d",&count);
	for (int i = 0; i <count; i++) 
	{
		printf("enter column name :");
		scanf(" %s",columns[i]);
		printf("enter new value for %s :",columns[i]);
		scanf(" %s",values[i]);
	}
	printf("enter key column name :");
	scanf(" %s",keyColumn);
	printf("enter key value :");
	scanf(" %s",keyValue);
	updateQuery(sql , tableName , count , columns , values , keyColumn , keyValue) ;// generating query string
	int success = query(sql , simpleCallback);// executing query 
	if( ! success)
	{	
		char message[500]="";
		sprintf(message, "Operation failed : %s\n",errorMessage);
		printf("%s%s%s\n",RED,message,RESET);
		logger(message ,LOGTOFILE , "error.log");
	}

}
//
//this function show dialog for delete query
//
void delete_dialog()
{
	char tableName[20] , keyColumn[20] , keyValue[20] , sql[500] ;
	printf("Enter table name :");
	scanf("%s",tableName);
	printf("enter key column name :");
	scanf(" %s",keyColumn);
	printf("enter key value :");
	scanf(" %s",keyValue);
	deleteQuery(sql , tableName , keyColumn , keyValue) ;// generating query string
	int success = query(sql , simpleCallback);// executing query 
	if( ! success)
	{	
		char message[500]="";
		sprintf(message, "Operation failed : %s\n",errorMessage);
		printf("%s%s%s\n",RED,message,RESET);
		logger(message ,LOGTOFILE , "error.log");
	}
}
//
//this function show dialog for select query 
//
void select_dialog()
{
	char sql[500] , tableName[20] , columnsName[10][20] ;
	int count = 0;

	printf("enter table name : ");
	scanf("%s",&tableName);
	printf("how many column of table you want to see (enter 0 for all columns) : ");
	scanf(" %d",&count);
	for (int i = 0; i <count; i++) 
	{
		printf("enter column name #%d : ",i);
		scanf("	%s",columnsName[i]);
	}
	selectQuery(sql , tableName , count , columnsName);// generating query string
	int success = query(sql , simpleCallback);// executing query
	if( ! success)
	{	
		char message[500]="";
		sprintf(message, "Operation failed : %s\n",errorMessage);
		printf("%s%s%s\n",RED,message,RESET);
		logger(message ,LOGTOFILE , "error.log");
	}
}
//
//this function is show dialog for creating table
//
void createTable_diolog()
{
	char tableName[20] , column[10][20] , columnType[10][20]  , isNullAnswer = 0 , sql[500]="";
	int count , isNull[10] ;
	printf("Please enter table name :");
	scanf("%s",tableName);
	printf("How many column your table has(max is 10)?:");
	scanf("%d",&count);
	for (int i = 0; i <count; i++) 
	{
		printf("enter name of column #%d:",i);
		scanf(" %s",column[i]);
		printf("enter type of %s :",column[i]);
		scanf(" %s",columnType[i]);
		printf("is it nullable column?");
		scanf(" %c",&isNullAnswer);
		isNull[i] = isNullAnswer == 'y' ? 1 : 0; 
		printf("\n");
	}
	tableQueryGen(sql ,tableName , count , column , columnType , isNull );//generating query string 
	int success = query(sql , simpleCallback); // executing query 
	if( ! success)
	{	
		char message[500]="";
		sprintf(message, "Operation failed : %s\n",errorMessage);
		printf("%s%s%s\n",RED,message,RESET);
		logger(message ,LOGTOFILE , "error.log");
	}

}
//
//this function show dialog for listing detail of a table 
//
void tableInfo_dialog()
{
	char tableName[20] , sql[500] ; 
	printf("Enter the table name : ");
	scanf("%s",tableName);
	tableInfoQuery(sql ,tableName);// generating query string
	int success = query(sql , simpleCallback);// executing query
	if( ! success)
	{	
		char message[500]="";
		sprintf(message, "Operation failed : %s\n",errorMessage);
		printf("%s%s%s\n",RED,message,RESET);
		logger(message ,LOGTOFILE , "error.log");
	}
}
//
//this function show dialog for listing existing table
//
void tableList_dialog()
{
	char sql[100] ;
  	listTablesQuery(sql) ; // generating query string 
	int success = query(sql , simpleCallback) ; // executing query
	if( ! success)
	{	
		char message[500]="";
		sprintf(message, "Operation failed : %s\n",errorMessage);
		printf("%s%s%s\n",RED,message,RESET);
		logger(message ,LOGTOFILE , "error.log");
	}

}

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

/*
this is function that implement interface for insert query .
*/
void insert_dialog(char sql[])	
{
	char tableName[20] , columns[10][20] , values[10][20] ;
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
	insertQuery(sql , tableName , count , columns , values ) ;
}

void update_dialog(char sql[])
{
	char tableName[20] , columns[10][20] , values[10][20] , keyColumn[20] , keyValue[20] ;
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
		updateQuery(sql , tableName , count , columns , values , keyColumn , keyValue) ;

}

void delete_dialog(char sql[])
{
	char tableName[20] , keyColumn[20] , keyValue[20] , sql[500] ;
	printf("Enter table name :");
	scanf("%s",tableName);
	printf("enter key column name :");
	scanf(" %s",keyColumn);
	printf("enter key value :");
	scanf(" %s",keyValue);
	deleteQuery(sql , tableName , keyColumn , keyValue) ;
}

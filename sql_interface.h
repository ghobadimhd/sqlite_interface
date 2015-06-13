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

void select_dialog(char sql[])
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
	selectQuery(sql , tableName , count , columnsName);
}

void createTable_diolog(char sql[])
{
	char tableName[20] , column[10][20] , columnType[10][20]  , isNullAnswer = 0;
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
		scanf(" %c",&isNullAnswer); // fix me : segmentation failed 
		isNull[i] = isNullAnswer == 'y' ? 1 : 0; 
		printf("\n");
	}
	tableQueryGen(sql ,tableName , count , column , columnType , isNull );

}

void tableInfo_dialog(char sql[])
{
	char tableName[20] ; 
	printf("Enter the table name : ");
	scanf("%s",tableName);
	tableInfoQuery(sql ,tableName);
}

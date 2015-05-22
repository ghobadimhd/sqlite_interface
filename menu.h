void innerMenu();
/*
this is function for showing interface for connecting to database .
*/
int connectToDb()
{
	char db_name[100]; 
	int hasError ;
	printf("Please enter name of database you want to connect :");
	gets(db_name);
	hasError = open_db(db_name);
	if (! hasError )
	{
		printf("%scan not connect to database : %s\n%s",RED,errorMessage,RESET);
		sqlite3_free(errorMessage);
		return 0 ;
	}
}
/*
this is function for showin main menu of program .
*/
void mainMenu()
{
	int choice = -1;
	while(choice != 0)
	{
		switch(choice)
		{
			case 1:
				innerMenu();
			break;
			case 2:
			{
				// insert query
				char tableName[20] , columns[10][20] , values[10][20] , sql[500] ;
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
				int success =query(sql , simpleCallback) ;
				if( ! success) 
					printf("%sOperation failed : %s\n%s", RED ,errorMessage, RESET);

			}
			break;
			case 3:
			{
				// update query 	
				char tableName[20] , columns[10][20] , values[10][20] , keyColumn[20] , keyValue[20] , sql[500] ;
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
				int success = query(sql , simpleCallback) ;
				if( ! success) 
					printf("%sOperation failed : %s\n%s", RED ,errorMessage, RESET);
			}
			break;
			case 4:
			{
				// delete query 	
				char tableName[20] , keyColumn[20] , keyValue[20] , sql[500] ;
				printf("Enter table name :");
				scanf("%s",tableName);
				printf("enter key column name :");
				scanf(" %s",keyColumn);
				printf("enter key value :");
				scanf(" %s",keyValue);
				deleteQuery(sql , tableName , keyColumn , keyValue) ;
				int success = query(sql , simpleCallback);
				if( ! success) 
					printf("%sOperation failed : %s\n%s", RED ,errorMessage, RESET);
			}
			break;
			case 5:
			{
				//select();
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
				printf("%s\n",GREEN);
				int success = query(sql , simpleCallback );
				printf("%s\n",RESET);
				if( ! success) 
					printf("%sOperation failed : %s\n%s", RED ,errorMessage, RESET);
			}
			break;
			default:
			break ; 			
		}
		
	printf("what do you want to do :\n1-tables\n2-insert\n3-update\n4-delete\n5-select\n0-exit\n?:");		
	scanf("%d",&choice);
	
		
		
	}
}
/*
this is function for showing inner menu .
*/
void innerMenu()
{
	int choice = -1;
	while(choice != 0)
	{
		switch(choice)
		{
			case 1 :  
			{		
				char sql[500]="" ,  tableName[20] , column[10][20] , columnType[10][20]  , isNullAnswer = 0;
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
				int success = query(sql , simpleCallback);
				if( ! success) 
					printf("%sOperation failed : %s\n%s", RED ,errorMessage, RESET);

			}	
			break ;
			case 2:
			{
				char sql[100] ;
			       	listTablesQuery(sql) ; 
				int success = query(sql , simpleCallback) ; 
				if( ! success) 
					printf("%sOperation failed : %s\n%s", RED ,errorMessage, RESET);
			}
			break;
			case 3:
			{
				char sql[100]  , tableName[20] ; 
				printf("Enter the table name : ");
				scanf("%s",tableName);
				tableInfoQuery(sql ,tableName);
				int success = query(sql , simpleCallback);
				if( ! success) 
					printf("%sOperation failed : %s\n%s", RED ,errorMessage, RESET);
			}

			break;
			case 0 : 
				return ;	
			break;
			default:
			break ; 	
		}
		
	printf("what do you want to do :\n1-create table\n2-show tables \n3-tables info\n0-back\n?:");		
	scanf("%d",&choice);
	
		
		
	}
}


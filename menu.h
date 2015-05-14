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
	if ( hasError )
	{
		printf("can not connect to database : %s\n",errorMessage);
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
				char tableName[20] , columns[10][20] , values[10][20] , *sql ;
				int count ;
				printf("Enter table name :");
				scanf("%s",tableName);
				printf("how many column your record has ? :");
				scanf("	%s",&count);
				for (int i = 0; i <count; i++) 
				{
					printf("enter column name :");
					scanf(" %s",columns[i]);
					printf("enter column value :");
					scanf(" %s",values[i]);
				}
				sql = insertQuery(tableName , count , columns , values ) ;
				query(sql , simpleCallback) ;

			}
			break;
			case 3:
				//update();
			break;
			case 4:
				//delete();
			break;
			case 5:
				//select();
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
				char *sql ,  tableName[20] , column[10][20] , columnType[10][20]  , isNullAnswer = 0;
				int count , isNull[10] ;
				printf("Please enter table name :");
				scanf("%s",tableName);
				printf("How many column your table has(max is 10)?:");
				scanf("%d",&count);
				for (int i = 0; i <count; i++) 
				{
					printf("enter name of column #%d:",count);
					scanf(" %s",column[count]);
					printf("enter type of column #%d:",count);
					scanf(" %s",columnType);
					printf("is nullable column?");
					scanf(" %c",&isNullAnswer); // fix me : segmentation failed 
					isNull[count] = isNullAnswer == 'y' ? 1 : 0; 
					printf("\n");
				}
				sql = tableQueryGen(tableName , count , column , columnType , isNull );
				query(sql , simpleCallback);
			}	
			break ;
			case 2:
			{
				char *sql = listTablesQuery() ; 
				query(sql , simpleCallback) ; 
			}
			break;
			case 3:
			{
				char *sql  , tableName[20] ; 
				printf("Enter the table name : ");
				scanf("%s",tableName);
				sql = tableInfoQuery(tableName);
				query(sql , simpleCallback);
			}

			break;
			case 0 : 
				return ;	
			break;
			default:
			break ; 	
		}
		
	printf("what do you want to do :\n1-create table\n2-show tables \n3-tables info\n0-exit\n?:");		
	scanf("%d",&choice);
	
		
		
	}
}


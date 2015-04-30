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
		switch()
		{
			case 1:
				//table_menu();	
			break;
			case 2:
				//insert();
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
				
		}
		
	printf("what do you want to do :\n1-tables\n2-insert\n3-update\n4-delete\n5-select\n0-exit\n?:");		
	scanf("%d",&choice);
	
		
		
	}
}

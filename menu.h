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

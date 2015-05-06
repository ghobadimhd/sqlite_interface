#define callbackFunction int (*callback)(void*,  int,  char**,   char**  )
sqlite3 *db ;//database object
char *errorMessage ; // error message returned by sqlite 

/*
this is function creating date base or connecting to it  .
*/
int open_db(char *db_name)
{
	int hasError ;
	hasError = sqlite3_open(db_name , &db);
	if(hasError)
	{
		errorMessage = sqlite3_errmsg(db);
		return 0 ;
	}
	else 
		return 1 ; // dataBase (create and ) opened successfully
}
/*
this is simple callback function .
*/
static int simpleCallback(void *data, int argc, char **argv, char **azColName)
{
	int i;
	for(i=0; i<argc; i++)
	{
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}
/*
this is function query to database  .
*/
int query(char *sql , callbackFunction)
{
	int rc ;
	rc = sqlite3_exec(db, sql, callback, 0, &errorMessage);
	if( rc != SQLITE_OK )
	{
		return 0 ;
	}
	 else
		 return 1 ;
}

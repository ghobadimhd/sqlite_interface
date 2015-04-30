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

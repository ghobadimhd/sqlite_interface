/*
this is function for generating a query for making a table .
*/
char* tableQueryGen(char tableName[],int numberOfColumns , char **columnsName , char **columnsType , int isNull[] )
{
	char sql[500] = "create table ";
	strcat(sql,tableName);
	strcat(sql , " (");
	for (int i = 0; i <numberOfColumns; i++) 
	{
		strcat(sql,columnsName[i]);
		strcat(sql , " ");
		strcat(sql,columnsType[i]);
		if(! isNull[i])
		{
			strcat(sql , " ");
			strcat(sql , "NOT NULL ");
		if(i != numberOfColumns -1 )
			strcat(sql , ",");
		}
	}
	strcat(sql , " );");
	return sql ;

}
/*
this is function for creating query for listing existence tables .
*/
char* listTablesQuery()
{
	char sql[] = "select name from sqlite_master where type == 'table'";
	return sql ;
}
/*
this is function for showing table info .
*/
char* tableInfoQuery(char *tableName)
{
	char sql[50] = "pragma table_info(";
	strcat(sql , tableName);
	strcat (sql , ");");
	
	return sql;
}
/*
this is function for generating sql query for inserting data in table .
*/
char* insertQuery(char tableName[] ,int numberOfColumns ,char **columns , char **values )
{
	char sql[500]= "insert into " ;
	strcat(sql,tableName);
	strcat(sql," (");
	for (int i = 0; i <numberOfColumns; i++) 
	{
		strcat(sql,columns[i]);
		if ( i != numberOfColumns-1 )
			strcat(sql,",");
	}
	strcat(sql,") values (");
	for (int i = 0; i <numberOfColumns; i++) 
	{
		strcat(sql,values[i]);
		if ( i != numberOfColumns-1 )
			strcat(sql,",");
	}
	strcat(sql,")");
	return sql;
}
/*
this is function for generating select sql query .
*/
char* selectQuery(char tableName[] , int numberOfColumns , char **columns)
{
	char sql[500] = "select ";
	if ( numberOfColumns == 0 )
		strcat(sql,"*");
	else
	{
		
		for (int i = 0; i <numberOfColumns; i++) 
		{
			strcat(sql,columns[i]);
			if ( i != numberOfColumns-1 )
				strcat(sql,",");
		}
	}
	
	strcat(sql," from ");
	strcat(sql,tableName);
	return sql ;
}
/*
this is function fot generating update query .
*/
char* updateQuery(char tableName[] , int numberOfColumns , char **columns , char **values , char keyColumn[] , char keyValue[])
{
	char sql[500]= "update " ;
	strcat(sql,tableName);
	strcat(sql," set ");
	for (int i = 0; i <numberOfColumns; i++) 
	{
		strcat(sql,columns[i]);
		strcat(sql,"=");
		strcat(sql,values[i]);	
		if ( i != numberOfColumns-1 )
			strcat(sql,",");
	}
	strcat(sql," where ");
	strcat(sql,keyColumn);
	strcat(sql,"=");
	strcat(sql,keyValue);

	return sql;
}
/*
this is function for generating delete query string .
*/
char* deleteQuery(char tableName[] , char keyColumn[] , char keyValue)
{
	char sql[100]= "delete from ";
	strcat(sql,tableName);
	strcat(sql," where ");
	strcat(sql,keyColumn);
	strcat(sql,"=");
	strcat(sql,keyValue);

	return sql;
}

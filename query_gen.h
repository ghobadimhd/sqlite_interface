/*
this is function for generating a query for making a table .
*/
void tableQueryGen(char sql[] , char tableName[],int numberOfColumns , char columnsName[][20] , char columnsType[][20] , int isNull[] )
{
	strcpy(sql,"create table ");
	strcat(sql,tableName);
	strcat(sql , " (");
	for (int i = 0; i <numberOfColumns; i++) 
	{
		strcat(sql,columnsName[i]);
		strcat(sql , " ");
		strcat(sql,columnsType[i]);
		if(! isNull[i])
		{
			strcat(sql , " NOT NULL ");
		}
		if(i != numberOfColumns -1 )
			strcat(sql , ",");
		
	}
	strcat(sql , " );");
	return sql ;

}
/*
this is function for creating query for listing existence tables .
*/
void listTablesQuery(char sql[])
{
	strcpy(sql, "select * from sqlite_master where type = 'table'");
	return sql ;
}
/*
this is function for showing table info .
*/
void tableInfoQuery(char sql[] , char *tableName)
{
	strcpy(sql , "pragma table_info(");
	strcat(sql , tableName);
	strcat (sql , ");");
	
	return sql;
}
/*
this is function for generating sql query for inserting data in table .
*/
void insertQuery(char sql[] , char tableName[] ,int numberOfColumns ,char columns[][20] , char values[][20] )
{
	strcpy(sql, "insert into ") ;
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
void selectQuery(char sql[] , char tableName[] , int numberOfColumns , char columns[][20])
{
	strcpy(sql, "select ");
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
void updateQuery(char sql[] , char tableName[] , int numberOfColumns , char columns[][20] , char values[][20] , char keyColumn[] , char keyValue[])
{
	strcpy(sql, "update ") ;
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
void deleteQuery(char sql[] , char tableName[] , char keyColumn[] , char keyValue[])
{
	strcpy(sql, "delete from ");
	strcat(sql,tableName);
	strcat(sql," where ");
	strcat(sql,keyColumn);
	strcat(sql," = ");
	strcat(sql,keyValue);

}

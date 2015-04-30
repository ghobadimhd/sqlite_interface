/*
this is function for generating a query for making a table .
*/
char* tableQueryGen(char[] tableName,int numberOfColumns , char **columnsName , char **columnsType , int isNull[] )
{
	char sql[500] = "create table ";
	strcat(sql,tableName);
	strcat(sql , " (");
	for (int i = 0; i <numberOfColumns; i++) 
	{
		strcat(sql,columnsName[i]);
		strcat(sql , " ");
		strcat(sql,columnsType[i]);
		if(i != numberOfColumns -1 )
			strcat(sql , ",");
	}
	strcat(sql , " );");
	return sql ;

}

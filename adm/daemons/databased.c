// databased.c
// 
// Created by mxzhao 2004/02/15
// Modified by Ciwei@SJ
// Segmentation fault 

#include <database.h>

private void log_out(string func, mixed ret);
private int isvalid();
private int dbconnect();
private void dbclose(int db);
mixed dbquery(string sql);

private void create()
{
	seteuid(ROOT_UID);
}

private void log_out(string func, mixed ret)
{
/*	if (intp(ret) && ret > 0)
	{
		return ret;
	}

	write_file("/log/database", 
		sprintf(" %s error:%O\n", func, ret));
*/
	return 0;
}

private int isvalid()
{
	return (previous_object() && (previous_object() 
		== find_object(SIMUL_EFUN_OB)))?1:0;
}

private int dbconnect()
{
	if (!previous_object() 
		|| (previous_object() != find_object(SIMUL_EFUN_OB)))
	{
		return 0;
	}

//	return log_out("db_connect", db_connect(DB_HOST, DB_NAME, DB_USER));
}

private void dbclose(int db)
{
//	log_out("db_close", db_close(db));
}

mixed dbquery(string sql)
{

	int db;
	mixed rows; 
	mixed rets = ({ });
/*
	if (!strlen(sql))
	{
		return 0;
	}

	if (!(db = dbconnect()))
	{
		return 0;
	}

	rows = db_exec(db, sql);

	if (stringp(rows))
	{
		log_out("db_exec", rows);
		return 0;
	}

	if (intp(rows) && rows > 0)
	{
		mixed ret;
		string temp;
		
		if (rows > ROW_LIMIT)
		{
			rows = ROW_LIMIT;
		}

		for (int i = 1; i <= rows; i++)
		{
			ret = db_fetch(db, i);
			
			for(int j = 0;j<sizeof(ret);j++){
				if(bufferp(ret[j])){
					temp = read_buffer(copy(ret[j]));
					ret[j] = copy(temp);
					//ret[j] = read_buffer(ret[j]);
				}
			}
			rets += ({ ret });
		}
	}

	dbclose(db);*/

	return rets;
}


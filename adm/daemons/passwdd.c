
// Modified by mxzhao 2004/02/18

#include <database.h>

void create()
{
	seteuid(getuid());
}

string get_passwd(string id)
{
// Modified by mxzhao 2004/02/18
	mixed ret = dbquery("select U_Password from Users "
		"where U_Username='"+id+"'");

	if (!ret)
	{
		write("数据库连接失败。\n");
		return 0;
	}

	if (sizeof(ret) == 0)
	{
		write("数据库无此用户信息。\n");
		return 0;
	}

	return ret[0][0];
/*
	mixed mysql = db_connect("localhost","mud","root");
	mixed *res;

	if (!intp(mysql))
		return 0;	// 不能连接到数据库
	if (1 != db_exec(mysql, "select U_Password from " + INTERMUD_MUD_NAME + "_Users where U_Username='"+id+"'")) {
		db_close(mysql);
		return 0;	// 没检索到记录
	}
	res = db_fetch(mysql, 1);
	db_close(mysql);
	return res[0];
*/
// End
}

int set_passwd(string id, string passwd)
{
// Modified by mxzhao 2004/02/18
	if (!get_passwd(id)) 
	{
		return 0;	// 没检索到记录
	}

	if (!dbquery("update Users set "
		"U_Password='"+passwd+"' "
		"where U_Username='"+id+"'"))
	{
		write("数据库连接失败。\n");
		return 0;
	}
	if (!BBS_D->add_Bbs_Up_Map(WEB_DB_NAME, "UPDATE members SET password = 
		'"+passwd+"' WHERE username = '"+
		id+"@"+lower_case(INTERMUD_MUD_NAME)+"' limit 1"))
		{
			write("WEB数据库更新失败。\n");
			return 0;
		}
	return 1;
/*
	mixed mysql = db_connect("localhost","mud","root");

	if (!intp(mysql))
		return 0;	// 不能连接到数据库
	if (!get_passwd(id)) {
		db_close(mysql);
		return 0;	// 没检索到记录
	}
	db_exec(mysql, "update " + INTERMUD_MUD_NAME + "_Users set "
		"U_Password='"+passwd+"' "
		"where U_Username='"+id+"'"
	);
	db_close(mysql);
	return 1;
*/
}

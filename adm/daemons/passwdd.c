
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
		write("���ݿ�����ʧ�ܡ�\n");
		return 0;
	}

	if (sizeof(ret) == 0)
	{
		write("���ݿ��޴��û���Ϣ��\n");
		return 0;
	}

	return ret[0][0];
/*
	mixed mysql = db_connect("localhost","mud","root");
	mixed *res;

	if (!intp(mysql))
		return 0;	// �������ӵ����ݿ�
	if (1 != db_exec(mysql, "select U_Password from " + INTERMUD_MUD_NAME + "_Users where U_Username='"+id+"'")) {
		db_close(mysql);
		return 0;	// û��������¼
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
		return 0;	// û��������¼
	}

	if (!dbquery("update Users set "
		"U_Password='"+passwd+"' "
		"where U_Username='"+id+"'"))
	{
		write("���ݿ�����ʧ�ܡ�\n");
		return 0;
	}
	if (!BBS_D->add_Bbs_Up_Map(WEB_DB_NAME, "UPDATE members SET password = 
		'"+passwd+"' WHERE username = '"+
		id+"@"+lower_case(INTERMUD_MUD_NAME)+"' limit 1"))
		{
			write("WEB���ݿ����ʧ�ܡ�\n");
			return 0;
		}
	return 1;
/*
	mixed mysql = db_connect("localhost","mud","root");

	if (!intp(mysql))
		return 0;	// �������ӵ����ݿ�
	if (!get_passwd(id)) {
		db_close(mysql);
		return 0;	// û��������¼
	}
	db_exec(mysql, "update " + INTERMUD_MUD_NAME + "_Users set "
		"U_Password='"+passwd+"' "
		"where U_Username='"+id+"'"
	);
	db_close(mysql);
	return 1;
*/
}

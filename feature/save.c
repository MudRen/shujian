// save.c
// Modified by mxzhao 2004/02/18
// Modified by mxzhao 2004/05/07 for add backup function

#include <mudlib.h>
#include <ansi.h>

int backup();

int update_viptime(object me)
{
	string uname = me->query("id");
	mixed ret = dbquery("SELECT Alivedays, U_Regtimelimit FROM Users "
		"WHERE U_Username=" + save_variable(uname));

	if (sizeof(ret) == 1 && ret[0][0] > 0)
	{
		if (me->query("vip/vip_time") < time()) //��ʾ���ڻ����¼�����û�
		{
			me->set("vip/vip_time",time() + ret[0][0]*24*3600);
			write("���Ĺ��ʱ���Ѿ��Զ������ˣ���ǰ�����Ч��Ϊ"+ret[0][0]+"�졣\n");
			
		}
		else
		{
			me->add("vip/vip_time",ret[0][0]*24*3600);
			write("���ѳɹ������ӹ����Ч��Ϊ"+ret[0][0]+"�졣\n");	
		}
//		me->set("vip/vip_time", ret[0][1]);
		me->set("vip/vip_start_time", time());
		me->set("registered", 3);
		dbquery("UPDATE Users SET Alivedays = 0 WHERE U_Username=" + save_variable(uname));
//		write("���Ĺ��ʱ���Ѿ��Զ������ˡ�\n");

		log_file("nosave/VIP", sprintf(" %s(%s) ע���� %d �죬����ʱ��Ϊ %s��", 
			me->name(1), uname, ret[0][0], ctime(me->query("vip/vip_time"))));

		return 1;
	}

	return 0;
}

int save()
{
	string file;
	object me = this_object();

	if (!stringp(file = me->query_save_file())) 
	{
		return 0;
	}
	
	if (base_name(me) == USER_OB)
	{
		update_viptime(me);
	}

	assure_file(file += __SAVE_EXTENSION__);
	
	if (!save_object(file)) 
	{
		return 0;
	}

	if (me->query_temp("db_quit")) 
	{
		string data;
	
		me->delete_temp("db_quit");
		
		data = replace_string(read_file(file), "", "");
		data = replace_string(data, "\\", "");
		data = replace_string(data, "\"", "");
		data = replace_string(data, "'", "");

		dbquery("REPLACE Data SET "
			"U_ID=" + save_variable(file) + ","
			"U_Time=" + save_variable(time()) + ","
			"U_Data=" + save_variable(data));
	}
	
	// Added by mxzhao 2004/05/07 -->>
	if(me->query("mud_time") && me->query("mud_time")/36000 > me->query("last_backup") )
	{
		if(backup())
		{
			me->set("last_backup", (int)me->query("mud_time")/36000);
			write(HIY"���������Ѿ��Զ������ˡ�\n"NOR);
		}
		/*
		else
		{
			me->set("last_backup", time()-35000);
		}
		*/
	}
	// Added by mxzhao 2004/05/07 <<--

	return 1;
}

int restore()
{
	string file;
	mixed ret;
	object me = this_object();

	if (!stringp(file = me->query_save_file())) 
	{
		return 0;
	}

	file += __SAVE_EXTENSION__;

	ret = dbquery("SELECT U_Data FROM Data WHERE U_ID=" 
		+ save_variable(file));

	if (sizeof(ret) == 1)
	{
		string data = ret[0][0];
		data = replace_string(data, "", "\n");
		data = replace_string(data, "\n\n", "\n");
		data = replace_string(data, "", "");
		data = replace_string(data, "", "\\");
		data = replace_string(data, "", "\"");
		data = replace_string(data, "", "'");

		assure_file(file);
		write_file(file, data, 1);
	}

	if (me->query_temp("db_login")) 
	{
		me->delete_temp("db_login");

		dbquery("DELETE FROM Data WHERE U_ID=" 
			+ save_variable(file));
	}

	return restore_object(file);
}

int backup()
{
	string file;
	string data;
	object link_ob;
	object me = this_object();

	if (!stringp(file = me->query_save_file())) 
	{
		return 0;
	}

	assure_file(file += __SAVE_EXTENSION__);

	if (!save_object(file)) 
	{
		return 0;
	}

	data = replace_string(read_file(file), "", "");
	data = replace_string(data, "\\", "");
	data = replace_string(data, "\"", "");
	data = replace_string(data, "'", "");

	if (!dbquery("REPLACE Backup SET "
		"U_ID=" + save_variable(file) + ","
		"U_Time=" + save_variable(time()) + ","
		"U_Data=" + save_variable(data)))
	{
		return 0;
	}
	
	if(objectp(link_ob = me->query_temp("link_ob")))
		link_ob->backup();

	return 1;
}


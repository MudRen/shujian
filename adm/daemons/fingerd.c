// fingerd.c

// Modified by mxzhao 2004/02/18
// LinuX@SJ 2004/02/28
// ���ӹ��ʱ����ʾ����ȷ���룬���ΪUSER_OB���棬������LOGIN_OB

#include <ansi.h>
#include <net/dns.h>
#include <mudlib.h>

void create()
{
	seteuid( getuid() );
}

string age_string(int time)
{
	int month, day, hour, min, sec;

	sec = time % 60;
	time /= 60;
	min = time % 60;
	time /= 60;
	hour = time % 24;
	time /= 24;
	day = time % 30;
	month = time / 30;
	return (month?month + "m":"") + (day?day + "d":"") +
	(hour?hour + "h":"") + min + "m";
}

int sort(object ob1, object ob2)
{
	if (!interactive(ob1)) return -1;
	if (!interactive(ob2)) return 1;
	return strcmp(query_ip_number(ob1), query_ip_number(ob2));
}

string user_list(object *ob, int flag)
{
	object me;
	string msg;
	string ipname;
	
	int i;
	
	if (! ob || ! sizeof(ob))
		return "û���κη�����������ҡ�\n";
	
	me = this_player();
	msg = "����������������������������������������������������������������������������������������\n" +
		WHT HBBLU "����          �ʺ�          ����          ����                     ����                \n" NOR +
		"����������������������������������������������������������������������������������������\n";
	for(i = 0; i < sizeof(ob); i++)
	{
		if (me && ! me->visible(ob[i]))
		{
			continue;
		}
		if(!ob[i] || !ob[i]->query_temp("link_ob")) continue;
		// Modified by mxzhao 2004/05/18 -->>
		//ipname = wiz_level(me) > 4 ? (query_ip_number(ob[i]) + "("+IP_D->ip2name(query_ip_number(ob[i]))+")") : "--------";
		ipname = ((ob[i]->query_temp("link_ob"))->query_temp("last_from"));
		ipname = wiz_level(me)>4?ipname: "--------";
		// Modified by mxzhao 2004/05/18 <<--
		msg = sprintf("%s%s%-14s%s%-14s%-14s%s%-7s" NOR "%s\n",
			msg, (ob[i]->name() != ob[i]->name(flag) ? HIM : NOR),
			ob[i]->name(flag), NOR, ob[i]->query("id"),
			age_string( (int)ob[i]->query("mud_time")), 
			(interactive(ob[i]) ? ((query_idle(ob[i]) >= 120) ? HIG : NOR) : ob[i]->query("doing") == "closed" ? HIY : HIR),
			(interactive(ob[i]) ? (query_idle(ob[i]) + "s") : ob[i]->query("doing") == "closed" ? "�չ�" : "����"), ipname);
	}
	
	msg += "����������������������������������������������������������������������������������������\n";
	return msg;
}

string finger_all()
{
	object me = this_player();
	object *ob;
	string msg;
	string ipname;
	int i;

	ob = filter_array(objects(), (: userp :));
	ob = sort_array(ob, (: sort :));
	msg = "";
	if (!wizardp(me) || wiz_level(me) < 3)  // player finger wizard���²��ܲ鿴���IP
	{
		for(i=0; i<sizeof(ob); i++) {
			if (!me->visible(ob[i])) continue;
			msg += sprintf("%-14s%-14s%-14s\n",
				ob[i]->query("name"), ob[i]->query("id"),
				!interactive(ob[i])?"������":query_idle(ob[i]) + "s");
		}
		return "��" + MUD_NAME + "��\n" +
		"��������������������������������������\n"
		+ "����          �ʺ�          ����\n" +
		"��������������������������������������\n"
		+ msg +
		"��������������������������������������\n";
	}
	else          // wizard finger
	{
		for (i=0;i<sizeof(ob);i++)
			if (me->visible(ob[i])) break;
		
		if(ob[i]&&ob[i]->query_temp("link_ob"))
		{		
		ipname = ((ob[i]->query_temp("link_ob"))->query_temp("last_from"));
												
		msg += sprintf("%s%-13s%-14s%-14s%-7s%-=50s\n",
			environment(ob[i])?" ":"*",
			ob[i]->query("name"), ob[i]->query("id"),
			age_string(ob[i]->query("mud_time")),
			!interactive(ob[i])?"������":query_idle(ob[i]) + "s",
			// Modified by mxzhao 2004/05/18 -->>			
			ipname);
			// Modified by mxzhao 2004/05/18 <<--
			////query_ip_name(ob[i])+"("+IP_D->ip2name(query_ip_number(ob[i]))+")");
		}
		for(i=i+1; i<sizeof(ob); i++) 
		{
			if (!me->visible(ob[i]) ) continue;
			if(!ob[i] || !ob[i]->query_temp("link_ob")) continue;
			ipname = ((ob[i]->query_temp("link_ob"))->query_temp("last_from"));
			msg += sprintf("%s%-13s%-14s%-14s%-7s%-=50s\n",
				environment(ob[i])?" ":"*",
				ob[i]->query("name"), ob[i]->query("id"),
				age_string(ob[i]->query("mud_time")),
				!interactive(ob[i])?"������":query_idle(ob[i]) + "s",
				query_ip_number(ob[i]) && query_ip_number(ob[i]) == query_ip_number(ob[i-1])?
				// Modified by mxzhao 2004/05/18 -->>
				//"��ַͬ��":query_ip_name(ob[i])+"("+IP_D->ip2name(query_ip_number(ob[i]))+")");
				"��ַͬ��":ipname);
				// Modified by mxzhao 2004/05/18 -->>
		}
		return "�� " + MUD_NAME + HIW"����\n"NOR +
		"����������������������������������������������������������������������������������������\n"
		HIC" ����         �ʺ�          ����          ����   ����\n"NOR +
		"����������������������������������������������������������������������������������������\n"
		+ msg +
		"����������������������������������������������������������������������������������������\n"
		"* ��ʾ��¼��\n";
	}
}

string reg(int i)
{
	if (i < 2)
		return "δע��";
	if (i == 2)
		return "����û�";
	return "����û�";
}

string finger_user(string name)
{
	object me = this_player(), ob, body;
	string msg;
	object user;
//	mixed *info;
	int public_flag;
	int last_on = strlen(name);
	int birthday;
	int days;
	
	object *uob;
	int same;
	if (INTERMUD_MUD_NAME != "SJ" && INTERMUD_MUD_NAME != "SJTX" )
	{
		while (last_on--) if (name[last_on] < 'a' || name[last_on] > 'z')
		return name+"��ʲô������\n";
	}
	if (name == "guest") 
	{
		return "�ÿ���ʲô�ÿ��ģ�\n";
	}
	
	user = new(USER_OB);
	if (!user) 
	{
		write("���ڿ������������޸�ʹ��������ĳ���\n\n");
		return 0;
	}

	seteuid(name);
	export_uid(user);
	seteuid(getuid());
	
	if(!user->restore()) 
	{
		destruct(user);
		return "û��������Ү��\n";
	}

	user->set_name(user->query("name"), ({ name}));

	ob = new(LOGIN_OB);
	ob->set("id", name);
	if (!ob->restore()) 
	{
		destruct(ob);
		return "û�������ҡ�\n";
	}

	last_on = ob->query("last_on");
/*
	if (!ob->query("login_fail") && !objectp(body = LOGIN_D->find_body(name))) {
		info = get_dir(DATA_DIR + "login/" + name[0..0] + "/" + name + ".o", -1);
		if (info[0][2] > last_on) last_on = info[0][2];
	}
*/
	if (objectp(body = LOGIN_D->find_body(name))) 
	{
		public_flag = body->query("env/public")?1:0;
		birthday = body->query("birthday");
		if (me == body) public_flag = 1;
	} 
	else 
	{
		body = LOGIN_D->make_body(ob);
		if (!body->restore()) 
		{
			destruct(ob);
			destruct(body);
			destruct(user);
			return "û�������ҡ�\n";
		}

		public_flag = body->query("env/public")?1:0;
		birthday = body->query("birthday");
		destruct(body);
	}
	if (!wizardp(me) && !me->id(name)) 	// player finger
	{
		msg = HIC"\n�q�� ��ҵ��� �������������������������������������r\n";
		msg +=  sprintf(
			"��"WHT"Ӣ�Ĵ���  ��%-36s"HIC"��\n"
			"��"WHT"ԭʼ����  ��%-28s"HIR"%s"HIC"��\n"
			"��"WHT"Ȩ�޵ȼ�  ��%-28s"HIR"%s"HIC"��\n"
//			"��"WHT"E-mail��ַ��%-36s"HIC"��\n"
			"��"WHT"ע�����  ��%-28s"HIR"%s"HIC"��\n"
			"��"WHT"�ϴ��˳�  ��%-28s"HIR"%s"HIC"��\n",
			name,
			ob->query("name"),
			"  �x�x  ",
			wiz_level(name)==5?"����Ա":"���",
			"��������",
//			public_flag?ob->query("email"):"��������",
			reg(user->query("registered")),
			"��������",
			last_on&&!wiz_level(name)?ctime(last_on):"�����û",
			"  ����  "

		);
		msg += "�t�������������������������������������������������s\n"NOR;

		if (objectp(body = LOGIN_D->find_body(name)) && geteuid(body)==name)
			if (me->visible(body))
				msg += sprintf(" %sĿǰ���������С�\n %s", body->name(1), body->long(1));
	} 
	else 	// wizard finger
	{
		// Modified by mxzhao 2004/05/18 -->>
		//string tmp = ob->query("last_from") + "", tmp1;
		string tmp1;
		// Modified by mxzhao 2004/05/18 <<--

		msg = HIC"\n�q�� ��ҵ��� �������������������������������������r\n";

// Modified by mxzhao 2004/02/18
		{
			mixed ret = dbquery("select U_Site, Alivedays from Users "
				"where U_Username="+save_variable(name));

			if (sizeof(ret) == 1)
			{
				tmp1 = ret[0][0];
				days = ret[0][1];
			}
			else
			{
				tmp1 = "�Ѿ���ɱ";
				days = 0;
			}
		}

/*		{
			mixed mysql = db_connect("localhost", "mud", "root"), rows, res = ({ "�Ѿ���ɱ", 0 });

			if (intp(mysql)) {
				rows = db_exec(mysql, "select U_Site,Alivedays from " + INTERMUD_MUD_NAME + "_Users where U_Username="+save_variable(name));
				if (rows==1)
					res = db_fetch(mysql, 1);
				db_close(mysql);
			}
			tmp1 = res[0];
			days = res[1];
		}
*/
// End

		msg +=  sprintf(
			"��"WHT"Ӣ�Ĵ���  ��%-36s"HIC"��\n"
			"��"WHT"ԭʼ����  ��%-28s"HIR"%s"HIC"��\n"
			"��"WHT"Ȩ�޵ȼ�  ��%-28s"HIR"%s"HIC"��\n"
			"��"WHT"E-mail��ַ��%-28s"HIR"%s"HIC"��\n"
			"��"WHT"ע�����  ��%-28s"HIR"%s"HIC"��\n",
//			ob->query("id")+"@"+tmp1+" "+days,
			ob->query("id"),
			ob->query("name"),
			"  �x�x  ",		
			SECURITY_D->get_status(name),
			"��������",			
			ob->query("email"),
			"��������",
			reg(user->query("registered")),
			"  ����  "
		);
		msg += "�t�������������������������������������������������s\n"NOR;
		if (wizardp(me))
			msg += CHINESE_D->chinese_date(birthday, 1)+"\n";
		
		// Modified by mxzhao 2004/05/18 -->>
		//sscanf(tmp, "%s(%s)", tmp, tmp1);
		//msg += sprintf("�ϴ����ߵ�ַ��%s(%s)\n�ϴε�¼ʱ�䣺%s\n", tmp,
		//	IP_D->ip2name(tmp1) ,last_on?CHINESE_D->chinese_date(last_on, 1):"��");
		if (wiz_level(me) > 2){
		msg += sprintf("�ϴ����ߵ�ַ��%s\n�ϴε�¼ʱ�䣺%s\n", 
			ob->query("last_from"), last_on?CHINESE_D->chinese_date(last_on, 1):"��");
		}
		else
		{
		msg += sprintf("�ϴε�¼ʱ�䣺%s\n", 
			last_on?CHINESE_D->chinese_date(last_on, 1):"��");	
		}
		// Modified by mxzhao 2004/05/18 -->>
		if (user->query("registered") == 3)
			msg += sprintf("���ʣ��ʱ�䣺%s\n", CHINESE_D->chinese_time(user->query("vip/vip_time") - time()));
		if( objectp(body = LOGIN_D->find_body(name)) && geteuid(body)==name ) 
		{
			if (me->visible(body)) 
			{
				object link_ob = body->query_temp("link_ob");

				if (wiz_level(me) > 2 )
				{
					msg += sprintf("%s%sǰ��%s��Ŀǰ��%s\n",
						body->query("name")+"("+name+")",
						CHINESE_D->chinese_time(time()-last_on),
				// Modified by mxzhao 2004/05/18 -->>
						ob->query("last_from"), 
						objectp(link_ob)?link_ob->query_temp("last_from"):"������");
						//IP_D->ip2name(tmp1),
						//IP_D->ip2name(query_ip_number(body)));
				
				//msg += sprintf("%sĿǰ��%s�С�\n%s",
				//	me->id(name)?"��":body->name(1), 
				//	objectp(link_ob)?"�� " + link_ob->query_temp("last_from") + ":" 
				//	+ query_ip_rport(body) + " ����":"����", body->long(1));
				}
				else
				{
					msg += sprintf("%sĿǰ��%s�С�\n%s",
					me->id(name)?"��":body->name(1), 
					objectp(link_ob)?"����":"����", body->long(1));
	
				
				}
				// Modified by mxzhao 2004/05/18 <<--
			}
		} 

		if (wiz_level(me) > 2)
		{
			uob = filter_array(users(),
				(: query_ip_number($1) == $(query_ip_number(body)) :));

			same = sizeof(uob);
			if (same > 1)
			{
				msg += sprintf("�õ�ַһ���� "HIY"%d"NOR" λʹ���ߡ�\n", same);
				if (previous_object() != find_object(user->query("id")))
					// I won't return the list if this is
                  	// called from a chat user
					msg += user_list(uob, 1);
			} 
		}
	}

	destruct(ob);
	destruct(user);
	return msg;
}

varargs string remote_finger_user(string name, int chinese_flag)
{
	object ob, body;
	string msg;

	ob = new(LOGIN_OB);
	ob->set("id", name);
	if( !ob->restore() )
		return chinese_flag ? "û�������ҡ�\n" : "No such user.\n";
	if( chinese_flag ){
		msg = HIC"\n�q�� ��ҵ��� �������������������������������������r\n";
		msg +=  sprintf("��"WHT"Ӣ�Ĵ���  ��\t%-34s"HIC"��\n��"WHT"��    ��  ��\t%-34s"HIC"��\n��"
			WHT"Ȩ�޵ȼ�  ��\t%-34s"HIC"��\n��"WHT"E-mail��ַ��\t%-34s"HIC"��\n��"
			WHT"ע�������\t%-34s"HIC"��\n��"WHT"�ϴ��˳���\t%-34s"HIC"��\n",
				ob->query("id"),
				ob->query("name"),
				SECURITY_D->get_status(name),
				ob->query("email"),
				ob->query("registered")>1?"��ע��":"��δע��",
				ob->query("last_from"));
		msg += "�t������������������������������������������ SJ ���s\n"NOR;
		msg += CHINESE_D->chinese_date(ob->query("last_on"), 1);
	 }
	else	msg =  sprintf(
		"\nName\t: %s\nStatus\t: %s\nEmail\t: %s\nLastOn\t: %s( %s )\n\n",
		capitalize(ob->query("id")),
		SECURITY_D->get_status(name),
		ob->query("email"),
		ob->query("last_from"),
		CHINESE_D->chinese_date(ob->query("last_on"), 1)
	);
	if( body = find_player(name) ) {
		if( !this_player() || this_player()->visible(body) )
			msg += chinese_flag ?
				("\n" + ob->query("name") + "Ŀǰ�������ϡ�\n"):
				("\n" + capitalize(name) + " is currently connected.\n");
	}

	destruct(ob);
	return msg;
}

object acquire_login_ob(string id)
{
	object ob;

	if( ob = find_player(id) ) {
		// Check if the player is linkdead
		if( ob->query_temp("link_ob") )
			return ob->query_temp("link_ob");
	}
	ob = new(LOGIN_OB);
	ob->set("id", id);
	if (!ob->restore()) destruct(ob);
	return ob;
}

string get_killer()
{
	string msg = "";
	object *ob = filter_array(children(USER_OB), (: userp :));

	foreach (object item in ob)
		if (item->query_condition("killer") > 0)
			msg += sprintf("%-60s ʱ�ޣ�%s��ʱ��\n",
				item->short(1), chinese_number((item->query_condition("killer")+5)/6));
	if (msg == "")
		return "		  �����ΰ����á�\n";
	return "\n���ڱ������ڼ��������˷���\n\n" + msg;
}
//�������� get_last_on()���ڻ�������һ���Զ�����ʱ���ʱ��
string get_last_on(string name)
{
	object ob;
	string msg;
	ob = new(LOGIN_OB);
	ob->set("id",name);
	if(!ob->restore()) return 0;
	msg = ob->query("last_on");
	destruct(ob);
	return msg;
}

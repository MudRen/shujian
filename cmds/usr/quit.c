// quit.c
// Modified by mxzhao 2004/05/18 


#include <ansi.h>
#include <command.h>

inherit F_DBASE;

void do_quit(object, int);

void create()
{
	seteuid(getuid());
	set("channel_id", "����ָ��");
}

int main(object me, string arg)
{
	object link_ob, env;
	int flag = 0;

	if (me->query_temp("quit") > uptime())
	{
		return notify_fail("�����˳������У����Ժ�\n");
	}

	link_ob = me->query_temp("link_ob");

	// We might be called on a link_dead player, so check this.
	if (link_ob) 
	{
		// Are we possessing in others body ?
		if (link_ob->is_character()) 
		{
			write("��Ļ��ǻص�" + link_ob->name(1) + "�����ϡ�\n");
			exec(link_ob, me);
			link_ob->setup();
			return 1;
		}
	}
	//��ʾֻ���ڶ���20�����ڲŻ�ȥִ�����
	if ((time()-me->query_temp("netdead")) < 1200)
	{
	//��ֹ����wmpcmd ��quit

		if (me->query_condition("killer")&&!wiz_level(me))
		{
			return notify_fail("��������ͨ���������Զ�ܵ���ʵ������ȥ��\n");
		}
            if (me->query_condition("no_quit"))
                   return notify_fail("��������ս����δ�����������Զ�ܵ���ʵ������ȥ��\n");
		if (me->is_busy())
		{
			return notify_fail("��������æ���������£������˳���Ϸ��\n");
		}
		if (me->is_fighting())
		{
			return notify_fail("����������ս���������˳���Ϸ��\n");
		}
	//end ,��	����Ӧ��û�н��� interactive �ж���,͵��һ��
	}
	//this_player(1) == me &&  kick it 	
	if (this_player() && interactive(me)) 
	{
		if (me->query_condition("killer")&&!wiz_level(me))
		{
			return notify_fail("��������ͨ���������Զ�ܵ���ʵ������ȥ��\n");
		}
             if (me->query_condition("no_quit"))
                    return notify_fail("��������ս����δ�����������Զ�ܵ���ʵ������ȥ��\n");
		if (me->is_busy())
		{
			return notify_fail("��������æ���������£������˳���Ϸ��\n");
		}
		if (me->is_fighting())
		{
			return notify_fail("����������ս���������˳���Ϸ��\n");
		}
	} 
	else 
	{
		flag = -1;
	}

	if ((env = environment(me)) && !env->query("no_save") 
		&& !me->is_ghost() && !clonep(env))
	{
		me->set("startroom", base_name(env));
	}
	
	if (env->query("no_save") && strsrch(file_name(env), "/d/group/") == 0)
	{
		me->set("startroom", "/d/city/kedian");	
	}
	if (me->query("combat_exp") < 100000 && me->query("combat_exp") > 3000 )
	{
		write("��Ϊ�㵱ǰ�ľ���ֵС�� 100000�������´����߻������ݱ�����ջ��\n");
		me->set("startroom", "/d/city/kedian");	
	}
	if ( getuid(me) == "mastera")
	{
		me->set("startroom", "/d/wizard/master_room");
	}

	me->set_temp("quit", uptime() + 203);

	CHANNEL_D->do_channel(this_object(), 
		wiz_level(me)?"wiz":"sys", 
		me->short() + NOR " ׼���뿪��Ϸ�ˡ�");

	if (!flag && !wizardp(me) && env 
		&& !env->query("valid_startroom")) 
	{
		write("�����˳���Ϸ����\n");
		me->delete_temp("combat_yield");
		call_out("do_quit", 3, me, 100);
	} 
	else 
	{
		do_quit(me, flag);
	}

	return 1;
}

void do_quit(object me, int t)
{
	int i, j;
	object link_ob;
	object *inv;
	string log = "";

	if (!me) 
	{
		return;
	}

	if (t > 0 
		&& (!living(me) || me->is_busy() 
		|| me->query_temp("combat_yield") || me->is_fighting() 
		|| me->is_perform() || me->is_exert())) 
	{
		me->delete_temp("combat_yield");
		call_out("do_quit", 2, me, t - 1);
		return;
	}

	if (t >= 0 && (me->query("qi") < 0
	|| me->query("eff_qi") < 0
	|| me->query("jing") < 0
	|| me->query("eff_jing") < 0
	|| me->query("jingli") < 0
	|| me->query_condition("killer"))) 
	{
		message("channel", "��Ϊ����ǰ��״̬���ȶ����˳������Զ���ֹ��\n", me);
		me->delete_temp("quit");
		return;
	}

	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++)
	{
		if( (int)inv[i]->query("imbued") && stringp(inv[i]->query("save_id")) )
		{
			log += inv[i]->query("save_id") + ",";
			inv[i]->set_temp("quit_dest",1);
			if( inv[i]->query("imbued") > 3 )
			{
				inv[i]->set("weapon_mp/utime", time());
			}

			destruct(inv[i]);
			continue;
		}

		if( !wiz_level(me) && !inv[i]->query_autoload() && !inv[i]->query("unique"))
		{
			DROP_CMD->do_drop(me, inv[i]);
		}
		else if(inv[i] && inv[i]->query("unique"))
		{
			destruct(inv[i]);
		}
	}

	if( strlen(log) > 3 )
	{
		log_file("career/worker", sprintf("quit    :%-8s:%s",me->query("id"),log), me);
	}

	if( me->query_team())
	{
		me->dismiss_team();
	}

	IRC_CMD->main(me, "/leaveall");

	i = uptime()-me->query_temp("time");
	tell_object(me, HIW"\n���齣����"NOR"�������ܹ�����" 
		+ CHINESE_D->chinese_time(i) + "��\n");
	j = me->query("combat_exp") - me->query_temp("combat_exp");
	tell_object(me, "\t  ����ֵ"
		+(j<0?"������" + (-j) + "��": j > 0?"������" + j +"��":"û�б䶯")+"��\n");

	me->update_age();
/*
	if (me->query("online_total") > 70200)
		tell_object(me, "\t  �������Ϣ"
			+CHINESE_D->chinese_time(me->query("online_total")/3+3600)
			+"������\n");
	else
*/	tell_object(me, "\t  ��ӭ���´�������\n");

	if (i > 600 && !wizardp(me) && me->query_temp("robottest") <= me->query_temp("time")) 
	{	// ���û���ܵ��������˼��
		if (me->add("no_robot_check", 1) > 1) 
		{
//			me->add("online_total", 3600);
			me->delete("no_robot_check");
		}
	} 
	else 
	{
		me->delete("no_robot_check");
	}

	if (!wizardp(me) || !me->query("env/invisibility"))
	{
		message("system", me->name() + "�뿪��Ϸ��\n", environment(me), me);
	}

	CHANNEL_D->do_channel(this_object(), 
		wiz_level(me)?"wiz":"sys", me->short(1) + NOR " �뿪��Ϸ�ˡ�");

	log_file("USAGE",
		sprintf("%-19s%s�˳�\n",
		me->query("name")+"("+capitalize(""+me->query("id"))+")",
		interactive(me)?"":"����"), me);
	
	if (link_ob = me->query_temp("link_ob")) 
	{
		link_ob->set("last_on", time() + (i > 300 ? -30 : 0));
		link_ob->set("last_from", link_ob->query_temp("last_from"));
		link_ob->set_temp("db_quit", 1);
		link_ob->save();
		destruct(link_ob);
		me->set_temp("db_quit", 1);
	}

	i = (i + 59) / 60;
	if (!wiz_level(me) && i
		&& (j = (me->query("combat_exp") - me->query_temp("combat_exp"))*60 / i) > 6000)
	{
		log_file("static/EXP",
			sprintf("%s �ϴξ��飺%d�����ξ��飺%d��ƽ����%d/Сʱ������ʱ��Ϊ %d �֡�\n",
			geteuid(me), me->query_temp("combat_exp"),
			me->query("combat_exp"), j, i));
	}

	if (!wiz_level(me) && i>=180
		&& (j = (me->query("combat_exp") - me->query_temp("combat_exp"))*60 / i) > 6000)
	{
		log_file("static/new_EXP",
			sprintf("%s �ϴξ��飺%d�����ξ��飺%d��ƽ����%d/Сʱ������ʱ��Ϊ %d �֡�\n",
			geteuid(me), me->query_temp("combat_exp"),
			me->query("combat_exp"), j, i));
	}


	TOP_CMD->add_rank(me);
	me->save();
	destruct(me);
}

int help(object me)
{
	write(@HELP
ָ���ʽ : quit

��������ʱ�뿪��Ϸʱ, �����ô�ָ�
HELP
    );
    return 1;
}

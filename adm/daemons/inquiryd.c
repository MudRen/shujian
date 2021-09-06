// inquiryd.c
// Created by Annihilator@ES2 (01-19-95)
// Modified by Xiang for XKX (12/20/95)
// Modified by snowman@SJ 20/06/2000

// This function handles the default inquiry between ppls and npcs to
// make npc more talktive. This is the '<me> ask <ob> about <topic>'
// case.

#include <ansi.h>

string find_gf_wanted_target(mapping target, int shen)
{
        object npc, where;
	string place;
	
	if( !mapp(target) || !objectp(target["base"]) || !stringp(target["name"]) )
		return "�������ϵ��ּ�ģ�����壬��֪����Ҫ��˭����";

	npc = target["base"];
	if( !npc || !objectp(npc) ){
        	if ( shen )
        		return "Ŷ������ҾͲ�����ˣ��⸽��û����"+target["name"]+"���ˡ�";
        	else 	return target["name"]+"��û��������æ���أ�����߿����������ﷳ�ң�";
        }
        
        where = environment(npc);
        if ( !where ){
        	if ( shen )
        		return target["name"]+"�����������������������������أ���������ԣ��벻�����ˣ�";
        	else 	return "����"+target["name"]+"�ǰɣ��ٺ٣��Ҽ������ɾͲ������㣡";
        }     
        if( userp(where) ){
        	place = where->name();
        	if ( shen )
        		return target["name"]+"���ղ�����˵��"+place+"ץȥ�ˣ�";
        	else 	return "����"+target["name"]+"����������������ձ�"+place+"ץ�ߣ�";
        }
        if( strsrch(base_name(where), "/d/") != 0 )
        	return "��������㵽�������ȥ�ɡ�";
        if( strsrch(base_name(where), "/d/city/") == 0 )
        	return "û��˵�����㵽�������ȥ�ɡ�";
        if( !stringp(place = TASK_D->get_regions(base_name(where))) )
        	place = environment(npc)->query("short");
        else if( random(5) == 1 )
        	place += environment(npc)->query("short");
        if ( shen )
        	return target["name"]+"�ǰɣ��Һ�������˵������"+place+"����ת���أ�";
        else 	return "������"+target["name"]+"����������������"+place+"���������ȥ�����ɣ�";
}


int parse_inquiry(object me, object ob, string topic)
{
	object wenshu;
	mapping target;
	
	switch( topic ) {
		case "name":
		case "����":
			message_vision(CYN "$N��$n�ʵ�������" + RANK_D->query_respect(ob) + "���մ�����\n" NOR, me, ob);
			return 1;
		case "here":
		case "�˵�":
			message_vision(CYN "$N��$n�ʵ�����λ" + RANK_D->query_respect(ob) + "��"
			+ RANK_D->query_self(me) + "�����󱦵أ���֪������Щʲô�������飿\n" NOR, me, ob);
			return 1;
		case "rumors":
		case "����":
			message_vision(CYN "$N��$n�ʵ�����λ" + RANK_D->query_respect(ob)
			+ "����֪�����û����˵ʲô��Ϣ��\n" NOR, me, ob);
			return 1;
		case "news":
		case "����":
		case "����":
			message_vision(CYN "$N��$n�ʵ�����λ" + RANK_D->query_respect(ob)
			+ "����֪�����û����˵ʲô���£�\n" NOR, me, ob);
			return 1;
		case "marry":
			message_vision(CYN "$N����һ˫���ۣ������������$n"+CYN"�ʵ���������λ"+RANK_D->query_respect(ob)
						+"�Ƿ���䣿\n" NOR,me,ob);
			return 1;
		case "food":
			message_vision(CYN "$N�����������$n"+CYN"�ʵ�������֪��λ"+RANK_D->query_respect(ob)
							+"�Ƿ��ܸ��ҵ�Ե�, �����Ѿ�����û�н�ʳ�ˣ���\n" NOR,me,ob);
			return 1;
		
		case "water":
			message_vision(CYN "$N�����������$n"+CYN"�ʵ�������֪��λ"+RANK_D->query_respect(ob)
							+"�Ƿ��ܸ��ҵ�ȵ�, ���¿ڿʵúܣ���\n" NOR,me,ob);
			return 1;
		
		case "money":
			message_vision(CYN "$N˫�ֱ�ȭ��$n"+CYN"�ʵ��������³���զ�������߽���ȱ��Щ�̲�,��λ"+RANK_D->query_respect(ob)
							+"�Ƿ���ʩ��һ��, ���²����м�����\n" NOR,me,ob);
			return 1;
		case "friend":
			message_vision(CYN "$N˫�ֱ�ȭ��$n"+CYN"˵�������ĺ�֮�ڽ��ֵ�Ҳ,��λ"+RANK_D->query_respect(ob)
							+",��֪Ը�������½������ѡ�\n" NOR,me,ob);
			return 1;
		/*case "all":
			message_vision(CYN "$N��$n�ʵ�����λ" + RANK_D->query_respect(ob)
				+ "��������֪����Щ���飿\n" NOR, me, ob);
			return 1;*/
		case "wanted":
		case "ͨ����":
			if( !userp(me) ) return 0;
			if( !objectp(wenshu = present("tiebu wenshu", me)) ) return 0;
			if( strsrch(base_name(environment(ob)), "/d/city/") == 0 ) return 0;
			message_vision(CYN "$N��$n�ʵ�����λ" + RANK_D->query_respect(ob)
				+ "����֪�����û���������������ͨ��������Ϣ��\n" NOR, me, ob);
			me->receive_damage("jingli", 50+random(100), "����������϶�");
			if( random(15) < 10 ) return 1;
			if( wenshu->query("asked_times") >= 3 ) return 1;
			if( !mapp(target = wenshu->query("target")) )
				ob->set("inquiry/" + topic, "Ц���������ſհ׵���������"+RANK_D->query_self(ob)+"���İ���");

			else ob->set("inquiry/" + topic, find_gf_wanted_target(target, ob->query("shen") > 0));
			wenshu->add("asked_times", 1);
			call_out("del_inquiry", 1 , ob, topic);
			return 1;
		default:
			return 0;
	}
}

void del_inquiry(object ob, string topic)
{
	if( !ob ) return;
	ob->delete("inquiry/" + topic);
}


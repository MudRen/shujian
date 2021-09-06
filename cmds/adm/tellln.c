// tell.c
// Modified by Numa 2000.1.27 For Can tell whom added you in his friend_user.
// modified by snowman@SJ 25/11/2000
// faster friend_user check.

inherit F_CLEAN_UP;

#include <ansi.h>
#include <mudlib.h>
#include <net/dns.h>

int help(object me);

void create() {seteuid(getuid());}

int main(object me, string arg)
{
        string target, msg, mud, *friend_list;
        object obj;

        if( !arg || sscanf(arg, "%s %s", target, msg)!=2 ) return help(me);

        if( sscanf(target, "%s@%s", target, mud)==2 ) {
                if (me->query("combat_exp") < 500000)
                        return notify_fail("�������������������ʹ��ǧ�ﴫ����\n");
                GTELL->send_gtell(mud, target, me, msg);
                write("��·ѶϢ���ͳ�������Ҫ�Ժ���ܵõ���Ӧ��\n");
                return 1;
        }

        obj = LOGIN_D->find_body(target);
        if( !obj || !me->visible(obj)) 
                return notify_fail("û������ˡ�\n");
        if( obj == me) 
                return notify_fail("�����Լ���\n");
        if( !interactive(obj)) 
                return notify_fail("����˶����ˡ�\n");
        if( !wizardp(me) && (obj->query("env/tell") == me->query("id"))) {
                write(GRN "�����" + obj->query("name") + "��" + msg + "\n" NOR);
                message("channel", sprintf( GRN "%s�����㣺%s\n" NOR,
                        obj->visible(me)?(me->query("name")+"("+capitalize(me->query("id"))+")"):me->name(), msg), obj);
                obj->set_temp("reply", me);
                return 1;
        }

// Add Friend_user tell From Here.
        friend_list = obj->query("friend_user");
        if( !arrayp(friend_list) ) obj->delete("friend_list");
        else if( sizeof(friend_list) >0 ) {
                if ( member_array(me->query("id"), obj->query("friend_user") ) !=-1 ) {
                        write(GRN "�����" + obj->query("name") + "��" + msg + "\n" NOR);
                        message("channel", sprintf( GRN "%s�����㣺%s\n" NOR,
                                obj->visible(me)?(me->query("name")+"("+capitalize(me->query("id"))+")"):me->name(), msg), obj);
                //���ӷ������أ�
                if (query_idle(obj) >= 120)
                        write(HIM "����" + obj->name(1) +
                        HIM "�Ѿ�������" + chinese_number(query_idle(obj) / 60) +
                        "�����ˣ����²������̻ش��㡣\n"NOR);
                        obj->set_temp("reply", me);
                        return 1;
                }
        }
// This Is End.

        if (!wizardp(me) && userp(me) && me->query("id") == obj->query("env/block"))
                return notify_fail(obj->query("name")+"��������Ϲ����\n");
        if (!wizardp(me) && userp(me) && obj->query("env/block")=="YES")
                return notify_fail(obj->query("name")+"��æ����ʲô�´�����˵�ɣ�\n");

	//Add Time Limit By Ciwei
	if(uptime()-me->query_temp("last_tell_time",1) < 3 )
		me->add_temp("consider_tell_forbid",1);
	else
	{
		me->add_temp("consider_tell_forbid",-1);
		if( uptime()-me->query_temp("last_tell_time",1) > 60)
			me->delete_temp("consider_tell_forbid");
	}
	
	if(!me->query_temp("consider_tell_forbid") || me->query_temp("consider_tell_forbid")<0 ) me->delete_temp("consider_tell_forbid");
	else if(me->query_temp("consider_tell_forbid")>5)
		return notify_fail("˵����̫����С��ҧ����ͷ��\n");
			
	me->set_temp("last_tell_time",uptime());
	//End
	
        write(GRN "�����" + obj->query("name") + "��" + msg + "\n" NOR);
        message("channel", sprintf( GRN "%s�����㣺%s\n" NOR,
                obj->visible(me)?(me->query("name")+"("+capitalize(me->query("id"))+")"):me->name(), msg), obj);
        //���ӷ������أ�
        if (query_idle(obj) >= 120)
                write(HIM "����" + obj->name(1) +
                      HIM "�Ѿ�������" + chinese_number(query_idle(obj) / 60) +
                      "�����ˣ����²������̻ش��㡣\n"NOR);
        obj->set_temp("reply", me);
        return 1;
}

string remote_tell(string cname, string from, string mud, string to, string msg)
{
        object ob;

        if( ob = LOGIN_D->find_body(to) ) {
        if ((!wizardp(ob) || !ob->query("env/invisibility"))) {
                if (ob->query("env/block") == "YES")
                        return "ǧ�ﴫ��@" +INTERMUD_MUD_NAME+ "�����㣺"+ob->query("name")+"��æ����ʲô�´�����˵�ɣ�";
                if( cname )
                        message("channel", sprintf(GRN "%s(%s@%s)�����㣺%s\n" NOR,
                                cname, capitalize(from), mud, msg), ob);
                else
                        message("channel", sprintf(HIG "%s@%s �����㣺%s\n" NOR,
                                capitalize(from), mud, msg), ob);
                ob->set_temp("reply", from + "@" + mud);
                return sprintf("�����%s(%s@%s)��%s", ob->query("name"), capitalize(to), INTERMUD_MUD_NAME, msg);
        }
        }
        return "ǧ�ﴫ��@" +INTERMUD_MUD_NAME+ "�����㣺û�� "+to+" �����ҡ�";
}

int help(object me)
{
        write(@HELP
ָ���ʽ��tell <ĳ��> <ѶϢ>

����������ָ��������ط���ʹ����˵����
��ػ����������ã�
��׼�κ��˸����㣺set block
��׼ĳ���˸����㣺set block ���� id
����ĳ���˸����㣺set tell ���� id

�������ָ�reply
HELP
);
        return 1;
}
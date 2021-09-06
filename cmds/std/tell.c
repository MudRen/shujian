// tell.c
// Modified by Numa 2000.1.27 For Can tell whom added you in his friend_user.
// modified by snowman@SJ 25/11/2000
// faster friend_user check.

inherit F_CLEAN_UP;

#include <ansi.h>
#include <mudlib.h>
#include <net/dns.h>

int help(object me);
int is_sub(string s_str, string m_str);
void create() {seteuid(getuid());}

int main(object me, string arg)
{
	string target, msg, mud;
	object obj;
	string no_tell,can_tell;
	string my_id;

	if( !arg || sscanf(arg, "%s %s", target, msg)!=2 ) return help(me);

	if( sscanf(target, "%s@%s", target, mud)==2 ) {
		if (me->query("combat_exp") < 500000)
			return notify_fail("�������������������ʹ��ǧ�ﴫ����\n");
		GTELL->send_gtell(mud, target, me, msg);
		write("��·ѶϢ���ͳ�������Ҫ�Ժ���ܵõ���Ӧ��\n");
		return 1;
	}

	obj = LOGIN_D->find_body(target);
	if (!obj || !me->visible(obj))
		return notify_fail("û������ˡ�\n");

	if( obj == me)
		return notify_fail("�����Լ���\n");

	if( !interactive(obj))
		return notify_fail("����˶����ˡ�\n");

	//if (!wizardp(me) && userp(me) && me->query("id") == obj->query("env/block"))
	//	return notify_fail(obj->query("name")+"��������Ϲ����\n");
	
	my_id = me->query("id");
	no_tell = obj->query("env/block");
	if (! wizardp(me) && (no_tell == "all" || no_tell == "ALL" ||
	    is_sub(my_id, no_tell))){
	    	can_tell = obj->query("env/tell");
                if (! is_sub(my_id, can_tell))
		       	return notify_fail(obj->query("name")+"��������Ϲ����\n");
	}

	if (!wizardp(me) && (obj->query("env/tell") == me->query("id")))
		;
	else if (!wizardp(me) && userp(me) && obj->query("env/block")=="YES") {
		// Add Friend_user tell From Here.
		string *friend_list = obj->query("friend_user");

		if (!arrayp(friend_list)) {
			obj->delete("friend_user");
			friend_list = ({ });
		}
		if (member_array(me->query("id"), friend_list) == -1)
			return notify_fail(obj->query("name")+"��æ����ʲô�´�����˵�ɣ�\n");
	}

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
	string no_tell;
	
	from = lower_case(from);
	to = lower_case(to);
	if (!(ob = LOGIN_D->find_body(to))
	|| ob->query("env/tell") != from
	&& wizardp(ob)
	&& ob->query("env/invisibility")
	&& wiz_level(from) < wiz_level(ob))
		return "ǧ�ﴫ��@"+INTERMUD_MUD_NAME+"�����㣺û�� "+to+" �����ҡ�";

//	if (from == ob->query("env/block")
//	&& wiz_level(from) < wiz_level(ob))
//		return "ǧ�ﴫ��@"+INTERMUD_MUD_NAME+"�����㣺"+ob->query("name")+"��������Ϲ����";
	
	no_tell = ob->query("env/block");
	if ( no_tell == "all" || no_tell == "ALL" ||
	    is_sub(from, no_tell))
		return "ǧ�ﴫ��@"+INTERMUD_MUD_NAME+"�����㣺"+ob->query("name")+"��������Ϲ����";

	if (ob->query("env/tell") != from
	&& wiz_level(from) < wiz_level(ob)
	&& ob->query("env/block") == "YES") {
		string *friend_list = ob->query("friend_user");

		if (!arrayp(friend_list)) {
			ob->delete("friend_user");
			friend_list = ({ });
		}
		if (member_array(from, friend_list) == -1)
			return "ǧ�ﴫ��@"+INTERMUD_MUD_NAME+"�����㣺"+ob->query("name")+"��æ����ʲô�´�����˵�ɣ�";
	}

	if (!interactive(ob))
		return "ǧ�ﴫ��@"+INTERMUD_MUD_NAME+"�����㣺"+"����˶����ˡ�";

	if (cname)
		message("channel", sprintf(GRN "%s(%s@%s)�����㣺%s\n" NOR,
			cname, capitalize(from), mud, msg), ob);
	else
		message("channel", sprintf(GRN "%s@%s �����㣺%s\n" NOR,
			capitalize(from), mud, msg), ob);
	ob->set_temp("reply", from + "@" + mud);
	return sprintf("�����%s(%s@%s)��%s", ob->query("name"), capitalize(to), INTERMUD_MUD_NAME, msg);
}

int is_sub(string s_str, string m_str)
{
        if (! m_str || ! s_str) return 0;
        return strsrch("," + m_str + ",", "," + s_str + ",") != -1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��tell <ĳ��> <ѶϢ>

����������ָ��������ط���ʹ����˵����
��ػ����������ã�
��׼�κ��˸����㣺set block all|ALL
��׼ĳ���˸����㣺set block ���� id
��׼ĳ���˸����㣺set block id1,id2,id3.....
����ĳ���˸����㣺set tell ���� id
����ĳ���˸����㣺set tell id1,id2,id3......

�������ָ�reply
HELP
);
	return 1;
}

// qiangui.c
// by augx@sj  3/13/2002

#include <ansi.h>
inherit ITEM;
#include <group.h>

void create()
{
	set_name(YEL"Ǯ��"NOR, ({ "qian gui","cash box" }));
	set_weight(15000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�߷�Ǯ��Ǯ���������������\n���ʣ�check\n��Ǯ��deposit\nȡǮ��withdraw\n");
		set("value", 15000000);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_get", 1);
		set("no_sell", 1);
		set("group", 1);
	}
	setup();
	set("hp",3000);
	set("max_hp",3000);
}

void init()
{
	add_action("do_drop", ({"drop","fangzhi","����"}));
	add_action("do_check", ({"check", "chazhang", "����"}));
	add_action("do_deposit", ({"deposit", "cun", "��"}));
	add_action("do_withdraw", ({"withdraw", "qu", "ȡ"}));
}

int do_drop(string arg)
{
	object me = this_player() , env = environment(this_object());

	if( !arg || !id(arg) || env!=me ) return 0;
	env = environment(me);
	if( !me->query("group/id") ) {
		tell_object(me,"�㲢û�п������ɣ�ҪǮ����ã�\n");
		return 1;
	}
	if( env && stringp(env->query("outdoors")) ) {
		tell_object(me,"Ǯ���ܷ������⡣\n");
		return 1;
	}
	if( !GROUP_D->site_now(me->query("group/id")) ) {
		tell_object(me,GROUP_D->get_last_error());
		return 1;
	}

	GROUP_D->drop_object(this_object(),me,env,"$N��ʼС�ĵİڷ�Ǯ�񡭡�\n","��æµ�˰��죬�����Ǯ����úá�\n");
	return 1;
}

int do_check(string arg)
{
	object me = this_player() , env = environment(this_object());
	int money;

	if( !env || env==me ) return 0;
	if( !env->query("group1") ) {
		tell_object(me,"��ֻ���ڰ��֮��ʹ�����"+this_object()->name()+"��\n");
		return 1;
	}
	if( me->is_busy() ) {
		tell_object(me,"����æ���ء�\n");
		return 1;
	}

	money = GROUP_D->query_money( env->query("group1") );
	if( money < -50000 ) {
		tell_object(me,"���ݿ��ѯ�����뱨����ʦ��\n");
		return 1;
	}

	tell_object(me,"����"+name()+"֮�У��ܹ�����"HIY"�ƽ�"NOR+CHINESE_D->chinese_number(money)+"����\n");
	if(!wizardp(me)) me->start_busy(2);
	return 1;
}

int do_deposit(string arg)
{
	object me = this_player() , env = environment(this_object());
	object gold;
	string gold_money;
	int money;

	if( !env || env==me ) return 0;
	if( !arg || sscanf(arg,"%d %s",money, gold_money) != 2 || gold_money != "gold")
		return notify_fail("��Ҫ����(deposit <����> gold)���ٻƽ�\n");
	if( !env->query("group1") )
		return notify_fail("��ֻ���ڰ��֮��ʹ�����"+this_object()->name()+"��\n");
	if( me->is_busy() )
		return notify_fail("����æ���ء�\n");
	if( !(gold=present("gold_money",me)) || gold->query_amount()<money )
		return notify_fail("�����Ǯ������\n");
if(money <= 0)   return notify_fail("����������������ԡ�\n");
	if( GROUP_D->add_money(env->query("group1"),money) < -50000 )
		return notify_fail("���ݿ����ʧ�ܣ��뱨����ʦ��\n");
	gold->add_amount(-money);

	message_vision("$N�ó�"+CHINESE_D->chinese_number(money)+"��"HIY"�ƽ�"NOR"������Ǯ��\n", me);
	if(!wizardp(me)) me->start_busy(2);
	return 1;
}

int do_withdraw(string arg)
{
	object me = this_player() , env = environment(this_object());
	object gold;
	string gold_money;
	int money;

	if( !env || env==me ) return 0;
	if( !arg || sscanf(arg,"%d %s",money, gold_money) != 2 || gold_money != "gold")
		return notify_fail("��Ҫȡ��(withdraw <����> gold)���ٻƽ�\n");
	if( !env->query("group1") )
		return notify_fail("��ֻ���ڰ��֮��ʹ�����"+this_object()->name()+"��\n");
	if( me->query("group/id")!=env->query("group1") || me->query("group/class")>2 )
		return notify_fail("��û��Ȩ�������"+name()+"��ȡǮ��\n");
	if( me->is_busy() )
		return notify_fail("����æ���ء�\n");
	if( (GROUP_D->query_money(env->query("group1"))-LIMIT_GOLD) < money )
		return notify_fail("ȥ��"+CHINESE_D->chinese_number(LIMIT_GOLD)+"���ƽ�ı�֤��֮��"+name()+"��Ļƽ𲻹���ȡ�ġ�\n");
if(money <= 0)   return notify_fail("����������������ԡ�\n");
	if( GROUP_D->add_money(env->query("group1"),-money) < -50000 )
		return notify_fail("���ݿ����ʧ�ܣ���֪ͨ��ʦ��\n");
	gold = new("/clone/money/gold");
	gold->set_amount(money);
	gold->move(me);

	message_vision("$N��"+name()+"���ó�"+CHINESE_D->chinese_number(money)+"��"HIY"�ƽ�"NOR"��\n", me);
	if(!wizardp(me)) me->start_busy(2);
	return 1;
}

void broken()
{
	object room = environment(this_object()) , gold;
	int money;
	string groupid;

	if( !room ) return;
	if( sscanf(base_name(room),"/d/group/%s/",groupid) < 1 ) return;
	if( (money=GROUP_D->query_money(groupid)) <= 0 ) return;
	if( money > LIMIT_GOLD ) money = LIMIT_GOLD;

	if( GROUP_D->add_money(groupid,-money) < -10000 ) return;
	tell_room(room,name()+"�������ˣ������ܶ��Ԫ����\n");
	gold = new("/clone/money/gold");
	gold->set_amount(money);
	gold->move(room);
}

varargs int move(mixed dest, int silently)
{
	int result;
	if( !(result = ::move(dest,silently)) ) return result;
	if( !objectp(dest) || clonep(dest) ) return result;
	if( !dest->query("group2") ) return result;

	set("name",YEL+dest->query("group2")+HIY"��Ǯ��"NOR);
	return result;
}

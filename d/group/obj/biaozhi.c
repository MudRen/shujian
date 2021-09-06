// biaozhi.c
// by augx@sj  3/13/2002

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY"����"NOR, ({ "pai bian","bian" }));
	set_weight(15000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", HIY"����һ��հ׵����ҡ�\n"NOR);
		set("value", 25000000);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_get", 1);
		set("no_sell", 1);
		set("group", 1);
	}
	setup();
	set("hp",10000);
	set("max_hp",10000);
}

void init()
{
	add_action("do_drop","drop");
}

int do_drop(string arg)
{
	object me = this_player() , env = environment(this_object());

	if( !arg || !id(arg) || env!=me ) return 0;
	env = environment(me);
	if( !me->query("group/id") ) {
		tell_object(me,"�㲢û�п������ɣ�Ҫ���Һ��ã�\n");
		return 1;
	}
	if( env && stringp(env->query("outdoors")) ) {
		tell_object(me,"���Ҳ��ܷ������⣡\n");
		return 1;
	}
	if( !GROUP_D->site_now(me->query("group/id")) ) {
		tell_object(me,GROUP_D->get_last_error());
		return 1;
	}

	GROUP_D->drop_object(this_object(),me,env,"$N��ʼС�ĵİ������ҡ���\n","��æµ�˰��죬��������Ұ��á�\n");
	return 1;
}

varargs int move(mixed dest, int silently)
{
	int result;
	if( !(result = ::move(dest,silently)) ) return result;
	if( !objectp(dest) || clonep(dest) ) return result;
	if( !dest->query("group2") ) return result;

	set("name",HIY+dest->query("group2")+HIY"������"NOR);
	set("long",HIY"����һ�������������ң����顰"+dest->query("group2")+HIY"���������֡�\n������Ҿ��ǰ��ɵı�־���������ڰ��ڣ��һٰ�����\n"NOR);
	return result;
}

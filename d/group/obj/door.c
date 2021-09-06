// door.c
// by augx@sj  3/27/2002

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"ʯ��"NOR, ({ "shi men","men","door" }));
	set_weight(30000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", HIW"����һ����̵�ʯ�š�\n������ż���׭ͷ���֡������صأ���������!����\n"NOR);
		set("value", 10000000);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_get", 1);
		set("no_sell", 1);
		set("group", 1);
	}
	set("open",0);
	set("attack",0);
	set("hp",2000);
	set("max_hp",2000);
	setup();
}

void init()
{
	add_action("do_drop","drop");
}

int do_drop(string arg)
{
	object me = this_player() , env = environment(this_object());
	string * sv;
	int i;

	if( !arg || !id(arg) || env!=me ) return 0;
	env = environment(me);
	if( !me->query("group/id") ) {
		tell_object(me,"�㲢û�п������ɣ�Ҫ"+name()+"���ã�\n");
		return 1;
	}
	if( !env ) {
		tell_object(me,name()+"���ܷ������\n");
		return 1;
	}

	if( mapp( env->query("exits") ) ) {
		sv = values( env->query("exits") );
		for(i=0;i<sizeof(sv);i++)
			if( strlen(sv[i])>14 && sv[i][0..14]=="/d/group/entry/" )
				break;
		if( i >= sizeof(sv) ) {
			tell_object(me,name()+"ֻ�ܷ��ڰ�����������ĵط���\n");
			return 1;
		}
	}

	if( present(query("id"),env) ) {
		tell_object(me,"���ﲻ���Ѿ�����һ"+query("unit")+name()+"����\n");
		return 1;
	}

	if( !GROUP_D->site_now(me->query("group/id")) ) {
		tell_object(me,GROUP_D->get_last_error());
		return 1;
	}

	GROUP_D->drop_object(this_object(),me,env,"$N��ʼ����"+name()+"����\n","��æµ�˰��죬�����"+name()+"������ˡ�\n");
	return 1;
}

void do_name()
{
	set("name",HIW+(query("open")?"����":"�ر�")+HIW"��ʯ��"NOR);
}

varargs int move(mixed dest, int silently)
{
	int result;
	if( !(result = ::move(dest,silently)) ) return result;
	if( !objectp(dest) || clonep(dest) ) return result;
	if( !dest->query("group2") ) return result;

	do_name();
	return result;
}

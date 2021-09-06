// gf_wenshu.c
// By snowman@SJ 11/06/2000

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(WHT "��������" NOR, ({ "tiebu wenshu", "wenshu" }));
	set("weight", 100);
	if(clonep()) set_default_object(__FILE__);
	else{
		set("unit", "��");
		set("no_give", 1);
		set("no_get", 1);
		set("long", WHT"����һ��Ѳ���������������飬������ͨ�����Ļ�������֡�\n" NOR);
	}
	setup();
}
 
void init()
{
	add_action("do_arrest", "jubu");
}

int do_arrest(string arg)
{
	object ob, me;
	
	if (!arg)
		return notify_fail("����в�˭��\n");
	
	me = this_player();
		
	if( !environment(me)->query("no_fight"))
		return notify_fail("ֻ�����ﷸ�������ʱ���в�����Ч��\n");

	if(!objectp(ob = present(arg, environment(me))) )
		return notify_fail("��Ҫ�в�˭��\n");
		
	if(!ob->is_character() )
		return notify_fail("��Ҫ�в�ʲô��\n");
		
	if( ob->query("id") != query("target/id") )
		return notify_fail("���������ϼǵĲ������˰ɣ�\n");
		
	message_vision("\n$N����$n���һ���������Ҵ����ˣ�������־��ܰɣ���\n", me, ob);
	me->kill_ob(ob);
	ob->fight_ob(me);
	
	return 1;
}

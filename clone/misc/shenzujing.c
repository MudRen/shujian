#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("���ľ���", ({ "fanwen book", "jingshu", "fanwen", "book" }));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "ÿһҳ�϶�д�����������������֣�ûһ��ʶ�á�\n");
                set("value", 500);
                set("material", "steel");
                set("no_give",1);
                set("no_get",1);
                set("no_drop",1);
                set("no_cun",1);

        }
}

void init()
{
	if (environment() == this_player())
		add_action("do_du", "read");
}

int do_du(string arg)
{
	object me = this_player();

	if (!id(arg)) 
		return notify_fail("��Ҫ��ʲô��\n");

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");

	
	if ( query("owner") != me->query("id") )
		return notify_fail("������ô�õ������㾭���İ���\n");

	if ( me->query("neili") < 1500 )
		return notify_fail("�������������\n");

	if (environment(me)->query("pigging"))
		return notify_fail("�㻹��ר�Ĺ���ɣ�\n");

	if (environment(me)->query("pending"))
		return notify_fail("�˵ز�����ϰ�����㾭����\n");

	if (environment(me)->query("sleep_room"))
		return notify_fail("���Ҳ�����������Ӱ�������Ϣ��\n");
 
	if (environment(me)->query("no_fight"))
		return notify_fail("�˵ز�����ϰ�����㾭����\n");

	if ( me->query("jing") < 40 )
		return notify_fail("��ľ�̫���ˣ������ж������㾭����\n");

if((int)me->query("potential") < 1 )
return notify_fail("���Ǳ���Ѿ������ˣ�����ô��Ҳû�á�\n");



	

	tell_object(me, "����ϸ�ж��š����㾭���ľ���֮����\n");
	me->receive_damage("jing", 30 );
	me->add("neili", - 50);
         me->add("potential", - random(3));

	me->improve_skill("yijin-jing", me->query_int());
	if (!random(8))
		message("vision", me->name() + "��ϸ�ж��š����㾭���ľ���֮����\n", environment(me), me); 
	return 1;
}

// ningxue.c ��Ѫ��צ��
// By River@SJ 2003.1.11

inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIR"��Ѫ��צ��"NOR, ({ "ningxue shenzhuapu", "pu", "book"}));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�������ػ��ܶ����½��ϵľ�����Ѫ��צ��ͼ�ס�\n");
		set("value", 5000);
		set("no_give", 1);
		set("treasure",1);
		set("material", "paper");
		set("no_get", "�������������뿪�Ƕ���\n");
	}
	setup();
}

void init()
{
	if (environment() == this_player())
		add_action("do_du", "read");
}

int do_du(string arg)
{
	object me = this_player();
       int lv;
	if (!id(arg)) 
		return notify_fail("��Ҫ��ʲô��\n");

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");

	if ( !me->query("quest/ningxue/pass") )
		return notify_fail("������ô�õ�����Ѫ��צ�ס��İ���\n");

	if ( query("owner") != me )
		return notify_fail("������ô�õ�����Ѫ��צ�ס��İ���\n");

	if ( me->query("neili") < 1500 )
		return notify_fail("�������������\n");

	if (environment(me)->query("pigging"))
		return notify_fail("�㻹��ר�Ĺ���ɣ�\n");

	if (environment(me)->query("pending"))
		return notify_fail("�˵ز�����ϰ����Ѫ��צ�ס���\n");

	if (environment(me)->query("sleep_room"))
		return notify_fail("���Ҳ�����������Ӱ�������Ϣ��\n");
 
	if (environment(me)->query("no_fight"))
		return notify_fail("�˵ز�����ϰ����Ѫ��צ�ס���\n");

	if ( me->query("jing") < 40 )
		return notify_fail("��ľ�̫���ˣ������ж����������䡹��\n");

	if ( me->query_skill("ningxue-shenzhua", 1) > 150 )
		return notify_fail("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");
	if ( me->query_skill("ningxue-shenzhua", 1) > 149 ){
	tell_object(me, "����ϸ�ж��š���Ѫ��צ�ס��ľ���֮����\n");
        //�츳�������ʦ��Ӱ��Ч����  by spiderii@ty ..lsxk�뷨̫����̬��
        lv = me->query("max_pot")-100;
        if(me->query("relife/quest/lwds")){
         if(random(100) > me->query("relife/quest/lwds")*10)
            write(HIC"�㾭��ת�����޺��������似��䲻�����ڵĵ���˲����������Ѫ��צ�ľ������ڡ�\n"NOR);
            me->set_skill("ningxue-shenzhua",lv);
            }

      }
	tell_object(me, "����ϸ�ж��š���Ѫ��צ�ס��ľ���֮����\n");
	me->receive_damage("jing", 30 );
	me->add("neili", - 50);
	me->improve_skill("ningxue-shenzhua", me->query_int());
	if (!random(8))
		message("vision", me->name() + "��ϸ�ж��š���Ѫ��צ�ס��ľ���֮����\n", environment(me), me); 
	return 1;
}

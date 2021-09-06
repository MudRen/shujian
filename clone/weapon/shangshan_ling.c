// sf_ling.c
// Created by snowman@SJ 08/05/2001

#include <weapon.h>
#include <ansi.h>

inherit DAGGER;
inherit F_UNIQUE;
void create()
{
        set_name(WHT"������"NOR,({ "shangshan ling", "shangshan", "ling", "dagger" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("treasure", 1);
                set("unit", "��");
                set("value", 500000);
                set("unique", 1);
                set("rigidity", 2);
                set("weapon_prop/dodge", 1);
                set("weapon_prop/parry", 1);   
                set("dagger_count", 1);     
                set("material", "bonze");
                set("wield_neili", 30);
                set("wield_maxneili", 500);
                set("wield_str", 15);
                set("wield_msg", WHT"$N����һ��������̲�ס��Ц�˼�����\n"NOR);
                set("long", WHT"\nһ����������İ�ͭ���ӣ�Լ�а��ƴ�С���̵���һ��Ц�����Ͱ����飡
������������ѣ�Ӧ���ܺϲ�(hebing)������\n"NOR);
                set("unwield_msg", WHT"$N"WHT"��$n"WHT"�ջص��ڴ��\n" NOR);               
        }
        init_dagger(60);
        setup();
}

void init()
{
    	add_action("do_add", "�ϲ�");
    	add_action("do_add", "hebing");
}

int do_add()
{
     	object me,ob, obj, ling;
     	me = this_player();
     	ob = this_object();
     	obj = present("fae ling", me);
     	
     	if(!objectp(obj))
           	return notify_fail("������ֻ��һֻ��������ҵ���һֻ��˵�ɡ�\n");
     	if((int)me->query("neili") < 200)
		return notify_fail("��о�ȫ����Ѫ���ڣ�ԭ���������������޷���˫��ϲ���\n");
     	if((int)me->query_str() < 25)
		return notify_fail("��о�ȫ����Ѫ���ڣ�ԭ���������������޷���˫��ϲ���\n");
     	me->add("neili", -150);
     	message_vision(HIW"\nֻ��$N�����������������໥Ħ����һ˲�侹Ȼ����һ�����磬����������һ��\n"NOR, me);
     	destruct(obj);   
     	ling = new(BINGQI_D("sf_ling"))->move(me, 1);     
     	destruct(ob);
     	return 1;
}

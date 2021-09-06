// sf_ling.c
// Created by snowman@SJ 08/05/2001

#include <weapon.h>
#include <ansi.h>

inherit DAGGER;
inherit F_UNIQUE;
void create()
{
        set_name(WHT"���Ʒ�����"NOR,({ "shangshanfae ling", "shangshanfae", "ling", "dagger" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("treasure", 1);
                set("unit", "��");
                set("value", 1000000);
                set("unique", 1);
                set("rigidity", 3);
                set("weapon_prop/dodge", 3);
                set("weapon_prop/parry", 2);   
                set("dagger_count", 2);     
                set("material", "bonze");
                set("wield_neili", 100);
                set("wield_maxneili", 1000);
                set("wield_str", 20);
                set("wield_msg", WHT"��������һ����$N"WHT"����$n"WHT"�໥һ���������̶���������\n"NOR);
                set("long", WHT"\n������������İ�ͭ���ӣ�Լ�а��ƴ�С��һ�����Ͽ���һ��Ц�����Ͱ����飬��һ���Ͽ̵�ȴ��һ��������ɷ���������Ե�ʮ�ֹ��죡
������������� �ֿ� �Ƶġ�\n"NOR);
                set("unwield_msg", WHT"$N"WHT"��$n"WHT"�ջص��ڴ��\n" NOR);               
        }
        init_dagger(120);
        setup();
}

void init()
{
	if (environment()==this_player())
		add_action("do_sub",({"fen", "�ֿ�"}));
}

int do_sub()
{
     	object me, obj;
     	me = this_player();
     	obj = this_object();
     	if((int)me->query("neili") < 200)
		return notify_fail("��о�ȫ����Ѫ���ڣ�ԭ���������������ֲ������Ʒ����\n");
     	if((int)me->query_str() < 25)
		return notify_fail("��о�ȫ����Ѫ���ڣ�ԭ���������������ֲ������Ʒ����\n");

     	message_vision(HIW"\n$N�����Ʒ������໥һ�죬��һ����һ��Ϊ��������ҫ�۵İ׹⣡\n"NOR, me);
     	me->add("neili", -150);
     	new(BINGQI_D("shangshan_ling"))->move(me, 1);
     	new(BINGQI_D("fae_ling"))->move(me, 1);  
     	destruct(obj); 
     	return 1;

}


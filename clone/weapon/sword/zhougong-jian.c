// zhougjian.c �ܹ���

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name(HIC"�ܹ���"NOR,({ "zhougong jian", "zhougong", "sword", "jian" }) );
        set_weight(15000);
        if( clonep())
		set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1);
                set("rigidity", 4);
                set("sharpness", 5);
                set("unique", 1);
                set("no_get", 1);
                set("material", "steel");
                set("weapon_prop/dodge", -5);
                set("weapon_prop/parry", 5);
                set("treasure",1);
                set("wield_neili", 300);
                set("wield_maxneili", 700);
                set("wield_str", 22);
                set("wield_msg", HIG"$N����һͦ��������ͻȻ����������²�������â��\n"NOR);
                set("long", "����һ��һ�ֻ۽�������������׿�������彣��\n");                
                set("unwield_msg", HIY "�ܹ�������һ���׹⣬��ৡ��ط��뽣�ʡ�\n" NOR);                  
        }
        init_sword(70);
        setup();
}

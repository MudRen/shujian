// zisong-bian.c ���ɱ�
// Created by Numa@Sj 1999-11-23

#include <weapon.h>
#include <ansi.h>

inherit WHIP;
inherit F_UNIQUE;

void create()
{
        set_name(MAG"���ɱ�"NOR,({ "zisong bian", "whip","bian" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1);
                set("unique", 1);
                set("rigidity", 5);
                set("material", "bamboo");
                set("weapon_prop/parry", 5);
                set("treasure",1);
                set("wield_neili", 700);
                set("wield_maxneili", 1200);
                set("wield_str", 23);
                set("long", "����һ������ɽ�ز����������ɵı��ӣ���ӯС�ɣ����������������\n");
                set("unwield_msg", "$Nһ����������$n�̻����䡣\n");
                set("wield_msg", "$N������С������ĳ��һ��$n�������С�\n");
        }
        init_whip(45);
        setup();
}

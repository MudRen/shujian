// yinsuo.c ������ 
#include <weapon.h>
#include <ansi.h>

inherit WHIP;
inherit F_UNIQUE;

void create()
{
        set_name("������",({ "jinling suo", "whip", "bian", "suo" }) );
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1);
                set("unique", 1);
                set("rigidity", 6);
                set("material", "softsteel");
                set("weapon_prop/parry", 4);
                set("treasure", 1);
                set("wield_neili", 800);
                set("wield_maxneili", 1300);
                set("wield_str", 23);
                set("long", "һ����ɫ�����ĩ�˻�ϵ��һ����ɫ��Բ��\n");                
                set("unwield_msg", HIY"$N����һ���������������뻳�С�\n"NOR);
                set("wield_msg", HIY"$N�����ӻ���ȡ��һ�ű�篰��������������֮�ϡ�\n"NOR);
        }
        init_whip(75);
        setup();
}

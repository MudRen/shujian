#include <weapon.h>
#include <ansi.h>

inherit WHIP;
inherit F_UNIQUE;

void create()
{
        set_name("����",({ "hei suo", "whip","bian","suo" }) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1);
                set("unique", 3);
                set("rigidity", 7);
                set("material", "steel");
                set("weapon_prop/parry", 4);
                set("treasure",1);
                set("wield_neili", 900);
                set("wield_maxneili", 1400);
                set("wield_str", 24);
                set("long", "������ͨ������޹�ĳ���������һ��������צ��ī����ҹ���趯֮ʱ�Ʋ������Ӱ�ӡ�\n");                
                set("unwield_msg", "$N����һ������$n�̻����䡣\n");
                set("wield_msg", "$N����һ�������һ��$n�������С�\n");
        }
        init_whip(120);
        setup();
}

//gangfu.c �ָ�
#include <weapon.h>
#include <ansi.h>

inherit AXE;
inherit F_UNIQUE;

void create()
{
        set_name("�ָ�",({ "gang fu", "fu", "axe"}) );
        set_weight(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 2000);
                set("material", "steel");
                set("weapon_prop/dodge", -5);
                set("wield_msg", "$N৵�һ�������г��һ�Ѹָ���\n");
                set("long", "����һ����ͨͨ�ĸָ���\n");                
                set("unwield_msg", "$N�Ѹָ����������С�\n");                
        }
        init_axe(30);
        setup();
}

// youlong.c

#include <weapon.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name("������", ({ "youlong sword", "youlong", "sword" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("unique", 1);
                set("rigidity", 1);
                set("sharpness", 1);
                set("long",
"���ǰѿ���������ͨ�ĳ���������ϸһ�����������м���ϸ����˸������\n");
                set("value", 10000);
                set("material", "blacksteel");
                set("wield_msg", 
"ֻ������쬡���һ����$N�������Ѿ�����һ�Ѻ�������ı�������$n��\n");
                set("treasure", 1);
                set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");
        }
        init_sword(40);
        setup();
}

// ITEM: /d/huashan/obj/shengzi.c
// Date: Look 99/03/25

#include <ansi.h>
#include <weapon.h>
inherit WHIP;

void create()
{
        set_name(MAG"����"NOR, ({ "song sheng", "sheng" }));
        set_weight(400);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ������֦��ɵĳ��������������ʺ�������֮�á�\n");
                set("value", 40);
                set("material", "leather");
                set("wield_msg", "$N��ৡ���һ����������һ��$n����һ���������С�\n");
                set("unwield_msg", "$N�����е�$n�̺ñ������\n");
        }
        init_whip(5);
        setup();
}

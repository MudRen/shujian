// /d/putian/npc/obj/fb-chan.c
// Lklv 2001.9.12

#include <weapon.h>
inherit STAFF;

void create()
{
        set_name("�����", ({ "fangbian chan", "zhang", "chan" }));
        set_weight(5500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��������ķ������Լ��ʮ���ɮ���ǳ��õı�����\n");
                set("value", 200);
                set("material", "steel");
                set("wield_msg", "$N�ó�һ��������$n�������С�\n");
                set("unwield_msg", "$N�ֱ�һת�������е�$n����������\n");
                set("shaolin",1);
        }
        init_staff(35);
        setup();
}

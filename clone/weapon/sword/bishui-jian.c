// ITEM: /d/huashan/npc/obj/bishuijian.c
// Date: Look 99/03/25

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name( GRN "��ˮ��" NOR, ({ "bishui jian", "jian", "sword" }));
        set_weight(12000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", GRN "���Ǳ��ֱ����������������������͸���̹⣬��������ޱȡ�\n" NOR);
                set("value", 1500);
                set("rigidity", 3);
                set("sharpness", 3);
                set("weapon_prop/parry", 2);
                set("material", "steel");
                set("unique", 1);
                set("treasure",1);
                set("wield_neili", 500);
                set("wield_maxneili", 900);
                set("wield_str", 22);
                set("wield_msg", GRN "ֻ�����ˡ���һ�����̹���֣�$N���������$n"+ GRN "����ˢ����һ�����ñ�ֱ��\n" NOR);
                set("unwield_msg", GRN "ֻ���̹�һ���������ǰһ����$N�����е�$n"+ GRN "�������䡣\n" NOR);
        }
        init_sword(52);
        setup();
}

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name(CYN"��������"NOR, ({ "dongling tiejian", "tiejian", "jian", "sword" }));
        set_weight(16000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ��������������̽��������Ͽ���һ��׭�ġ�����������������顿��\n");
                set("value", 1500);
                set("unique", 1);
                set("sharpness", 3);
                set("rigidity", 3);
                set("treasure", 1);
                set("weapon_prop/parry", 2);
                set("wield_neili", 500);
                set("wield_maxneili", 900);
                set("wield_str", 22);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
        }
        init_sword(42);
        setup();
}

// yuxiao.c ����

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name(HIG"����"NOR, ({ "yu xiao", "xiao" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����ͨ����̣������ϺõĴ��񣬽����ڴ��м�����ߣ������Ѫ����ӳ������������Ρ�\n");
                set("value", 2500);
                set("no_sell", 1);
                set("material", "steel");
                set("wield_msg", "$N��������һ��$n�������С�\n");
                set("unwield_msg", "$N����һת�������е�$n����������\n");
        }
        init_sword(35);
        setup();
}

// hongying-qiang.c ��ӧǹ

#include <ansi.h>
#include <weapon.h>
inherit SPEAR;

void create()
{
        set_name(RED"��ӧ������ǹ"NOR , ({ "hongying qiang", "qiang", "spear","hongying" }));
        set_weight(12000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "��ǹ�ɰ������Ƴ�,���������࣬ͨ�������񡢼����Ӳ��������ۡ�ǹͷ�ɾ��ִ��ƣ�������ƥ��\n");
                set("value", 1000);
		set("no_sell", 1);
                set("material", "steel");
                set("wield_msg", "$N����һ������$n��ֻ��ǹ��ͻ�����磬�ڿ��е���߶��滨��\n");
                set("unwield_msg", "$N������$һ�������ڼ��ϡ�\n");
        }
        init_spear(30);
        setup();
}
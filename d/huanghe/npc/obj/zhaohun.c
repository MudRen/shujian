// zhaohun.c �л���

#include <weapon.h>
#include <ansi.h>
inherit WHIP;

void create()
{
        set_name(BLU"�л��"NOR, ({ "zhaohun fan", "fan","whip" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�˲��������ϵ��л�ᦡ�\n");
                set("value", 3000);
                set("rigidity", 5);
                set("material", "steel");
                set("wield_msg", BLU"$N���һ���л���������У�ģ�������ޱȣ�������Ϊ֮�ᡣ\n"NOR);
                set("unwield_msg", "$N�����е�$n�������\n");
        }
        init_whip(38);
        setup();
}


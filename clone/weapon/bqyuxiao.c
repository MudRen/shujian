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
                set("unit", "ֻ");
                set("long", "����һֻ���ϺõĴ�����ĥ�ƶ��ɵ����ͨ����̣������ڴ��м�����ߣ������Ѫ��\n");
                set("value", 42000);
                set("no_sell", 1);
                set("material", "steel");
                set("wield_msg", "$N��������һ�У�һ֧$n�ѳ�����$N���С�\n");
                set("unwield_msg", "$Nһ����Х�������е�$n������䡣\n");
        }
        init_sword(80);
        setup();
}

// ̴����

#include <weapon.h>
#include <ansi.h>

inherit SWORD;


void create()
{
        set_name(GRN "̴����" NOR, ({ "tanxiang shan", "shan" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�ѳ�����̴��ľ���ȡ�\n");
                set("value", 1000);
                set("material", "steel");
                set("wield_msg", GRN "$Nչ�����ӣ�����������ȡ�\n" NOR);
                set("unwield_msg", GRN "$Nˢ��һ���������ӣ��Ż����С�\n" NOR);
        }
        init_sword(40);
        setup();
}


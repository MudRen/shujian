// yaoqin.c ����

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(YEL"����"NOR,({"yao qin","qin"}));
        set_weight(1000);
        if(clonep())
                set_default_object(__FILE__);
        else{
                set("unit","��");
                set("value",1000);
                set("material","steel");
                set("unique", 1);
                set("rigidity", 5);
                set("treasure",1);
                set("long","����������ɫ���ɣ�����������������ǧ�����ϵĹ��\n");
                set("wield_msg",YEL"$N����һ����������������,�������ϲ��˼��¡�\n"NOR);
                set("unwield_msg",YEL"$N����һת������ͣ��������\n"NOR);
        }
        init_sword(42);
        setup();
}

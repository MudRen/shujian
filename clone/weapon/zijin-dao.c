// zijin-dao.c �Ͻ�

#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
        set_name( HIM"�Ͻ�"NOR , ({ "zijin dao", "dao","blade" }));
        set_weight(17500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIM"���ǰ���ɫ�ı�����ֻ���ڹ�������˲��ܷ�����ȫ����������\n"NOR);
                set("value", 10000);
                set("unique", 1);
                set("rigidity", 3);
                set("weapon_prop/parry", 2);
                set("wield_neili", 500);
                set("wield_maxneili", 900);
                set("wield_str", 22);
                set("treasure",1);
                set("material", "steel");
        }
        init_blade(40);
        setup();
}

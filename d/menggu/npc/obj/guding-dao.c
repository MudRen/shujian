// gunding-dao.c

#include <weapon.h>
#include <ansi.h>
#include <weapon.h>
inherit BLADE;
inherit F_UNIQUE;

void create()
{
        set_name(HIY"�Ŷ���"NOR, ({"guding dao", "dao", "blade", }) );	
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIY"һ���⼣�߲��ĳ�������˵�������ᵱ�����õ�ս���������൱�ĳ��ء�\n"NOR);
                set("value", 1);
                set("unique", 1);
                set("rigidity", 5);
                set("sharpness", 10);
                set("weapon_prop/parry", 1);
                set("wield_maxneili", 2000);
                set("treasure",1);
                set("wield_str", 35);
                set("material", "steel");
                set("wield_msg", HIY"$N��������������ʣ���ʱ���籩�����������ת�������Ѷ���һ��Ӣ�����˵ļ⵶��\n"NOR);
                set("unwield_msg",HIY"$N���Ŷ���С�Ĳ�ص��ʣ���ʱӢ���������š�\n"NOR);
        }
        init_blade(180);
        setup();
}

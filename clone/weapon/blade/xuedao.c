// xuedao.c Ѫ��
#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
        set_name( HIR"Ѫ��"NOR , ({ "xue dao", "xuedao","blade","dao"}));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIR"����嵶���Ἣ�����з���ȫ�ǰ���֮ɫ��Ѫ�����������ǿɲ���\n"NOR);
                set("value", 1000);
                set("unique", 1);
                set("rigidity", 4);
                set("sharpness", 4);
                set("weapon_prop/parry", 4);
                set("wield_neili", 900);
                set("wield_maxneili", 1400);
                set("wield_str", 24);
                set("treasure",1);
                set("material", "steel");
                set("wield_msg", HIR"$N�������䣬һ��֮�£������Ѷ���һ��������嵶������ס��������Ȼһ�������һ�㡣\n"NOR);
                set("unwield_msg",HIR" $N�����������Ѫ����С�ĵĲ��������䡣\n"NOR);
        }
        init_blade(75);
        setup();
}

// hua3.c

#include <ansi.h>;
#include <armor.h>;
inherit HEAD;

void create()
{
	set_name(HIB"ޥ����"NOR, ({"huilan hua", "flower", "hua"}));
	set_weight(110);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��������ޥ�������������¡�\n");
                set("value", 0);
                set("material", "plant");
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 1);
                set("wear_msg", "$N����ذ�һ��$n����ͷ�ϡ�\n");
                set("unequip_msg", "$N����ذ�$n��ͷ��ժ��������\n");
        }
        setup();
}

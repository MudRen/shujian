// suoluohua.c

#include <ansi.h>;
#include <armor.h>;
inherit HEAD;

void create()
{
	set_name(HIR"ɯ须�"NOR, ({"shaluo hua" "flower", "hua"}));
        set_weight(140);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��������ɯ须����������¡�\n");
                set("value", 230);
                set("material", "plant");
                set("armor_prop/armor", 1);
                set("armor_prop/personality", 1);
                set("wear_msg", "$N����ذ�һ��$n����ͷ�ϡ�\n");
                set("unequip_msg", "$N����ذ�$n��ͷ��ժ��������\n");
        }
        setup();
}

// baihehua.c
// creat by Lklv@SJ for ��λ��Ů @@

#include <ansi.h>;
#include <armor.h>;
inherit HEAD;

void create()
{
	set_name(HIW"�ٺϻ�"NOR, ({"baihe hua", "hua", "flower" }));
	set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�������İٺϻ����������¡�\n");
                set("value", 110);
                set("material", "plant");
                set("armor_prop/armor", 1);
                set("armor_prop/personality", 1);
                set("wear_msg", "$N����ذ�һ��$n����ͷ�ϡ�\n");
                set("unequip_msg", "$N����ذ�$n��ͷ��ժ��������\n");
        }
        setup();
}

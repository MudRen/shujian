#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(YEL"ϸ˿ľ������"NOR, ({ "jia sha", "cloth","jiasha" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ����ɫ��ľ�����ġ�\n");
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 20);
                set("wear_msg","$N����һ��$n��\n");
                set("remove_msg","$N��$n����������������\n");
                set("tianlongsi",1);
        }
        setup();
}

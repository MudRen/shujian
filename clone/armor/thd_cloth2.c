#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(WHT "��ɫ����" NOR, ({ "chang shan", "cloth","changshan","shan"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ����ɫ�ĳ����������޲����ö��ɣ������ǳ��á�\n");
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 15);
                set("value", 100);
                set("wear_msg","$N��$n�������������ϡ�\n");
                set("remove_msg","$N��$n����������������\n");
        }
        setup();
}

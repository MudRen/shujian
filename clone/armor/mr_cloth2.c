#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIB "��ɫ��ɼ" NOR, ({ "chang shan", "cloth","changshan","shan"}));
        set_weight(3500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ�����úܺõİ�ɫ�޲��������������ǳ�������\n");
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 25);
                set("value", 100);
                set("wear_msg","$N�����İ�$n�������ϡ�\n");
                set("remove_msg","$N�İ�$n����������������\n");
        }
        setup();
}

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIW"�ױ�"HIC"��ɫ����" NOR, ({ "chang pao", "cloth","changpao","pao"}));
         set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ����ɫ����������ϸ����ɫ���ۣ�����������ʲô���ϲóɵġ�\n");
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 30);
                set("wear_msg","$N��$nӭ��һչ���������������ϡ�\n");
                set("remove_msg","$N����İ�$n����������������\n");
        }
        setup();
}

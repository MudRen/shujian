#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIW"�ױ�"HIY"��ɫ����" NOR, ({ "chang pao", "cloth","changpao","pao"}));
         set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ����ɫ���߻�ɫ���ۣ������ƺ��Ƚϼ򵥡�\n");
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 10);
                set("wear_msg","$N��$nӭ��һչ���������������ϡ�\n");
                set("remove_msg","$N����İ�$n����������������\n");
        }
        setup();
}

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIB "��ɫ����" NOR, ({ "duan pao", "cloth","duanpao","pao"}));
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ��������ϸ����ɫ���ۣ��ƺ���������Ľ��ϳ�м��ö��ɡ�\n");
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 35);
                set("value", 100);
                set("wear_msg","$N��$n����һ�ӣ��������������ϡ�\n");
                set("remove_msg","$N����İ�$n����������������\n");
        }
        setup();
}

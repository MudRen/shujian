#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(WHT"�ڱ�"HIW"��ɫ����" NOR, ({ "chang pao", "cloth","changpao","pao"}));
	set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ����ɫ���ߵİ�ɫ���ۣ������쳣����������ʲô�������ġ�\n");
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 40);
                set("wear_msg","$Nӭ��һչ����ৡ���һ��������һ��$n��\n");
                set("remove_msg","$N�⿪$n����$n����������������\n");
	}
        setup();
}

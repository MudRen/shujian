// yanling.c ����
// by iceland

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name( WHT "����" NOR, ({ "yan ling", "yanling","ling" }) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�������Ĵ�����ë���������ƺ�����ԭ��̫��������ԱȽ����\n");
                set("value", 500);
                set("material", "cloth");
                set("armor_prop/armor", 0);
                set("wear_msg", "$N�������������룬̧�ּ����˶����ϡ�\n");
             }
        setup();
}

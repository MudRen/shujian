// caoxie.c ��Ь
// build by Lklv@SJ 2001.9.28

#include <armor.h>
inherit BOOTS;

void create()
{
        set_name("��Ь", ({ "cao xie", "caoxie", "xie", "shoes" }) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "˫");
                set("material", "boots");
                set("value", 0);
                set("long", "����һ˫��ͨ�Ĳ�Ь�����ڽ��Ϻ������\n");
                set("armor_prop/dodge", 2);
        }
        setup();
}

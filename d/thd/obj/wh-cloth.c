// wh-cloth.c thd �Ĵ�Ů���Ӵ�

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(WHT"ǳ�ҳ���"NOR, ({ "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","����һ��ǳ��ɫ�ĳ�����\n");
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 10);
        }
        setup();
}


// OBJ : /d/wudang/obj/daolv.c ����
// By lius 99/8

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
        set_name( WHT"����"NOR, ({ "dao lv", "lv" }) );
        set_weight(1000);
        if( clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "˫");
                set("long", "һ˫�ײ��ڵ׵ĵ��ģ��䵱��ҩ���˿�����ɽԾ������ƽ�ء�");
                set("value", 3000);
                set("material", "boots");
                set("armor_prop/dodge", 2);
                set("wudang",1);
        }
        setup();
}

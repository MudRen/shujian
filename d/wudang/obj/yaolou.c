#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("ҩ¨", ({ "yao lou", "lou" }) );
        set_max_encumbrance(3000);
        set_weight(1000); 
        if( clonep() )
                set_default_object(__FILE__);
        else{
        set("long", "����һ�������ӱ�ɵ�ҩ¨��һ���ҩ�˶�����Я��һ��\n"
"�������һ����ǡ�\n"
);
        set("unit", "��");
        set("material","bamboo");
        set("no_get", 1);
        }
        setup();
}

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("����Ͳ", ({ "zhu tong", "tong" }) );
        set_max_encumbrance(300000);
        set_weight(1000); 
        if( clonep() )
                set_default_object(__FILE__);
        else{
        set("long", "����һ���������������ɵ���Ͳ����˵ֻ���嶾�̲��С�\n"
"�������һ����ǡ�\n"
);
        set("unit", "��");
        set("material","bamboo");
        set("no_get", 1);
        }
        setup();
}

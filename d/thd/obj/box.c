inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIW"������"NOR, ({ "array box","box"}));
        set_weight(100000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ���һ���������������Ĳ����䡣\n");
                set("value", 10);
                set("unique", 1);
                set("material", "steel");
         }
        setup();
}

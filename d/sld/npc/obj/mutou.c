
#include <ansi.h>

inherit ITEM;

 void create()
{
        set_name(YEL "��ľͷ" NOR, ({"mu tou", "mu"}));
        set_weight(200000);
        set("no_get",1);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "һЩ");
                set("long", "���Ǽ�����ľͷ��Ҳ��֪�������á�\n");
        }

        setup();
}

// stone.c
// By River 98.10
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("ʯ��", ({"shi kuai", "shi", "stone"}));
        set_weight(5000);
        if (clonep())
               set_default_object(__FILE__);
        else {
               set("long", "����һ������ͨͨ��ʯͷ��\n");
               set("unit", "��");
        }
        setup();
}

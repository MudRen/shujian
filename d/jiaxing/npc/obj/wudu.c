// wudu.c �嶾�ش�

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR"�嶾�ش�"NOR, ({ "wudu mizhuan", "mizhuan", "book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ��������㶾ҩ�ͽ�ҩ�ĳ�����\n");
                set("value", 1000);
                set("material", "paper");
                set("no_give", 1);
                set("no_drop", 1);
                set("no_get", 1);
        }
}

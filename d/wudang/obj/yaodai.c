// OBJ : /u/lius/yaodai.c ҩ��
// By lius 99/8

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(WHT"ҩ��"NOR, ({ "yao dai","dai" }));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "���ǰ�ɫ�Ĵֲ�ҩ��������װ�����ҩ�ġ�\n");
                set("value", 0);
                set("material", "cloth");
                set("no_drop",1);
                set("no_get",1);
                set("no_put",1);
                set("no_give",1);

         }
}

// bojuan.c ����

inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIW"����"NOR, ({"bo juan", "bojuan"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
         set("long", "
            һ���ɫ�Ĳ��֯��һ�㡣\n");
                set("unit", "��");
                set("value", 30);
        }
}

// hongse-yaoshi.c
// action@SJ 2009/1/11
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR"����Կ��"NOR, ({"hongyu yaoshi", "yaoshi"}));
  if (clonep())
        set_default_object(__FILE__);
        else {
        set("long",
                "����һ�ѿ������ܹŹֵ�Կ�ס�\n");
        set("unit", "��");
        set("unique", 1);
        set("value", 1);             
        set("material", "steel");
        set("treasure",1);
        set_weight(10);
        }
        setup();
}


// OBJ: xuantie.c
// Date: Look 99/04/25

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIB "ī������" NOR, ({"mowen xuantie", "xuantie", "tie"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
              set("unit", "��");
              set("long", HIY "����һ��ǧ�꺱����ī�����������ּ��أ�������ɽ��Ļ�����������޽��ɱȡ�\n");
              set("value", 10000);
              set("unique", 1);
	      set("treasure",1);
//              set("no_drop", 1);
              set("no_get", 1);
        }
        setup();
}


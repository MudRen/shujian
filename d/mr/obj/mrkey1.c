// mrkey1.c ��Կ��
// by leontt 2000/10/18

inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIW"��Կ��"NOR, ({"bai yaoshi","mrkey1"}));
        set("long",
                "����һ�Ѱ�Կ�ס�\n");
        set("unit", "��");
        set("weight", 10);
        set("value", 10000);
        set("no_give", "�������������뿪�㡣\n");
//        set("no_get", "���������ò�������\n");
        set("no_drop", "�������������뿪�㡣\n");
}


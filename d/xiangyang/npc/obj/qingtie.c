// qingtie.c

#include <armor.h>
#include <ansi.h>
inherit ITEM;

void create()
{
set_name(HIC"���͵�����������"NOR, ({ "qing tie", "qingtie", "tie" }));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "����һ�����͵�����������ʿ�����������\n");
                set("value", 500);
                set("no_give", 1);
                set("treasure",1);
                set("material", "paper");
                set("no_get", "�������������뿪�Ƕ���\n");
               
        }
}


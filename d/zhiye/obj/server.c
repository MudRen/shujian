// mine.c ��ʯ
//Modified By ChinaNet
//By 2004/1/11

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIR"��������"NOR, ({"yuntie"}));
       
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "��");
                set("weight", 800);
                set("long",HIR"һ�鼫�����ص���������˵���������\n"NOR);
                set("no_get","����ʯ��ô�أ���᲻������\n");
                set("no_drop","������ʯͷ���ҵ�����ô�죿\n");
                set("material", "stone");
                set("value",10000+random(5000));
        }
        setup();
}

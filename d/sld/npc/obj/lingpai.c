
#include <ansi.h>

inherit ITEM;

 void create()
{
        set_name(YEL "ͨ������" NOR, ({"ling pai"}));
        set_weight(20);
        
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�����̵�ͨ�����ơ�\n");
		set("sld",1);
        }

        setup();
}


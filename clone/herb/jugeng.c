#include "herb.h"

void create()
{
        set_name(HIY "�չ�" NOR, ({"ju geng"}));

        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("long","�չ����ջ����������Ȱܻ�\n");
                set("base_unit", "��");
                set("base_value", 4000);
                set("base_weight", 60);
        	set("cure_s",0);
		set("cure_d",5);
		set("cure_n",0);
		
        }
        setup();
}

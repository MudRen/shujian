#include "herb.h"

void create()
{
        set_name(YEL "����" NOR, ({"chan tui"}));
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("long", "���ɣ������׳��ɱ����ɳ����ŵĿǣ���ȥ��ʪ��Ч����\n");
                set("base_unit", "��");
                set("base_value", 4000);
                set("base_weight", 60);
                set("cure_s", 3);
	        set("cure_d", 0);
	        set("cure_n", 0);	
        }
        setup();
}

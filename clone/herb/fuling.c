#include "herb.h"

void create()
{
        set_name(HIG "����" NOR, ({"fu ling"}));
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("long","���ߣ��ݱ�ֲ�����Ѫ�������࣬�ǲ��ɶ�õ��ϼ�ҩ�ġ�\n");
                set("base_unit", "��");
                set("base_value", 4000);
                set("base_weight", 60);
                set("cure_s",40);
	        set("cure_d",0);
	        set("cure_n",53);
		
        }
        setup();
}

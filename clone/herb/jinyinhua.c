#include "herb.h"

void create()
{
        set_name(HIY"��"HIW"��"HIC"��"NOR, ({"jinyin hua","hua"}));

        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("long","���������ٱ�ֲ����ֽ�����ɫ������ҩ���ܻ����\n");
                set("base_unit", "��");
                set("base_value", 4000);
                set("base_weight", 60);
                set("cure_s",0);
	        set("cure_d",1);
	        set("cure_n",0);
		
        }
        setup();
}

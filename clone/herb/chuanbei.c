#include "herb.h"

void create()
{
        set_name(HIY "����" NOR, ({"chuan bei"}));
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("long","�������������ݱ�ֲ���������Σ��油�������������˶�����Ч��\n");
                set("base_unit", "��");
                set("base_value", 4000);
                set("base_weight", 60);
                set("cure_s",10);
	        set("cure_d",0);
	        set("cure_n",0);
		
        }
        setup();
}

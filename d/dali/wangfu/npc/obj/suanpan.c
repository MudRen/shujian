// Modify By River 98/12
#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("ͭ����", ({ "tong suanpan", "suanpan" }) );
        set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "����һ��ͭ�Ƶ����̡�\n");
                set("value", 1000);
		set("material", "iron");
		set("wield_msg", "$N�ó�һ��$n����Ū�����£�Ȼ���������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}

        init_hammer(15);
	setup();
}

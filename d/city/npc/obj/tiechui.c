// hammer.c

#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("����", ({ "tiechui", "hammer" }) );
        set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "����һ�����ص�������\n");
                set("value", 220);
		set("material", "iron");
		set("wield_msg", "$N�ó�һ��$n��������������Ȼ���������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}

        init_hammer(12);
	setup();
}

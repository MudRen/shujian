
#include <weapon.h>

inherit HAMMER;

void create()
{
	set_name("���", ({ "zhong chui","chui" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ѳ�������鳣���Ȼ������ľ�Ƴɣ���Ӳ�쳣��\n");
		set("value", 3);
		set("material", "iron");
		set("wield_msg", "$N�ó�һ��$n���������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}

	init_hammer(15);
	setup();
}

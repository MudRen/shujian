#include <weapon.h>
#include <ansi.h>

inherit COMBINED_ITEM;
inherit THROWING;
inherit F_UNIQUE;
void create()
{
	set_name(HIY "��˦��" NOR, ({ "jin shuaijian", "shuaijian", "jian" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "֧");
		set("long", HIY "���ͽ�����Ǵ��ɻʵ۵Ĵ����ơ�\n" NOR);
		set("base_value", 50000);
                set("base_unit", "֧");
                set("unique", 10);
                set("base_weight", 50);		
	}
	 set_amount(1);
       init_throwing(75);
}

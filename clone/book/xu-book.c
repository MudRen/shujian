#include <ansi.h>

inherit ITEM;

void create()
{
      set_name(GRN "��ϼ���μ�" NOR, ({ "xuxiake youji","youji" }));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�������飬����ϼ�ͶԸ��ط羰��ʤ�͵���ļ��ء�\n");
		set("value", 10000);
		set("material", "paper");
             }
	setup();
}

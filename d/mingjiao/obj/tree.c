#include <ansi.h>
inherit ITEM;
void create()
{
	set_name("����", ({ "shu gan", "tree", "shu", "gan" }));
	set("weight", 130000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "�޴�����ɣ���һ���˻�Ҫ�֡�\n" NOR);
		set("value", 10);                
	}
	setup();
}

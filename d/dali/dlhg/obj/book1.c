// book1.c �����˲�1
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"����ƪ"NOR, ({"tianshen pian","shu","book"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "���������˲���֮һ--����ƪ��\n");
		set("unit", "��");
	     }
}

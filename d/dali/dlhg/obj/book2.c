// book1.c �����˲�2
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"����ƪ"NOR, ({"longshen pian", "shu","book"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "���������˲���֮��--����ƪ��\n");
		set("unit", "��");
	     }
}

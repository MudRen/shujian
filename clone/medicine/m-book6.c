inherit ITEM;

void create()
{
	set_name("����ϡ����", ({ "boji xidoufang", "medicine book"}));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�������������������йر���������顣\n");
		set("value", 8000);
		set("material", "paper");
		set("exp_required", 200000);
		set("jing_cost", 45);
		set("difficulty", 27);
		set("min_skill", 70);
		set("max_skill", 81);
	}
}

#include "m-book.h";

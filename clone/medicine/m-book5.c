inherit ITEM;

void create()
{
	set_name("�����", ({ "douzhen dinglun", "medicine book"}));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ������촿�������Ľ�������ҩ����顣\n");
		set("value", 3000);
		set("material", "paper");
		set("exp_required", 200000);
		set("jing_cost", 40);
		set("difficulty", 26);
		set("min_skill", 60);
		set("max_skill", 71);
	}
}

#include "m-book.h";

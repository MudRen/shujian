inherit ITEM;

void create()
{
	set_name("�ƽ𾵸�����", ({ "kejin jijie", "medicine book" }));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�������ï�������Ľ�������ҩ����顣\n");
		set("value", 2500);
		set("material", "paper");
		set("exp_required", 150000);
		set("jing_cost", 35);
		set("difficulty", 25);
		set("min_skill", 50);
		set("max_skill", 61);
        }
}

#include "m-book.h";

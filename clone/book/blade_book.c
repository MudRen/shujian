// blade_book.c

inherit ITEM;

void create()
{
	set_name("������Ҫ", ({ "daofa gaiyao", "shu", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��������������Ҫ����鼮��\n");
		set("unique", 1);
		set("newbie", 1);
		set("treasure", 1);
		set("value", 100);
		set("material", "paper");
		set("skill", ([
			"name": "blade",	// name of the skill
			"exp_required":	1000,	// minimum combat experience required
			"jing_cost": 20,	// jing cost every time study this
			"difficulty": 20,	// the base int to learn this skill
			"max_skill": 30		// the maximum level you can learn
		]) );
	}
}

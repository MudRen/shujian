// stick-book.c

inherit ITEM;

void create()
{
	set_name("����ͼ��", ({ "stick book", "book" }));
	set_weight(30);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�����������ֽ�����滭��һЩ��������Ρ�\n");
		set("value", 100);
		set("material", "paper");
		set("skill", ([
			"name":  "stick",	// name of the skill
			"exp_required":	1000,	// minimum combat experience required
			"jing_cost":	20,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	40	// the maximum level you can learn
		]) );
	}
}

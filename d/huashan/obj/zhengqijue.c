// ITEM: /d/huashan/obj/zhengqijue.c
// Date: Look 99/03/25

inherit ITEM;

void create()
{
	set_name( "������Ҫ", ({ "shu", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�Ừɽ���������ϲᡣ���滭���˸��ִ������ŵ����ơ�\n");
        set("value", 50);
		set("material", "paper");
		set("skill", ([
			"name":	"zhengqi-jue",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	10+random(20),	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	120	// the maximum level you can learn
		]) );
	}
}

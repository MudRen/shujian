// zhifa.c ָ����Ҫ

inherit ITEM;

void create()
{
	set_name("ָ����Ҫ", ({ "zhifa jueyao", "jueyao", "shu", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ������ָ������������Ҫ����װ�顣\n");
		set("value", 30);
		set("material", "paper");
		set("skill", ([
			"name":	"finger",	// name of the skill
			"exp_required":	100,	// minimum combat experience required
			"jing_cost":	15,	// jing cost every time study this
			"difficulty":	25,	// the base int to learn this skill
			"max_skill":	30	// the maximum level you can learn
		]) );
	}
}

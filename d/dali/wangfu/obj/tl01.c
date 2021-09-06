// fojing-1.c

inherit ITEM;

void create()
{
	set_name( "��˷�", ({ "dacheng fojing", "fojing","book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���˷𾭡�\n");
		set("value", 100);
		set("material", "paper");
		set("skill", ([
			"name":	"buddhism",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost": 25, 	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	30,	// the maximum level you can learn
		]) );
	}
}

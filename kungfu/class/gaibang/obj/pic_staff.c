// book_pic.c

inherit ITEM;

void create()
{
	set_name("ˮī��", ({ "picture", "tu hua", "book" }));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
"����һ����ī��ͼ��������ΰ���ţ��������죬�����ǻ�����³���������սФС��\n");
		set("value", 500);
		set("material", "silk");
		set("skill", ([
			"name":	"staff",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	10,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	31	// the maximum level you can learn
		]) );
	}
}

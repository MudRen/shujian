// book_pic.c

inherit ITEM;

void create()
{
	set_name("ͼ��", ({ "picture", "tu hua", "book" }));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
"����һ���ɵ÷��Ƶ�ˮīͼ�����滭��һ���󺺻��������������ɱ���龰��\n");
		set("value", 500);
		set("material", "silk");
		set("skill", ([
			"name":	"stick",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	10,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	31	// the maximum level you can learn
		]) );
	}
}

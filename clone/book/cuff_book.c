// cuff_book.c 

inherit ITEM;

void create()
{
	set_name("����ȭ��", ({ "shu", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", 
"����һ������ȭ�ף�������ɵ��书�ؼ���\n"
		);				
		set("value", 1000);
		set("material", "paper");
                set("unique", 1);
		set("skill", ([
			"name":	"cuff",	        // name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	30,	// jing cost every time study this
			"difficulty":	10,	// the base int to learn this skill
			"max_skill":	50	// the maximum level you can learn
		]) );
	}
}

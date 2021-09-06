
inherit ITEM;

void create()
{
	set_name("ϴ�辭", ({ "xisui jing", "xisui", "shu", "book" }));
	set_weight(50);
	if( clonep() ) {
		call_out("dest", 1800);
		set_default_object(__FILE__);
	} else {
		set("unit", "��");
		set("long",
			"����һ���Ħϴ�辭\n"
			"��һ�鰵��ɫ���Ʋ���������������Ļ��˲��ٴ������ŵ����ơ�\n");
                set("treasure", 1);
		set("unique", 1);
		set("value", 500);		set("material", "cloth");
		set("skill", ([
			"name":	"force",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	10,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	29	// the maximum level you can learn
		]) );
	}
}

void dest()
{
	destruct(this_object());
}

// fojing2.c

inherit ITEM;

void create()
{
	set_name("��ؾ�", ({ "dazang jing","shu", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��������д�ķ𾭣�������¡�\n");
		set("value", 500);
                set("no_sell", 1);
		set("material", "paper");
		set("skill", ([
			"name":	"huanxi-chan",	
			"exp_required":	0,	
			"jing_cost":	30,	
			"difficulty":	15,	
			"min_skill":    100,
             		"max_skill":	120	
		]) );
	}
}

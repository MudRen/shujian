inherit ITEM;

void create()
{
	set_name("����ҩ��", ({ "shenlongyaoli jing", "jing"}));
	set_weight(1000);
	set("unit", "��");
	set("long", "����һ��½�������������ҩ����\n");
	set("value", 10000);
	set("material", "paper");
	set("unique", 1);
	set("treasure",1);
	set("skill", ([
			"name": "shenlong-yaoli",      
			"exp_required": 10000,  
			"jing_cost":    15+random(20),     
			"difficulty":   25,     
			"max_skill":    120
	]));
}

// xuedao-miji.c 

inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIR"Ѫ���ؼ�"NOR, ({ "xuedao miji","miji","shu", "book" }));
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���Ǳ���΢���Ƶ��ֳ�С���ӣ����������Զ�����������Щ�������ӻ���\n");
		set("value", 500);
                set("treasure",1);
                set("unique", 1);
		set("material", "paper");
		set("skill", ([
			"name":	"xuedao-jing",	
			"exp_required":	30000,	
			"jing_cost":	30+random(20),
			"difficulty":	15,	
             		"max_skill":	50	
		]) );
	}
}

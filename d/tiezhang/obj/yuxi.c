// zitie.c
// zqb

#include <ansi.h>

inherit ITEM;
void setup()
{}
void create()
{
           set_name( HIY"�������ϵ��"NOR, ({"shixi biao","shixi","biao"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", YEL"\n����һ��������ϵ����ʱ����Ǩ�����˷ǣ�����������ǿգ����������ǿա�\n"NOR);  
		set("value", 10000000);
		set("material", "stone");

set("no_cun",1);
set("no_give",1);
set("no_get",1);
		
	}
}

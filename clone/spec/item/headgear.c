
#include <ansi.h>
#include <armor.h>

inherit HEAD;

#include "token.h"

void create()
{	
	set_name(HIY"�ƽ�ͷ��"NOR, ({ "headgear" }) );
	set_weight(100);
	set("long","��"HIY"�ƽ�"NOR"�Ƴɵ�ͷ��,����ȥ�����ޱȡ�\n�������ڲ����һ������:\n");
	set("unit", "��");
	set("value", 3000000);
	set("no_get",1);
	set("no_drop",1);
	set("armor_type", "token_head");
	set("armor_prop/armor",5);
	setup();

}


void init()
{
	add_action("do_discard","discard");
	token_reload();
}



#include <ansi.h>
#include <armor.h>

inherit WRISTS;

#include "token.h"

void create()
{	
	set_name(HIG"�������"NOR, ({ "bangle" }) );
	set_weight(100);
	set("long","�������Ϻõ����"HIG"���"NOR"����ϸ�����ɵ�����,ͨ�徧Ө��͸���˰������֡�\n�������ڲ໹��Լ���Կ���һ��С��:\n");
	set("unit", "ֻ");
	set("value", 3000000);
	set("no_get",1);
	set("no_drop",1);
	set("armor_type", "token_hand");
	set("armor_prop/armor",5);
	setup();

}

void init()
{
	add_action("do_discard","discard");
	token_reload();
}

#include <ansi.h>
#include <armor.h>

inherit FINGER;

#include "token.h"

void create()
{	
	set_name(HIW"�׽����"NOR, ({ "ring" }) );
	set_weight(100);
	set("long","һ��"HIW"�׽�"NOR"�ƳɵĽ�ָ,������һ��˶���"HIW"��ʯ"NOR"��ҫ�����˶�Ŀ�Ĺ�ʡ�\n��������Ȧ����һ������:\n");
	set("unit", "��");
	set("value", 3000000);
	set("no_get",1);
	set("no_drop",1);
	set("armor_type", "token_finger");
	set("armor_prop/armor",5);
	setup();

}

void init()
{
	add_action("do_discard","discard");
	token_reload();
}
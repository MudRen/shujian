
#include <ansi.h>
#include <armor.h>

inherit NECK;

#include "token.h"

void create()
{	
	set_name(HIM"��ˮ������"NOR, ({ "necklace" }) );
	set_weight(100);
	set("long","һ��"HIW"�׽�"NOR"�Ƴɵ�����,���滹����һ��"HIM"��ˮ��"NOR"׹��,����һ�ֺ����ظо���\n׹�ӱ������һ��С��:\n");
	set("unit", "��");
	set("value", 3000000);
	set("no_get",1);
	set("no_drop",1);
	set("armor_type", "token_neck");
	set("armor_prop/armor",5);
	setup();

}

void init()
{
	add_action("do_discard","discard");
	token_reload();
}
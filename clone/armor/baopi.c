// baopi.c ѩ��Ƥ
// by iceland
#include <ansi.h> 
#include <armor.h> 
 
inherit CLOTH; 

void create() 
{ 
	set_name( WHT "ѩ��Ƥ" NOR, ({ "bao pi", "baopi","pi" }) ); 
	set_weight(2500);
	if( clonep() ) 
		set_default_object(__FILE__); 
	else { 
		set("unit", "��");
		set("long", "����һ���Ϻõ�ëƤ������ȥ��ů����ֻ��ѩɽ�е�ѩ����������Ƥë��\n"); 
		set("value", 50000);
		set("material", "fur");
		set("armor_prop/armor", 20);
	} 
	setup(); 
} 

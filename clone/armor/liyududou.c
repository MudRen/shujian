// liyududou.c
 
#include <ansi.h> 
#include <armor.h> 
 
inherit CLOTH; 
 
void create() 
{ 
	set_name( RED "����Ƕ�" NOR, ({ "liyu dudou", "dudou" }) ); 
	set_weight(300); 
	if( clonep() ) 
		set_default_object(__FILE__); 
	else { 
		set("unit", "��"); 
		set("long", "����һ����ɫ�ĶǶ��������ý�������һ�����������Ĵ����㡣\n"); 
		set("value", 300); 
		set("material", "cloth"); 
		set("armor_prop/armor", 1);
		set("female_only", 1);
	} 
	setup(); 
} 

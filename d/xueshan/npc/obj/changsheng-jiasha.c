// changsheng-jiasha.c
 
#include <ansi.h> 
#include <armor.h> 
 
inherit CLOTH; 
 
void create() 
{ 
        set_name( RED "��ʤ����" NOR, ({ "changsheng jiasha", "jiasha" , "jia sha"}) ); 
        set_weight(1000); 
        if( clonep() ) 
                set_default_object(__FILE__); 
        else { 
                set("unit", "��"); 
                set("long", "����һ�����ﴩ�����ģ���������Щ���ģ��Ƿ�����𻤷�����˼��\n"); 
                set("value", 0); 
                set("material", "cloth"); 
                set("armor_prop/armor", 40); 
              } 
        setup(); 
} 

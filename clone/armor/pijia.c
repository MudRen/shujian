// pijia.c

#include <armor.h> 

inherit CLOTH; 

void create() 
{ 
        set_name("Ƥ��", ({ "pi jia", "jia" , "armor" }) ); 
        set_weight(3300); 
        if( clonep() ) 
                set_default_object(__FILE__); 
        else { 
                set("unit", "��"); 
                set("long", "����һ����ӲţƤ�ͱ���Ƭ���ƶ��ɵ�Ƥ�ף���Ȼ���մֲڣ��ɷ������ܻ�����\n"); 
                set("value", 3300); 
                set("material", "cloth"); 
                set("armor_prop/armor", 30);
              } 
        setup(); 
} 

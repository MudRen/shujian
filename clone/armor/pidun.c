// pidun.c

#include <armor.h> 
 
inherit SHIELD; 
 
void create() 
{ 
        set_name("Ƥ��", ({ "pi dun", "dun" , "pidun" ,"shield"}) ); 
        set_weight(2300); 
        if( clonep() ) 
                set_default_object(__FILE__); 
        else { 
                set("unit", "��"); 
                set("long", "����һ���������ܱ࣬����ӲţƤ������ɵ�Ƥ�ܣ����Ե�סԶ�������ļ�ʸ��\n"); 
                set("value", 1500); 
                set("material", "cloth"); 
                set("armor_prop/armor", 15);
		set("armor_prop/dodge", -2);
              } 
        setup(); 
} 

// pixue.c

#include <armor.h> 
 
inherit BOOTS; 
 
void create() 
{ 
        set_name("Ƥѥ", ({ "pi xue", "shoe" , "pixue"}) ); 
        set_weight(2000); 
        if( clonep() ) 
                set_default_object(__FILE__); 
        else { 
                set("unit", "˫"); 
                set("long", "����һ˫����Ƥ���Ƶı�Ƥѥ����ů�൱�á�\n"); 
                set("value", 800); 
                set("material", "cloth"); 
                set("armor_prop/armor", 3);
		set("armor_prop/dodge", 3);
              } 
        setup(); 
} 

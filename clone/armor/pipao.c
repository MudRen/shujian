// pipao.c

#include <armor.h> 

inherit CLOTH; 

void create() 
{ 
        set_name("Ƥ��", ({ "pi pao", "cloth" , "pipao" ,"pao"}) ); 
        set_weight(2500); 
        if( clonep() ) 
                set_default_object(__FILE__); 
        else { 
                set("unit", "��"); 
                set("long", "����һ����ެ���ճ��������·������顢�޵Ȳ���֯�ɡ���Ǯ��ͨ����Ҫ׺��ëƤ��\n"); 
                set("value", 900); 
                set("material", "cloth"); 
                set("armor_prop/armor", 2);
              } 
        setup(); 
} 

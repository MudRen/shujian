// xiquechai.c
 
#include <ansi.h> 
#include <armor.h> 
 
inherit HEAD; 
 
void create() 
{ 
        set_name( WHT"ϲȵ÷֦��" NOR, ({ "xique chai", "meizhi chai" , "chai"}) ); 
        set_weight(100); 
        if( clonep() ) 
                set_default_object(__FILE__); 
        else { 
                set("unit", "��"); 
                set("long", "����һ�����Σ����ʾ�Ө��͸��һֻ���׵�ϲȵվ��÷����֦�ϣ�÷֦�����Ϊ�α���\n"); 
                set("value", 8000); 
                set("material", "stone"); 
             } 
        setup(); 
} 

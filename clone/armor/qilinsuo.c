// qilinsuo.c
 
#include <ansi.h> 
#include <armor.h> 
 
inherit NECK; 
 
void create() 
{ 
        set_name( YEL "����̤����" NOR, ({ "qilin suo", "suo" }) ); 
        set_weight(600); 
        if( clonep() ) 
                set_default_object(__FILE__); 
        else { 
                set("unit", "��"); 
                set("long", "����һ������÷ǳ������ĳ���������׹��һͷ��̤���Ƶ����롣��˵������ħ������\n"); 
                set("value", 3000); 
                set("material", "gold"); 
                set("armor_prop/armor", 5); 
             } 
        setup(); 
} 

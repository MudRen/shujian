 
#include <ansi.h>                     
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIY"��֬��"NOR,({ "lingzhi lan", "lan" }) );
         set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("material", "plant");
                set("long", "����һ�꿪���Ž��޻����ֲ���������ɫ��졣\n");
                set("wear_msg", "");
               
                set("armor_prop/armor", 0);
        }
           
        setup();
}

 

#include <ansi.h>
#include <armor.h>
inherit NECK;
void create()
{
        set_name(HIW"��˿��"NOR, ({ "white silk", "silk" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","һ��ѩ�׵�˿��Χ�����ϣ�������档\n");
		set("unit", "��");
                set("value", 0);
                set("material", "cloth");
                set("armor_type", "cloth");       
                set("armor_prop/armor", 5);
                
        }
setup();
}

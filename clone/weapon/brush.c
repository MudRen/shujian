//bi.c �йٱ�
#include <weapon.h>
#include <ansi.h>

inherit BRUSH;
inherit F_UNIQUE;

void create()
{
        set_name("����",({ "tie bi", "bi","brush" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
            set("value", 1500);
                set("material", "steel");
                set("weapon_prop/parry", 5);
                set("wield_msg", "$N�ӻ����ͳ�һֻ���ʡ�\n");
                set("long", "����һֻ�Ϻ������ƶ��ɵ����ʡ�\n");                
                set("unwield_msg", "$N�����ʷ��뻳�С�\n");                
        }
        init_brush(25);
        setup();
}

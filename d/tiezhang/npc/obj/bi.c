//bi.c �йٱ�
#include <weapon.h>
#include <ansi.h>

inherit BRUSH;
inherit F_UNIQUE;

void create()
{
        set_name("�����йٱ�",({ "panguan bi", "bi" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1);
                set("material", "steel");
                set("weapon_prop/parry", 5);
                set("wield_msg", "$N�ӻ����ͳ�һ�������йٱʡ�\n");
                set("long", "����һ���Ϻ������ƶ��ɵ������йٱʡ�\n");                
                set("unwield_msg", "$N�������йٱʷ��뻳�С�\n");                
        }
        init_brush(30);
        setup();
}

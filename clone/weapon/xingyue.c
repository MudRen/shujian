
#include <ansi.h>
#include <weapon.h>

inherit WHIP;
void create()
{
        set_name(HIY"��������"NOR, ({ "xingyue puti", "puti" }) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1);
                set("unique", 1);
                set("rigidity", 5);
                set("material", "steel");
                set("weapon_prop/parry",5);
                set("treasure",1);
                set("wield_neili", 500);
                set("wield_maxneili", 900);  
                set("wield_str", 22);
                set("long", "����һ�������������Ƴɵ����飬����һ����˿ţ�����ɢ������⣬��������ɮ����֮���\n");
                set("wield_msg","$N����һ������ˢ����һ��������һ���������������裬һ��$n������$N�������ϡ�\n");
                set("unwield_msg","$NĬ��һ���������ӷ𡱣����˫�ְ���������ؿڡ�\n");
       }
       init_whip(55);
       setup();
}


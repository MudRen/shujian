// yang.c �쵶
// zly 99.6.22

#include <weapon.h>
#include <ansi.h>

inherit BLADE;
inherit F_UNIQUE;

void create()
{
        set_name(HIC"�쵶"NOR, ({"yang dao","yang","dao", "blade"}));
        set_weight(10000);
        if( clonep() )
               set_default_object(__FILE__);
        else{
               set("treasure", 1);
               set("unit", "��");
               set("long", HIC"����ԧ�쵶�е��쵶����������ҫ�ۣ������Ͽ������޵С����֡�\n" NOR);
               set("value",4000);
               set("material","steel");
               set("weapon_prop/parry",2);
               set("unique", 1);
               set("rigidity", 3);
               set("sharpness", 3);
               set("wield_neili", 500);
               set("wield_maxneili", 900);
               set("wield_str", 22);
               set("wield_msg", HIC"$N���һ�������ҫ���������˵ĳ����������С����к������������в�����Хһ����\n" NOR);
               set("unwield_msg", HIC"$N���Ὣ���е��쵶��������ĵ��ʡ�\n" NOR);
        }
        init_blade(40);
        setup();
}

//shanyu-jin ɺ����
#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void create()
{
        set_name(BLU"ɺ����"NOR, ({ "shanhu jin", "shanhu","jin" }) );
        set_weight(32000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��ɺ�����ɵĹ��ȣ������ߵ��Ժ��׵��ز��������ֽ�����ͣ�\n"
                            "�ں�������ǧ�������ɺ�����������ж�������ʯ�����޻������۶��\n"
                            "�������У���֮���ۡ�\n"
                );
                set("rigidity", 4);
                set("weapon_prop/parry", 4);
                set("wield_neili", 900);
                set("wield_maxneili", 1400);
                set("wield_str", 24);
                set("unique", 1);
                set("treature", 1);
                set("value", 1000);
                set("material", "steel");
                set("wield_msg", "$N�ó�һ��$n���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }
        init_staff(75);
        setup();
}

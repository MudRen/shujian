#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name(MAG"������"NOR,({ "qingsuo jian", "sword", "jian", "qingsuo" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 10000000000);
                set("rigidity", 3);
                set("sharpness", 3);
                set("unique", 1);
                set("material", "steel");
                set("wield_neili", 200);
                set("wield_maxneili", 1000);
                set("wield_str", 22);                
                set("long", "�˽���Ϊ��������Ƥ�ʣ����̿ڣ���Ϊ���������Σ������ȳ�������������֮һ��Ϊ��֮��Ʒ��\n"); 
                set("wield_msg", "$N��ָ������$nһ������Ȼ����һ���������������ز�ͣ�ض�������������һ�㣡\n");
                set("unwield_msg", "$N����һ��������������ڣ��ѽ�$n������佣�ʡ�\n");
        }
        init_sword(150);
        setup();
}

#include <weapon.h>
#include <ansi.h>

inherit BLADE;
inherit F_UNIQUE;
void create()
{
        set_name(HIY"ն������"NOR,({ "zhanyao nao", "nao","zhanyao" }) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("treasure", 1);
                set("unit", "��");
                set("value", 500000);
                set("unique", 1);
                set("rigidity", 3);
                set("sharpness", 1);
                set("weapon_prop/dodge", -5);
                set("weapon_prop/parry", 5);        
                set("material", "gold");
                set("wield_neili", 100);
                set("wield_maxneili", 700);
                set("wield_str", 22);
                set("wield_msg",HIY"ֻ������ৡ���һ����ն������ɳ�$N���У�����������⣬�������죡\n"NOR);
                set("long", HIY"\n�����ô�������һ���������븱��ֱ�������������������ն��������
����ҵ��Ұ븱��Ӧ�ÿ��Խ����������������\n"NOR);                
                set("unwield_msg", HIY "ն���������շɳ����ַɻ���$N�����С�\n"NOR);               
        }
        init_blade(80);
        setup();
}


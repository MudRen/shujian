#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        set_name(WHT"��ѩ��"NOR,({ "xue sui", "blade", "dao", "sui","xue" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 45000);
                set("rigidity", 3);
                set("material", "steel");
		  set("no_sell", 1);
                set("wield_neili", 10);
                set("wield_maxneili", 100);
                set("wield_str", 20);                
                set("long", "���ֵ������б����ðٴ㾫�ִ��죬�пڷ����ޱȣ���������׾ٰ�һ�����������롣\n����������ˣ�����ѩز�赶ʱ��һ���������ܰ���ƮƮ��������ѩ���������룬���Բ��������������ơ�\n"); 
                set("wield_msg", "$N��ৡ���һ����������һ�Ѻ���������ѩ���ֵ���\n");
                set("unwield_msg", "$NС�������������$n���пڣ���Ȼû��˿�����ˡ����Ƿ��ĵĽ�$n������䡣\n");
        }
        init_blade(80);
        setup();
}

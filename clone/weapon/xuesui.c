#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        set_name(WHT"ѩ��"NOR,({ "xue sui", "blade", "dao", "sui","xue" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 10000);
                set("rigidity", 1);
                set("material", "steel");
                set("wield_neili", 10);
                set("wield_maxneili", 100);
                set("wield_str", 20);                
                set("long", "���ֵ������б����ðٴ㾫�����пڷ����ޱȣ���������׾ٰ�һ���˲�
�۴�ʲô��λ�������롣����������ˣ�����ѩز�赶ʱ��һ����������
����ƮƮ��������ѩ���������룬���Բ��������������ơ�\n"); 
                set("wield_msg", "$Nһ����Ц����ৡ���һ����������һ�������ĸֵ�����\n");
                set("unwield_msg", "$N����һ�鲼����������$n�ϵ�Ѫ������$n�Ż����䡣\n");
        }
        init_blade(50);
        setup();
}

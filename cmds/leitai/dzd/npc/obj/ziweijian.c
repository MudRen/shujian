// ziweijian ��ޱ��

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
//inherit F_UNIQUE;

void create()
{
	set_name(HIY"��ޱ��"NOR,({"ziwei jian","ziwei","jian","sword"}));
	set_weight(15000);
	if( clonep() )
		 set_default_object(__FILE__);
	else {
		  set("unit", "��");
                set("value", 1);
                //set("unique", 1);                
                set("rigidity", 10);
                set("sharpness", 9);
                set("material", "steel");
                set("weapon_prop/parry", 8);
                //set("treasure",1);
             set("dzd",1);

                set("wield_neili", 1000);
                set("wield_maxneili", 1500);
                set("wield_str", 28);
                set("wield_msg", HIY"$N৵�һ������������ޱ�����������߲������������ˡ�\n"NOR);
                set("long", "����һ�����߳������������Ͽ��š���ޱ���������֡�\n���걻���´�������ɽ�ȣ���֪Ϊ��ȴ���������\n");
                set("unwield_msg", HIY "$N����ޱ������һ����������������䡣\n" NOR);
	}
	init_sword(160);
	setup();
}
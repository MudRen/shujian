// looklove copyright at 2000/8/13
#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
        set_name(HIC"���浶"NOR, ({ "qingyan dao", "dao", "blade" }) );
          set_weight(20000);
        if( clonep() )
              set_default_object(__FILE__);
        else {
           set("value", 1000);
           set("rigidity", 3);
        set("long",HIC"�������Լ��ʮ�����������˸�������б����з��Ͽ��й��ӻ��ƣ�����һ����ʱ�Ѿõ���Ʒ��\n"NOR);
           set("sharpness", 3);
           set("unique", 1);
           set("treasure",1);
           set("weapon_prop/parry", 2);
           set("wield_neili", 500);
           set("wield_maxneili", 900);
           set("wield_str", 22);
           set("unit", "��");
        set("wield_msg", HIB"$N�ɱ���ȡ�±�����˫��һ�֣������浶������ʣ����ܶ�ʱ����������ɱ����\n"NOR);
        set("unwield_msg",HIB" ֻ�������һ���죬$N�����ص����浶������ʣ����ڱ��ϡ�\n"NOR);
        }
        init_blade(48);
        setup();
}

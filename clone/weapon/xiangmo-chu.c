#include <ansi.h>
#include <weapon.h>
inherit STAFF;
inherit F_UNIQUE;
void create()
{
        set_name(HIY "��ս�ħ��" NOR, ({ "xiangmo chu", "xiangmo", "chu","staff" }));
        set_weight(32000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIY + "����һ���ִ��ֳ��Ľ��ƣ������ĳߣ���ͷ��ڴ�ϸ�������������������ô���������\n"NOR);
                set("value", 100000);
                set("unique", 1);
                set("rigidity", 8);
                set("material", "gold");
                set("weapon_prop/parry", 4);
                set("weapon_prop/dodge", -11);
                set("treasure",1);
                set("wield_neili", 1000);
                set("wield_maxneili", 2000);
                set("wield_str", 30);
                set("wield_msg", HIY"$N����������һ�ף��������֮����˳��һǣ�Ʊ������ν���������ǰ���������ݣ�\n"NOR);
                set("unwield_msg", HIY"$N���������һ����⣬˳�Ʋ������\n"NOR);
        }
        init_staff(120);
        setup();
}

#include <ansi.h>
#include <weapon.h>

inherit STAFF;
inherit F_UNIQUE;
void create()
{
        set_name(HIY "�Ż�����" NOR, ({ "jiuhuan xizhang", "xizhang", "jiuhuan","staff" }));
        set_weight(32000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "���Ǹ���ҽ�ħ���������Ż����ȡ�������\n"HIY"
  ͭ��������������Ž�������פ�ա������ῴ����ݣ���ɽ������ƻ���
  Ħ�����������ʣ��޲�Ѱ���Ƶعء���Ⱦ�쳾Щ�ӻ࣬ϲ����ɮ����ɽ��\n"NOR);
                set("value", 10000);
                set("unique", 1);
                set("rigidity", 4);
                set("material", "gold");
                set("weapon_prop/parry", 3);
                set("treasure",1);
                set("wield_neili", 800);
                set("wield_maxneili", 1300);
                set("wield_str", 24);
                set("wield_msg", HIY"$N���Ż�����������һ����ֻ�����ϾŻ���ײ��������â���䣡\n"NOR);
                set("unwield_msg", HIY"$N�����еľŻ������ð׳���ϸ����������\n"NOR);
        }
        init_staff(60);
        setup();
}

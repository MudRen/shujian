#include <ansi.h>
#include <weapon.h>
#include <ansi.h>
inherit STAFF;
inherit F_UNIQUE;
void create()
{
        set_name(HIR "�ڽ���" NOR, ({ "wujin hanzhang", "hanzhang","zhang", "wujin","staff" }));
        set_weight(35000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "���ȣ��ഫ������ɽ���ɼ����ڽ��Ͼ������ɣ�ͨ�巢�ڣ�ɢ���ű���������\n");
                set("value", 100000);
                set("unique", 1);
                set("rigidity", 1);
                set("material", "gold");
                set("weapon_prop/parry", 3);
                set("weapon_prop/dodge", -10);
                set("wield_neili", 400);
                set("wield_maxneili", 800);
                set("wield_str", 22);
                set("wield_msg", HIY"$N����һ�ӣ���������һ���ڽ��ȣ�����֮����\n"NOR);
                set("unwield_msg", HIY"$N����ббһ�壬����б���ڱ���\n"NOR);
        }
        init_staff(65);
        setup();
}

#include <ansi.h>
#include <weapon.h>
inherit CLUB;
inherit F_UNIQUE;

void create()
{
 set_name("�����", ({ "banzhu gun", "gun", "banzhu","club" }));
        set_weight(4000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", GRN "\n���Ǹ����Ϻ������Ƴɵĳ��������ּ�Ϊ��ӯ����������ɷ�֦������������롣\n"NOR);
                set("value", 1);
                set("unique", 3);
                set("material", "bamboo");
		set("sharpness", 2);
                set("weapon_prop/parry", 2);
                set("weapon_prop/dodge", 5);
                set("wield_msg", "$N˫��һ�Σ���$n������ñ�ֱ��\n"NOR);
                set("unwield_msg", "$N����һ������$n��ر���\n"NOR);
        }
        init_club(45);
        setup();
}

// ITEM: youlong-jian.c
// Date: Look 99/03/25

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name( YEL "������" NOR, ({ "youlong jian", "youlong", "sword" }));
        set_weight(25000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", YEL "����һ�ѿ������ǳ���ͨ�Ľ�������������һЩ��·���ǳ��Ź֣����ּ�Ϊ���ء�\n" NOR);
                set("value", 15000);
                set("rigidity", 4);
                set("sharpness", 4);
                set("weapon_prop/parry", 4);        
                set("material", "steel");
                set("unique", 1);
                set("treasure",1);
                set("wield_neili", 800);
                set("wield_maxneili", 1300);
                set("wield_str", 23);
   set("wield_msg", YEL "ֻ������쬡���һ����$N�������Ѿ�����һ�ѿ�����������ͨ�ĳ�����\nֻ��$N��һ�þ������������ī�ƿ��ߣ��������һ���ס�������Ϊ֮ʧɫ��\n" NOR);
                set("unwield_msg", YEL "$N�����е��������ջ����䣬���֮��ĸ��Ϳ��ҵ���ɱ֮���������ã�������ʧ��\n" NOR);
        }
        init_sword(220);
        setup();
}

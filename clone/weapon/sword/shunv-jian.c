// shunu jian
// Modify By River
#include <weapon.h>
#include <ansi.h>
inherit SWORD;
inherit F_UNIQUE;
void create()
{
        set_name(HIM"��Ů��"NOR,({ "shunu jian", "shunu", "jian", "sword" }) );
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1500);
                set("rigidity", 3);
                set("sharpness", 3);
                set("unique", 1);
                set("treasure", 1);
                set("material", "steel");
                set("weapon_prop/parry", 2);
                set("wield_neili", 500);
                set("wield_maxneili", 900);
                set("wield_str", 22);
                set("long","�˽��ںڵĽ���û�����󣬾���һ�κ�ľ��������Ů���֡�����ӽ�һ�㳤�̣�ȫ�޶��¡�\n");
                set("wield_msg", HIM"$N���������Ů����ֻ����ƮƮ��������������һ��������Ȼ���ˣ�����Ī�ɺ��ӡ�\n"NOR);
                set("unwield_msg", HIM"$N�������ƣ�����Ů��������ؽ��ʣ����������Ȼ��\n" NOR);
        }
        init_sword(55);
        setup();
}

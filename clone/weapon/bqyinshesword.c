// yinshesword ���߽�

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name(HIW"���߽�"NOR,({ "yinshe sword", "sword","yinshe" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("no_sell", 1);
                set("value",  55000);
                set("rigidity", 6);
                set("sharpness", 6);
                set("material", "steel");
                set("weapon_prop/parry", 15);
                set("wield_neili", 1000);
                set("wield_maxneili", 1500);
                set("wield_str", 25);
                set("long", "��ѽ�����һ�����ߣ�������������Ϊ���ɾ��� ��\n������һ��Ѫ�ۣ����������͵İ��⣬���ǹ��졣\n");                
                set("unwield_msg", WHT "$N����һ�ӣ��������߽��Ѳ�����Ӱ����̬�����ޱȡ�\n" NOR);
                set("wield_msg", WHT"$N΢һ�趯��һ��ҫ�۵���������$Nȫ���������ߣ���â��ס��$N����\n"+
                                    "�Ѷ��˱��������������α���������ĺ���ӳ�ճ�$N���ϸ��ֳ��������顣\n"NOR);
        }
        init_sword(90);
        setup();
}

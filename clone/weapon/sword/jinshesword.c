// jinshesword ���߽�

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name(HIY"���߽�"NOR,({ "jinshe sword", "sword","jinshe" }) );
        set_weight(23000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1);
                set("unique", 1);
                set("rigidity", 6);
                set("sharpness", 6);
                set("material", "steel");
                set("weapon_prop/parry", 5);
                set("treasure",1);
                set("wield_neili", 1000);
                set("wield_maxneili", 1500);
                set("wield_str", 25);
                set("long", "��ѽ�����һ�����ߣ�����Ӳӣ���Ϊ���� ��\n������һ��Ѫ�ۣ����������͵İ��⣬���ǹ��졣\n");                
                set("unwield_msg", HIY "$N����һ�ӣ����н��߽��Ѳ�����Ӱ����̬�����ޱȡ�\n" NOR);
                set("wield_msg", HIY"$N΢һ�趯��һ��ҫ�۵Ľ������$Nȫ���������ߣ���â��ס��$N����\n"+
                                    "�Ѷ��˱��������������α���������ĺ���ӳ�ճ�$N���ϸ��ֳ��������顣\n"NOR);
        }
        init_sword(80);
        setup();
}

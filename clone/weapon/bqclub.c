// weapon: tiegun.c
// Jay 3/18/96

#include <weapon.h>
#include <ansi.h>


inherit CLUB;

void create()
{
        set_name(HIC"��ü��"NOR, ({ "tiegun", "gun" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���԰������Ƴɣ�����ӯ�ѵ���ü������ʮ����ɮ������֮�����ֹ��������£���˵ǹ��һ���ߣ�����һ��Ƭ,���ųưٱ�֮�ס�\n");
                set("value", 50000);
                set("material", "iron");
                set("wield_msg", "$N���˸��������˶����е�$n��\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_club(50);
        setup();
}


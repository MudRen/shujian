// /clone/armor/taijipao.c ̫������

#include <armor.h>
#include <ansi.h>

inherit CLOTH;
inherit F_UNIQUE;

void create()
{
        set_name(HIW"̫������"NOR, ({ "taiji daopao", "dao pao", "daopao" }));
        set_weight(2500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW"����һ���䵱ɽ���������Ƶķ�ѩɫ���޵��ۣ�էһ�����޲��������ơ�\nϸϸ�۲�ȴ���������ú�������ײ�˿��֯���ɡ�\n��ɫ��"HIC"��"HIW"����ɫΪ"HIR"��"HIW"������Բת��һ����̫����ͼ�Ρ�\n"NOR);
                set("material", "silk");
                set("unit", "��");
                set("unique", 1);
                set("value", 1000000);
                set("wear_msg", HIW "ֻ��$N��������һ��ѩ�޵��ۣ��·�һ��"HIC"̫��"HIW"������ζ���\n" NOR);
                set("remove_msg", HIW "$N�������һ��ѩ��ɫ̫�����ۡ�"HIC"̫��Բת"HIW"֮�ζ�ʱ�������Ρ�\n" NOR);
                set("treasure",1);
                set("armor_prop/armor", 75);
                set("armor_prop/parry", 10);
        }
        setup();
}

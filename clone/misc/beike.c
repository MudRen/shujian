// beike.c ���Ǻ�����
// by Lklv for girls :)
// 2001.9.27

#include <ansi.h>
inherit ITEM;

void create()
{
        switch(random(10)) {
               case 0 : set_name(HIY"����"NOR, ({ "hai luo", "hailuo", "luo" }) ); break;
               case 1 : set_name(HIM"ԧ�챴"NOR, ({ "yuanyang bei", "beike", "bei" }) ); break;
               case 2 : set_name(HIR"���鱴"NOR, ({ "zhenzhu bei", "beike", "bei" }) ); break;
               case 3 : set_name(HIW"�ȱ�"NOR, ({ "bei ke", "beike", "bei" }) ); break;
               case 4 : set_name(HIG"������"NOR, ({ "yingwu luo", "hailuo", "luo" }) ); break;
               case 5 : set_name(HIW"�ɻ���"NOR, ({ "hehua bei", "beike", "bei" }) ); break;
               case 6 : set_name(YEL"��ƿ��"NOR, ({ "huoping luo", "hailuo", "luo" }) ); break;
               case 7 : set_name(HIW"������"NOR, ({ "liujiao luo", "hailuo", "luo" }) ); break;
               case 8 : set_name(HIC"ҹ����"NOR, ({ "yeguang luo", "hailuo", "luo" }) ); break;
               case 9 : set_name(HIR"��"HIY"��"HIB"��"NOR, ({ "caihong bei", "beike", "bei" }) ); break;
        }
	set("long", "һ��ɫ�����޵�"+name()+"��\n");
	set_weight(200+random(100));
        set("value", 250+random(500));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        }
        setup();
}
// /u/jpei/thd/obj/tupu.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"�Ź�����ͼ��"NOR, ({ "jiugong tu", "tupu", "tu" }) );
       	set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "
�Ź�������Ź�֮�壬������ꡣ����Ϊ�磬����Ϊ�㣻�������ߣ�������һ������м䡣
����ͼ�⣺Ǭ�����������Σ������飬�������������ۣ��޸��룻����ȱ�����¶ϡ�
��������������ˮ��ˮ��ľ��ľ���𣬻�������������
������ˣ����ľ��ľ����������ˮ��ˮ�˻𣬻�˽�
");
		set("value", 20);
		set("material", "paper");
		set("treasure", 1);
		set("unique", 1);
		set("newbie", 1);
		set("skill", ([
			"name":	"qimen-bagua",	// name of the skill
			"exp_required":	3000,	// minimum combat experience required
			"jing_cost":	20,	// jing cost every time study this
			"difficulty":	25,	// the base int to learn this skill
			"min_skill":	30,	// the minimum level you need before study
			"max_skill":	50	// the maximum level you can learn
		]) );
        }
        setup();
}

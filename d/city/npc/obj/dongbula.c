
#include <weapon.h>
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("������",({"dongbula"}));
        set_weight(150);
        if (clonep())
                set_default_object(__FILE__);
        else{
                set("unit", "��");
                set("value", 600);
                set("material", "wood");
                set("long","����һ��ά�����������������������������(play)����\n");
                        }
        setup();
}

void init()
{
	add_action("do_play", "play");
	add_action("do_play", "tan");
}

int do_play(string arg)
{
	object me;
	me = this_player();
	if (!arg) return 0;
	if (arg !="dongbula") return 0;
	if (arg=="dongbula")
	switch(random(3)) {
	case 0 :
		message_vision(HIW"\n$N���𶬲���������س�����" +
		"����ңԶ�ĵط�����λ�ù��ÿ�������߹�����ձ������Ҫ����" +
		"�������������\n\n"NOR,me);
               break;
	case 1 :
		message_vision(GRN"\n$N���𶬲��������˵س�����" +
		"���̲�ϵ�һ����Ȫ����ɽ�ϵ�һ��ѩ�����籩������Զ��ͣ����������ʲôʱ�򰡣����ܼ������Ц������\n\n"NOR,me);
		break;
	case 2 :
		message_vision(MAG"\n$N���𶬲��������ֵس�����" +
		"����ǵ�ʯͷԲ��Ӳ����ϴ�����ඣ�����ǵĹ�����ӳ����ֻ�۾���Ư����\n\n"NOR,me);
		break;
	}
	return 1;
}
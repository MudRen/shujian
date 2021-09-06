// OBJ : /u/lius/obj/wd_dan.c �����µ�
// By lius 99/9

#include <ansi.h>
inherit ITEM;

string *eat_msg = ({
HIG"\n������ڼ�������������$N����һ����Դ�ɵ�����𣬱����澭������һ����������\n" NOR,
HIM"\n$N����һ�ŵ��裬����һ��һ���������������ζ������������У�����ͷ���ٻ��Ѩ��\n"+
   "$Næ�����������������������չ鵤�����������\n" NOR,
HIC"\n������ǣ�$N�پ���ʹ�ޱȣ�����Ѫ�����ͣ���֫�ٺ���ӯ���ѣ�$Næ�����������࿹��\n"+
   "���ã�������Ϣ��˿������ԴԴ���ϣ������������٣�\n"NOR,
});

string *clr = ({RED"",GRN"",YEL"",BLU"",MAG"",CYN"",WHT"",HIR"",HIG"",HIY"",HIB"",HIM"",HIC"",HIW""});

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name( (clr[random(sizeof(clr))])+ "������ҩ" NOR, ({"wudang danyao","dan"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���䵱���Ƶĵ��裬��˵����ͨ�񣬷��ϻ�ͯ��\n");
                set("value", 1000);
                set("no_drop", "�������������뿪�㡣\n");
                set("no_get", "�����������ò��ˡ�\n");
                set("no_give", "�����������������ˡ�\n");
                set("no_put", "�����������ܷ������ֶ������档\n");
        }
        setup();
}

int do_eat(string arg)
{
	int j,z;
	string msg;
	object me = this_player();        
	
	if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");

	if(query("owner") != me->query("id"))
		return notify_fail("�����������ĵ�ҩ��\n");

	z = random(10) + 1;
	if ( z && me->query("combat_exp") < 2000000) {
		msg = eat_msg[random(sizeof(eat_msg))];
		j = 200 + random(100);
		message_vision(msg, me);
		me->add("combat_exp",j);
		log_file("job/liandan",sprintf("%8s%-10s�䵱���������%3d�㾭�飬�־��飺%d��\n",
			me->name(),"("+me->query("id")+")",j, me->query("combat_exp")), me);
		destruct(this_object());
		return 1;
	}
	else {
		message_vision(YEL"$N����һ�ŵ���,����ҩ��ƽƽ���������档\n"NOR,me);
		me->add("combat_exp",-(random(20)+10));
		destruct(this_object());
		return 1;
        }
        return 1;
}

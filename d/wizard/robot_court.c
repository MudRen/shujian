// Room: /d/wizard/robot_court.c
// By Jpei  Aug 1997

#include <ansi.h>

inherit ROOM;

//void hour_pass();

void create()
{
        set("short", "�����˷�ͥ");
        set("long", @LONG
��������������˺��µĻ����˷�ͥ�����˿�ǽ��һ����ľ������������
�Ļ����˷����⣬����ʲôҲû�С�
LONG);

        set("objects", ([
                "/clone/npc/robot-judge" : 1,
        ]) );
        set("no_clean_up", 1);
        set("no_sleep_room", 1);
        set("no_fight", 1);
        setup();
//      hour_pass();
}

void init()
{
        object me = this_player();
        object weapon = me->query_temp("weapon");
        if (weapon && !weapon->query("imbued")) {
		tell_object(me, YEL"��ͥ���Ͻ�Я���������콻�����ɡ�\n"NOR);
		weapon->unequip();
		weapon->move(environment(me));
		me->start_busy(random(5));
	}
	add_action("do_action", "");
} 

int do_action(string arg)
{
        string action = query_verb();

        switch (action) {
                case "dazuo":
                case "exercise":
                case "tuna":
                case "meditate":
                case "lian":
                case "practice":
                        write("�ⲻ�����������ĵط���\n");
                        return 1;

                case "yun":
                case "exert":
                case "perform":
                case "yong":
                case "fight":
                case "hit":
                case "kill":
                        write("�ⲻ�����ܴ�ܵĵط���\n");
                        return 1;

                case "save":
                        write("�ⲻ�����ܴ��̵ĵط���\n");
                        return 1;
                case "get":
                case "give":
                        write("��ʵ�㣬�����Ƿ�ͥ��\n");
                        return 1;
        }
        return 0;
}

/*
void test_robot()
{
        int i;
        object antirobot;
        object *ob = users();

        message("channel:chat", HIC "�����ġ��������켩�ܲ����������̽Ա��ע�⣬ɨ���ж���ʽ��ʼ��\n" NOR, users());
        for (i = 0; i < sizeof(ob); i++) {
                antirobot = new("/clone/npc/antirobot2");
                antirobot->test_robot(ob[i]);
        }
}

void hour_pass()
{
        mixed *local;

        local = localtime(time());
        if (local[2] == 1) test_robot();
        call_out("hour_pass", 3600);
}
*/


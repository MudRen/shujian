// /d/wudang/shuitan.c  ˮ̶

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIB"ˮ̶"NOR);
        set("long", @LONG
����һ����ˮ̶��̶ˮ�峺��ˮ���̹ǣ�������ʲô������ҧ��Ľ�ֺ��
���ǸϿ����ϰ��ɡ�
LONG                           
        );
	set("outdoors", "�䵱");
        setup();

}

void init()
{
        add_action("do_pa","pa");
        add_action("do_qian",({"qian","dive"}));
}

int do_pa(string arg)
{
	object me;
        me=this_player();

        if ( !arg || arg != "up" )
            return notify_fail("���ù���ʽ��ˮ��������ȥ!\n");

        if ( me->is_busy() || me->is_fighting())
            return notify_fail("����æ���ء�\n");

        message_vision("$N����ʪ͸���������Ƶ������˰���\n", me);
        me->move(__DIR__"gudao3");
        return 1;
}

int do_qian(string arg)
{
	object me;
        me=this_player();

        if ( !arg || (arg != "down"))
            return notify_fail("�����������ˮ��������ȥ!\n");

        if ( me->is_busy() || me->is_fighting())
            return notify_fail("����æ���ء�\n");

        if (arg =="down") {
           message_vision("$Nһ�����ԣ�Ǳ����ȥ��\n", me);
           me->receive_damage("jingli", 60-(int)me->query_skill("dodge", 1)/20);
           me->move(__DIR__"tandi1");
           me->apply_condition("diving",1);
           tell_room(environment(me), me->name() + "������Ǳ��������\n", ({ me }));
           return 1;
        }
        return 1;
} 

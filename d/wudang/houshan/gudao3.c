// /d/wudang/gudao3.c  �ŵ�

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIG"�ŵ�"NOR);
        set("long", @LONG
������ͣͣ�������ѵ���·�ľ�ͷ���������ͻ����������ݣ���ֻҰ��
�������������ȥ��������������ʮ��������һˮ̶��̶ˮ�峺�����������
�������ѵ����޲�����������ȥ����һ����
LONG                           
        );
        set("exits", ([
                "southup" : __DIR__"gudao2",
        ]));

        set("objects",([        
                "/d/wudang/npc/yetu" : 2,
                "/d/wudang/obj/lxshi" :1,
        ]));
        set("outdoors","�䵱");
        setup();

}
void init()
{
       add_action("do_jump","tiao");
}

int do_jump(string arg)
{
	object me;
        me=this_player();
        if ( !arg || arg != "down" )
            return notify_fail("��Ҫ������?\n");
        message_vision(HIY"$Nһ�й�����ǽ����֫ƽչ�͵ó�ˮ̶���¡�\n"NOR, me);
        me->move(__DIR__"shuitan");
        message_vision(RED"��ͨһ����$N����������ˮ����������һ�󷭹���������Ҫ������\n"+
                          "���๾�࣬����������һ����ˮ��\n"NOR, me);
        me->receive_damage("jingli", 20);
        me->set("water", me->max_water_capacity() + 50);
        if ((int)random(me->query_kar()) < 20){
            message_vision(HIW"$N�����ظ�����������Ȱ��³���\n"NOR, me);
            me->move(__DIR__"tandi1");
            me->apply_condition("diving",1);
            me->start_busy(2);
       }
       return 1;
}

// /d/wudang/tandi2.c  ˮ̶��

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIB"ˮ̶��"NOR);
        set("long", @LONG
����ˮ̶̶�ף�̶��ϸɳ��ѩ��̶ˮī����ˮ���̹ǣ��ž�һƬ������
�ֲ���
LONG                           
        );
        set("objects",([        
            "/d/wudang/npc/eyu" : 1,
        ]));
        set("outdoors", "�䵱");
        setup();

}
void init()
{
        add_action("do_qian",({"qian","dive"}));
}

int do_qian(string arg)
{
	object me;
        me = this_player();

        if ( !arg || (arg != "down" && arg != "up" ))
            return notify_fail("�����������ˮ��������ȥ!\n");

        if (arg =="down")
            return notify_fail("���뵱������������ѽ!\n");

        if ( me->is_busy() || me->is_fighting())
            return notify_fail("����æ���ء�\n");
            
        message_vision("$Nһ���ȣ�������ȥ��\n", me);
        me->receive_damage("jingli", 50-(int)me->query_skill("dodge", 1)/20);
        me->move(__DIR__"tandi1");
        tell_room(environment(me), me->name() + "��ˮ��ð��������\n", ({ me }));
        return 1;      
}

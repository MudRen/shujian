// pingtai.c
// By River 98/08/28

inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", HIC"ƽ̨"NOR);
    set("long", @LONG
������ƽ̨���棬������ľ�Դ䣬ɽ����ѡ��������ң�ֻ�����ʯ���
��һ����ء���ر���ɽ�ȣ���������������������ڣ����ռ�����ơ���ϸһ
����ʯ�ϡ���ڣ����������֮�ԣ��������������С��ʯ�̣�zi���� 
LONG
        );

    set("item_desc", ([
       "zi": HIY"����ħ������ܼ��޵�����£������˹����\n" +
                "\n���غ���Ⱥ�����֣��������������౯�򣡡�\n"NOR,
    ]));

    set("outdoors", "����");

    setup();
}

void init()
{
        add_action("do_move", "move");
        add_action("do_move", "yi");
        add_action("do_tiao", ({"tiao", "zong"}));
}

int do_move(string arg)
{
        object me;
        me = this_player();
        if (!arg) return 0;
        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ģ�\n");
        if ( arg == "stone" || arg == "shikuai"){
        if ( me->query("max_neili") < 1500 && me->query_str() < 30 )
          return notify_fail("��Ѿ������ƶ�ʯ�飬������˿������\n");
        if ( me->query_temp("weapon"))
          return notify_fail("�����ű�����ô�ƶ�ʯ�飿\n");
           message_vision(YEL"$N��������˿����������ƶ�ʯ�顣\n\n"NOR,me);
           write(HIG"ֻ��ʯ���������ƶ������ʯ���ƿ��ˣ�¶���˽�ڣ����ڡ�\n"NOR);
           set("exits/enter", __DIR__"jianzhong");
           me->receive_damage("neili", 200);
	   me->receive_damage("jingli", 200); 
           remove_call_out("close");
           call_out("close", 5, this_object());
           return 1;
           }
          return notify_fail("��Ҫ�ƶ�ʲô��\n");
}

void close(object room)
{
        message("vision",HIY"ʯ�������ƻ���ԭλ���ֵ�ס����ڡ�\n"NOR, room);
        room->delete("exits/enter");
}

int do_tiao(string arg)
{ 
        object me;
        me = this_player();
        if ( !arg || arg != "down")
         return notify_fail ("������������");
        if ( arg == "down")
         message_vision(HIG"$N���ζ�ת�����ͻʯ�����������ͱڡ�\n"NOR,me);
         me->move(__DIR__"qiaobi");
         me->receive_damage("qi", 200);
	 me->receive_damage("jingli", 200);
         tell_room(environment(me),HIG + me->name() + "���ζ�ת�����ͻʯ��������ƽ̨������������\n"NOR, ({ me }));
         return 1;
} 

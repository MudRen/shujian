// room: houyuan.c
// Lklv 2001.9.10

#include <room.h>

inherit ROOM;
int do_break(string);

void create()
{
        set("short", "��լ��Ժ");
        set("long", @LONG
������������լ�ĺ�Ժ�������Ƿ�������ù������Ҷ��Ժ�ӵ�������һ��
������̨�Ͽ���Щ�֡�Ժ�ӱ�����һ����(men)�����ѱ�̮����ש�ߵ�ס�ˡ�
LONG
        );

        set("exits", ([
                "down" : __DIR__"well",
        ]));

        set("item_desc", ([
                "men" : "�������ѱ���ס�޷�ͨ�У����������(break)����\n",
        ]));
	setup();
}

void init()
{
        add_action("do_break", "break");
}

int do_break(string arg)
{
        int n;
        n = this_player()->query("neili");
        if( !arg || arg!="men" ) {
                write("��Ҫ�������������˵Ķ�����\n"); // by pishou
                return 1;
        }


        message_vision(
        "$N�ߵ�����ǰ���ݳ��������ʽ������һ������˫��ͬʱ�ĳ���\n", this_player());

        if (n>=500) {
        message_vision(
        "$Nֻ��һ�����죬$N�������ˣ�\n", this_player());
        set("exits/north", __DIR__"laozhai");
        this_player()->set("neili",n-500);
        remove_call_out("close");
        call_out("close", 5, this_object());
        }
        else {
        message_vision(
        "$N���һ���������������ʲôҲû����������$N����������ǿ��\n", this_player());
        this_player()->set("neili",0);
        }

        return 1;
}

void close(object room)
{
        message("vision","���ϵ�שͷ�߿�ϡ�ﻨ��̮���������ֵ�ס��С�š�\n", room);
        room->delete("exits/north");
}

// /u/jpei/thd/jingshe.c
// Modified by Numa 19990902

#include <ansi.h>
inherit ROOM;

int do_pai(string arg);

void create()
{
        set("short",GRN"����"NOR);
        set("long",@LONG
�����һ�������ҩʦ���鷿����������ȫ���Բ���Ƥ��������ɣ���������ʫ���伮��
�����档�ݱ߰���һ������(zhuozi)�����ߵ�ǽ���Ϲ���һ����īɽˮ��
LONG
        );
        set("exits",([
                "south" : __DIR__"shilu.c",
        ]) );
        set("objects",([
                __DIR__"obj/box.c" : 1,
        ]) ); 
        set("no_clean_up",0);
        set("item_desc",([
                "table" : "����һ��ʯ����\n",
                "zhuozi" : "����һ��ʯ����\n",
        ]) );
        setup();
}

void init()
{
        add_action("do_pai", "pai");
        add_action("do_pai", "press");
}

void close_door(object room)
{
        message("vision", "�����Զ�����������ס����ڡ�\n", room);
        room->delete("exits/enter");
}

int do_pai(string arg)
{
        object me = this_player();

        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���أ�\n");
        if( arg == "table" || arg == "zhuozi")
        {
                write("������Ϲ��ŵĵ�īɽˮ������������¶��һ����������\n");
                set("exits/enter", __DIR__"liandanfang.c");
                remove_call_out("close_door");
                call_out("close_door", 5, this_object());

                return 1;
        }
}



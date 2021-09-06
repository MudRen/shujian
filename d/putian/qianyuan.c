// Room: /d/putian/qianyuan.c ǰԺ
// lklv 2001.7.21

inherit ROOM;
void create()
{
        set("short", "ǰԺ");
        set("long", @LONG
����ɽ���ڵ�һ����Ժ�ӣ��ܿյ����������������һ�����ʯ������Ժ
�ӵĶ��Ͻǣ�����һ�������ܣ���������İ��Ÿ�ʽ�������������Ҳ���ɮ
������һ�����䡣�����м��������಼ɮ�µ�ɮ�ˣ��������Ŵ�ɨ���ڵ���ͷ
ɨ�ء��������ֵ����������£������ƺ�Ҳ����ͨ��
LONG
        );

        set("exits", ([
                "south" : __DIR__"cb-dian",
                "east" : __DIR__"xiaoyuan2",
                "west" : __DIR__"xiaoyuan3",

        ]));

        set("objects",([
        	__DIR__"npc/seng-bing" : 2,
        ]));

        set("outdoors", "����");
        setup();
}
void init()
{
        add_action("do_open", "open");
        add_action("do_open", "kai");
        add_action("do_close", "close");
}

void close_gate()
{
        object room;

        if(!( room = find_object(__DIR__"shanmen")) )
                room = load_object(__DIR__"shanmen");
        if(objectp(room))
        {
                delete("exits/north");
                        message("vision", "ɮ����ǰ�Ѵ��Ź���������\n", this_object());
                room->delete("exits/south");
                message("vision", "ƹ��һ�����������˰Ѵ��Ź����ˡ�\n", room);
        }
}

int do_close(string arg)
{
        if (!query("exits/north"))
                return notify_fail("�����Ѿ��ǹ��ŵ��ˡ�\n");

        if (!arg || (arg != "gate" && arg != "north"))
                return notify_fail("��Ҫ��ʲô��\n");

        message_vision("$N��ɮ�����˵�ͷ��\n", this_player());

        remove_call_out("close_gate");
        call_out("close_gate", 2);

        return 1;
}

int do_open(string arg)
{
        object room;

        if (query("exits/north"))
                return notify_fail("�����Ѿ��ǿ����ˡ�\n");

        if (!arg || (arg != "gate" && arg != "north"))
                return notify_fail("��Ҫ��ʲô��\n");

        if(!( room = find_object(__DIR__"shanmen")) )
                room = load_object(__DIR__"shanmen");
        if(objectp(room)){
                set("exits/north", __DIR__"shanmen");
                message_vision("$Nʹ���Ѵ��Ŵ��˿�����\n", this_player());
                room->set("exits/south", __FILE__);
                message("vision", "֨��һ�����������˰Ѵ��Ŵ��ˡ�\n", room);
                remove_call_out("close_gate");
                call_out("close_gate", 10);
        }
        return 1;
}

string look_gate()
{
        return "һ���������ߵ����ɼľ��ͭ���š�\n";
}

int valid_leave(object me, string dir)
{
        if (dir == "north" && me->id("seng bing")) return 0;
        return ::valid_leave(me, dir);
}


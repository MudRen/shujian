// Modify By Yanyang@SJ 2001.3.2
// Room: /d/tiezhang/zoulang-4.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������һ�������ϡ����汱�涼�и��ڰ���С�ݣ�����������һЩ������
LONG
        );
        set("exits", ([
                "west" : __DIR__"zoulang-1",
                "east" : __DIR__"gjfang",
                "north": __DIR__"xxsnan",
                "south": __DIR__"xxsnv",
        ]));

        set("item_desc",([            
            "north" : "������ߺܰ�����ʲôҲ��������ֻ������һ�������Եĺ�����\n",
            "south" : "������ߺܰ�����ʲôҲ��������ֻ���ŵ�һ�ɵ��������㡣\n",
           ]));

        set("no_clean_up", 0);

        set("coor/x",-310);
        set("coor/y",-250);
        set("coor/z",10);
        setup();
}

int valid_leave(object me, string dir)
{
        if ((dir == "north" && me->query("gender") == "Ů��")||(dir == "south" && me->query("gender") != "Ů��"))
        {
                return notify_fail("�㲻�ܽ�ȥ��ȥ��һ����Ϣ�Ұɣ�\n");
        }
        return ::valid_leave(me, dir);
}


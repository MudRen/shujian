// Room: /d/huashan/v-road-3.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
������Χ���ǹ�ľ��ǰ���޷��������ߣ������Ǹղ���ʱ��·��������Լ
Լ������������Ů��(mount)��
LONG);
        set("item_desc", ([
"mount" : "����ͷ������ȥ����Լ������Ů��߸����ϡ�ͻȻ�㷢�־�������ܽ���\n"
        "�ط��������и������������⣡\n",
        ]) );
        set("exits", ([ /* sizeof() == 3 */
                "westdown"      : __DIR__"v-road-2",
                "southeast"      : __DIR__"shulin3"
        ]));
        set("outdoors", "��ɽ");
        set("coor/x",60);
  set("coor/y",90);
   set("coor/z",0);
   setup();
}

int init()
{
        add_action("do_climb","climb");
}

int do_climb(string arg)
{
        object me;
        me=this_player();
        if ( arg!="up") return 0;
        tell_object(me, "��ץס��Χ�Ĺ�ľ��������ȥ��\n");
        message("vision", "ֻ��" + me->query("name") + "ץס��Χ�Ĺ�ľ��������ȥ��\n", environment(me), me);
        me->move(__DIR__"v-road-4");
        return 1;
}

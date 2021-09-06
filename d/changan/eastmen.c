// Write By Yanyang@SJ 2001.9.20
// Room: /d/changan/eastmen.c

inherit ROOM;

string look_gaoshi();

void create()
{
        set("short", "������");
        set("long", @LONG
�����ǳ����ǵĶ����š����ǺӼ������������ҳǸ�ǽ����һ�򵱹أ�
���Ī��֮�ơ�������¥��ֻ����¥�ߴ������ڱ����䱸ɭ�ϡ���ǽ�����Ź�
���ĸ�ʾ(gaoshi)���ٱ�����������ؼ��ÿһ�����������ˡ�
LONG
        );
        set("outdoors", "����");

        set("item_desc", ([
                "gaoshi" : (: look_gaoshi :),
        ]));

        set("exits", ([
                "east" : __DIR__"eastroad1",
                "west" : __DIR__"eastjie4",
                "up"   : __DIR__"eastchl",
        ]));
        set("objects", ([
                __DIR__"npc/wujiang" : 1,
                __DIR__"npc/bing" : 2,
        ]));

        set("incity",1);
	setup();
}

int valid_leave(object me, string dir)
{
        if (!wizardp(me) && (objectp(present("guan bing", environment(me))) || objectp(present("wu jiang", environment(me))))&& 
                dir == "up")
                return notify_fail("�ٱ���ס�����ȥ·��\n");
        return ::valid_leave(me, dir);
}

string look_gaoshi()
{
        return FINGER_D->get_killer() + "\n����֪��\n";
}

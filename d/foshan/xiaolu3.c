//xiaolu3.c by zly

inherit ROOM;

void create()
{
        set("short", "С·");
        set("long",
"������һ����ɽ��С·���ߵ�����·Խ��Խխ����˵ɽ�Ͼ�����ɽ
����û��Ҫ����С�ġ�û��ʲô���鿴�����ǻ�ȥ�ɡ�\n"
        );
        set("outdoors", "��ɽ");
        set("exits", ([
            "north" : "/d/fuzhou/wroad10",
            "northeast" : __DIR__"milin",
            "southdown" : __DIR__"xiaolu2",
        ]));
   setup();
}


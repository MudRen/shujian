// Room: /city/guangchang.c
// YZC 1995/12/04 
inherit ROOM;

string look_notice();

void create()
{
    set("short", "Ұ��ƽ��");
    set("long", @LONG
     ������һ����ս�����ż��������Ҳ���Ұ�ݴ����������н�ʬ��û������������
LONG
    );
        set("outdoors", "city");
       set("exits", ([
        "east" : __DIR__"dongdajie1",
        "south" : __DIR__"nandajie1",
        "west" : __DIR__"xidajie1",
        "north" : __DIR__"beidajie1",
	    ]));
    setup();
}

//�Ǿ���
int is_mirror() { return 1; }

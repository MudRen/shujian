// Room: /u/swl/songshan/xxjge.c

inherit ROOM;

void create()
{
	set("short", "��ԯ����");
	set("long", @LONG
��������Ÿ��ֳ��̽��������������ߣ���������ԯ��ȴ���������
��һͳ���ֵ�Ұ�ġ�
LONG);
	set("exits", ([ 
            "north" : __DIR__"yushu-lou",
        ]));
        set("objects", ([ 
            BINGQI_D("changjian") : 1+random(3),
            __DIR__"npc/ssdizi" : 1,
        ]));
	set("coor/x",20);
  set("coor/y",330);
   set("coor/z",120);
   setup();
}

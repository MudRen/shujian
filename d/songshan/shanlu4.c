// Room: /u/swl/songshan/shanlu4.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
��·����һת��ǰ���������������ֿ�ʼ�Եÿ������Ƚ�ƽ̹�ˣ�
�����Ѿ��ӽ���ɽ�ľ����ˡ�
LONG	);
	set("exits", ([ 
            "southeast" : __DIR__"xtlxia",
            "northwest" : __DIR__"ctmen",
        ]));
        set("objects", ([ 
            __DIR__"npc/ssdizi" : 2,
        ]));
        set("jingli_cost/northwest", 10);
	set("outdoors", "��ɽ");
	set("coor/x",40);
  set("coor/y",220);
   set("coor/z",100);
   setup();
}



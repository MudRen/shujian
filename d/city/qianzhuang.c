// Room: /city/qianzhuang.c

inherit ROOM;

void create()
{
        set("short", "���ի");
        set("long", @LONG
����һ�����ֺŵ�Ǯׯ�����м��������ʷ����ȫ�����ض��зֵꡣ����
�е���Ʊ�����ǳ��ã�ͨ��ȫ����
LONG
        );

        set("exits", ([
                "east" : __DIR__"beidajie2",
        ]));

        set("objects", ([
                __DIR__"npc/qian" : 1,
                __DIR__"npc/dashou" : 1,
          
        ]));

        set("coor/x",110);
  set("coor/y",10);
   set("coor/z",0);
   set("coor/x",110);
  set("coor/y",10);
   set("coor/z",0);
   set("coor/x",110);
  set("coor/y",10);
   set("coor/z",0);
   set("incity",1);
	setup();
}

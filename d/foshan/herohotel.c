// Room: /d/fuoshan/herohotel.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "Ӣ��¥");
	set("long", @LONG
����һ������������Ĵ��¥��������д�š�Ӣ��¥�������������
�����߳��Ŵ�������¥�ﵶ����죬�����������������
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "up" : __DIR__"herohotel2",
  "south" : __DIR__"nanjie",
  "north" : __DIR__"guangchang",
]));
	set("no_clean_up", 0);

        set("objects", ([
        __DIR__"npc/xiaoer" : 1,
]));

	set("coor/x",0);
  set("coor/y",-540);
   set("coor/z",0);
   setup();
}

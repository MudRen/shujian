// Room: /d/fuoshan/herohotel2.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "Ӣ��¥��¥");
	set("long", @LONG
��¥�����νྻ�����п������κ��ݣ�ʮ���Ǹ��̴�֡�
LONG
	);
        set("outdoors","��ɽ");
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"herohotel",
]));

        set("objects", ([
        __DIR__"npc/fengqi" : 1,
]));

	set("no_clean_up", 0);

	set("coor/x",0);
  set("coor/y",-540);
   set("coor/z",10);
   setup();
}

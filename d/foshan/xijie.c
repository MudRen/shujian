// Room: /d/fuoshan/xijie.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "��ɽ����");
	set("long", @LONG
����һ����������ʯ��ֵ��������������ǳ����֣������Ƿ�ɽ����
��㳡�����������������������������������ɷ��վ�����Ƚ�ߺ����
����ǰ��
LONG
	);
        set("outdoors","��ɽ");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"duchang",
  "east" : __DIR__"guangchang",
  "west" : __DIR__"xijie2",
]));

        set("objects", ([
        __DIR__"npc/liumang" : 2,
]));

	set("coor/x",-10);
  set("coor/y",-530);
   set("coor/z",0);
   setup();
}

// Room: /d/fuoshan/ximen.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "����");
	set("long", @LONG
�����Ƿ�ɽ������š������������ɹ������������������һ��
������Ĵ���Ƿ�ɽ�����Ҫ�ֵ���
LONG
	);
        set("outdoors","��ɽ");
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"xijie2",
        "west" : __DIR__"road1",
]));
	set("no_clean_up", 0);

	set("coor/x",-30);
  set("coor/y",-530);
   set("coor/z",0);
   setup();
}

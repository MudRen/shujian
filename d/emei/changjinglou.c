// Room: /d/emei/changjinglou.c

inherit ROOM;

void create()
{
	set("short", "�ؾ�¥");
	set("long", @LONG
�����Ǳ����µĲؾ�¥����¥�������������˺ö���ܣ����ϰ����˾��顣
�����������µ�Сʦ̫����һ�Ǿ����ض��ž��顣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"daxiongdian",
]));

	setup();
}

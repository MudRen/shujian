// Room: /d/emei/cangjinglou.c

inherit ROOM;
void create()
{
	set("short", "�ؾ�¥");
	set("long", @LONG
�����Ǳ����µĲؾ�¥����¥�������������˺ö���ܣ����ϰ����˾��顣
�����������µ�Сʦ̫����һ�Ǿ����ض��ž��顣
LONG
	);

	set("exits", ([
	    "out" : __DIR__"daxiongdian",
	]));
	set("objects",([
		"/d/emei/obj/fojing1" : 1,
		"/d/emei/obj/fojing2" : 1,
		"/d/emei/npc/daoming" : 1,
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	if (dir == "out" && present("shu", me) && objectp(present("daoming shifu", environment(me))))
		return notify_fail("����Сʦ���ȵ������ؾ�¥���鼮���������\n");

	return ::valid_leave(me, dir);
}

// Room: /d/huashan/shiwu.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long",@LONG
���߽�ʯ�ݣ����ڳ�����ᣬ��Ȼ�����û����ס�ˡ�
LONG);

	set("cant_hubiao", 1);
	set("exits", ([
		"west" : __DIR__"shulin4",
	]));

	set("objects",([
		__DIR__"npc/mu_renqing" : 1,
	]));

	setup();
}
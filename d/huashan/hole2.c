// Room: /d/huashan/hole2.c
// Date: Look 99/03/25

inherit ROOM;
void create()
{

	set("short", "ʯ��");
	set("long",@long
����һ����ɽ����ʯ���ϵ�һ�������۵�ʯ������ɽ�ɸ����ߺͰ����߾�
�����ڴˡ���ɽ�ɵ���һ������ܹ��������ǣ�����ܹ��������书��Ȼ�õ�
���ǵĴ���ָ�㡣
long);
	set("exits",([
	"out" : __DIR__"song",
]));
	set("objects",([
	__DIR__"npc/gao" : 1,
	__DIR__"npc/ai" : 1,
]));
	setup();
}

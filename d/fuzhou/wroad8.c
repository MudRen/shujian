// Room: /d/fuzhou/wroad8.c
// Lklv 2001.9.10

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
��������ɽ����һ��ɽ·��ʱֵ���գ�·�Ե�ɽ���ϵ��������˽��ɫ��
�Ͳ˻���һ����ɽ�紵�����������������Ͳ˻�����ζ���ɴ������Ϸ���ɽ�
�����㣬�������ɵ����ݡ�
LONG
	);

	set("exits", ([
		"southwest" : __DIR__"wroad9",
		"northeast" : __DIR__"wroad7",
	]));

	set("objects",([
		NPC_D("tiao-fu") : 1,
		__DIR__"npc/tangzi" : 1,
	]));

	set("outdoors", "����");
	setup();
}

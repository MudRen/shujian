// Room: /d/huashan/npc/baichi.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
	set("short", "�ٳ�Ͽ");
	set("long", @LONG
�߹�ǧ�ߴ���ǰ���ּ���һҪ���İٳ�Ͽ���ٳ�Ͽ����ǧ�ߴ����վ�����
��ʮ�ֶ��ͣ��ұ�����������������������
LONG
	);
	set("exits", ([
		"northdown" : __DIR__"qianchi",
		"eastup" : __DIR__"laojun",
	]));
	set("objects", ([
		__DIR__"npc/monkey" : 1,
		NPC_D("tiao-fu") : 1,
	]));
	set("outdoors", "��ɽ" );
	setup();
}
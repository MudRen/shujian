// Room: /d/shaolin/xiaojing2.c

inherit ROOM;

void create()
{
	set("short", "�﹡��");
	set("long", @LONG
ת��ɽ��ֻ�����ù�ʵ���۵Ĵ�����������������﹡�ߣ���������˺�
������ӣ�ʹ���̲�ס��ժ�¼��ų������������Ű��������������������
��ª�����ݡ�
LONG
	);

	set("exits", ([
		"southdown" : "/d/group/entry/slxiaoj1",
		"west" : __DIR__"houshan",
	]));

	set("objects",([
		NPC_D("kid") : 1,
	]));

	set("outdoors", "����");
	setup();
}

// Write By Yanyang@SJ 2001.10.13
// Room: /d/changan/southroad3.c

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
����һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ���������������������
�����̣����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡���ʱ����
������������߷ɳ۶���������һ·��������·��������������������֡�
LONG
	);
	set("outdoors", "����");
	set("exits", ([
		"west"   : "/d/xiangyang/caiyongmanor",
		"south"  : "/d/xiangyang/lantian",
		"north"  : __DIR__"southroad2",
	]));
	set("objects", ([
		CLASS_D("gaibang/qigai") : 1,
	]));
	setup();
}

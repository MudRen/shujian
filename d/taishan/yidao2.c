// Room: /d/shaolin/yidao2.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵ����̣����Ŵ�
��������Ͼ��Ͽ��������������������ǳ����֡���ʱ����������������
�߷ɳ۶���������һ·��������·��������������������֡�
LONG
	);

	set("exits", ([
                "west" : __DIR__"hsroad2",
	        "east" : "/d/group/entry/tsyidao3",
	        "northwest" : __DIR__"shulin1",
	]));

	set("objects",([
		__DIR__"npc/shu-sheng" : 1,
	]));

 	set("outdoors", "̩ɽ");
	setup();
}

// Room: tianjing.c
// Lklv Modify 2001.9.21

inherit ROOM;
void create()
{
	set("short", "�쾮");
	set("long", @LONG
���߽�һ��С�쾮����ʯ����·��·��Χ�����ļ����ݣ�������������ͨ
����Ժ�䣬����һ��СС���쾮�����õ�Ҳ�Ǿ���ϸ�£���߽��ġ�
LONG
	);
	set("objects", ([
                __DIR__"npc/jiading": 1,
		__DIR__"npc/wenfangshi": 1,
	]));
	set("outdoors", "����");
	set("exits", ([
		"north": __DIR__"shidetang",
		"south": __DIR__"houhuayuan",
		"west":__DIR__"lianwu",
		"east":__DIR__"guifang",
	]) );

	set("incity",1);
	setup();
}

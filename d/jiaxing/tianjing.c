// /d/jiaxing/tianjing.c �쾮
// by shang 97/6

inherit ROOM;

void create()
{
        set("short", "�쾮");
	set("long", @LONG
����½��ׯׯ�ڵ��쾮��������һ����ʯ���磬���滭��һ������������
����һ���������ڵ�ͷɨ�ء�
LONG
	);

	set("exits", ([
                "west" : __DIR__"dating",
                "east" : __DIR__"luzhuang",
	]));

        set("objects", ([
                __DIR__"npc/puren" : 1,
        ]));
        set("outdoors", "����");
	setup();
}

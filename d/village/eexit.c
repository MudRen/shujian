// Room: /d/village/eexit.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����ǻ�ɽ���£�����������ɽ��·�ˡ�������һ��С��ׯ���������˼�
�����࣬�����ǹ����ճ������������Ϣ���������
LONG
	);
	set("exits", ([
		"west" : __DIR__"shilu6",
		"east" : "/d/huashan/path1",
	]));

/*        set("objects", ([
                CLASS_D("gaibang/qigai") : 1,
        ])); */
        set("outdoors", "��ɽ");
	setup();
}

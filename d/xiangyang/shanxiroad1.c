// /d/xiangyang/shanxiroad1.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
�������¶��������·�ϣ�ż��������������ҴҶ����������Ѿ�������
�ؽ磬�����Ͻ���������ڣ������߲�Զ��������ɽ���µķ����ˡ�
LONG
	);
        set("outdoors", "����");

	set("exits", ([
            "west" : "/d/gumu/fchuan",
		"southeast" : __DIR__"outnroad3",
		"northwest" : __DIR__"shanxiroad2",
	]));

	setup();
}


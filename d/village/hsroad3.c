// Room: /d/village/hsroad3.c
// ��ɽ��������Ľӿ�

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
һ���ӿ����ݵ���·�����������Ĳ�֪��ͨ��η���ǰ����Զ������һ��
С��ׯ�������������˼Ҳ��࣬�������ճ������������Ϣ���������
LONG
	);
        set("outdoors", "��ɽ");

	set("exits", ([
		"south" : "/d/xiangyang/shanxiroad2",
		"north" : __DIR__"sexit",
	]));
	setup();
}

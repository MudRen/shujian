// Room: /d/jiaxing/beimen.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���ǽ������Ǽ��˵ı��ţ����Ų��Ǻܸߣ��������кܾõ���ʷ�ˣ�����
��ɣ�ĺۼ��̻��ڳ�ǽ�ϣ��߲����ֹ��ӡ��ֵ������˲��࣬���洫��һ����
������������������ʯ·ͨ�����ݡ�
LONG
	);

	set("exits", ([
                "northwest" : __DIR__"road1",
		"south" : __DIR__"jiaxing",
	]));

        set("outdoors", "����");
	setup();
}

// Room: /d/jiaxing/jiaxing.c

inherit ROOM;

void create()
{
	set("short", "�м�");
	set("long", @LONG
���ǽ������Ǽ��˵������м��������������������������֡���ɫ������
�����ؽ�������������Ÿ��ֻ�Ʒ������ķ����������һ�����š�������ֱ
���Ƕ����Ƿ羰�续���Ϻ����������Ľֵ�ͨ�����ݡ�
LONG
	);

	set("exits", ([
                "north" : __DIR__"beimen",
                "east" : __DIR__"dbianmen",
		"south" : __DIR__"jxnanmen",
	]));
        set("outdoors", "����");
	setup();
}

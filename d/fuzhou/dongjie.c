// Room: /d/fuzhou/dongjie.c
// Lklv 2001.9.10
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǹ��ݵĶ��֣������Ϻܶ������������������������ģ����д��ű�
���ģ�����������������ȥ���ֱ���һ�Źžɵ��Ŵ����ű��Ϲ���һ������
Ԫ���Ļ��ӣ�����������һ��Ǯׯ��������Լ���Կ���һ��С�ţ�����С����
�ű���ˣ��
LONG
	);

	set("exits", ([
                "west" : __DIR__"zhongxin",
                "east" : __DIR__"haigang",
                "north" : __DIR__"dongxiang",
                "south" : __DIR__"shiqiao",
	]));

	set("outdoors", "����");
	setup();
}



// Room: /d/fuzhou/shanpo.c
// Lklv 2001.9.10
inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
��������ɽ��´��һ��ɽ�£�������������ó��Ÿ߸߰�������ľ���ּ�
�Ĳݴ��ﲻʱ�ܹ�һ��ֻҰ�á���������Ĵ��Եĺõط������µĿյ��ϵ���
�����˽��ɫ���Ͳ˻���һ����ɽ�紵�����������������Ͳ˻�����ζ������
������Լ���Կ���һ�������ӡ�
LONG
	);

	set("exits", ([
		"south" : __DIR__"wroad2",
	]));
        set("objects", ([
                "/d/wudang/npc/yetu" : 2,
        ]));
	set("outdoors", "����");
	setup();
}

// Room: /d/fuzhou/xixiang4.c
// Lklv 2001.9.7
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǹ��ݳ�������Աߵ�һ��С��������·�ܿ��������������
��խ���˶��٣����߿���һЩС���ӡ������ǼҲ�ݣ���Ϊ�����Ĳ�Ҷ������
�������Գ��˱����ˣ�������Ʒ��������Ҳ���١������Ǽҿ�ջ���ſڸ߸�
����һ���̽����ң���д�š������ջ���ĸ����֡�
LONG
	);

	set("exits", ([
                "west" : __DIR__"chalou",
                "north" : __DIR__"xixiang3",
                "south" : __DIR__"kezhan",
	]));
        set("objects", ([
                "/d/huashan/npc/haoke" : 1,
        ]));
	set("outdoors", "����");
	setup();
}

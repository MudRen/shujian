// Room: /d/fuzhou/xijie2.c
// Lklv 2001.9.7
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǹ��ݵ�����֣�������һ���ưܵ�լ�ӡ�������һ���ӻ��̣�ר��
һЩŮ�˼��õĶ���������������ȥ�����������Կ���һ����Ժ�ף�һ��
����߸�Ʈ������Ǹ����ھֵ����ڡ�
LONG
	);

	set("exits", ([
                "east" : __DIR__"xijie",
                "west" : __DIR__"ximen",
                "south" : __DIR__"xixiang3",
                "north" : __DIR__"xixiang2",
	]));

        set("objects", ([
                CLASS_D("gaibang/qigai") : 1,
        ]));
	set("outdoors", "����");
	setup();
}

// /d/xiangyang/cross1.c
// rebuild by Lklv 2001.9.24

inherit ROOM;

void create()
{
        set("short", "�����ֽ�");
        set("long", @LONG
�����Ǿ���������������ͨ�����ź����ŵĶ���·�ڣ���ʱ���ж������
��ʿ��������ȥ����ת�߱��ֳ��ǿ��Խ������������Ͼ��ڣ�����ȥ�ι���
�����䵱ɽ������ֱ�߳������Ĵ��������淽����Լ��һ����¥��
LONG
        );
        set("outdoors", "����");
        set("xyjob", 1);
        set("exits", ([
                "west" : __DIR__"xjie",
                "east" : __DIR__"bjie3",
                "south" : __DIR__"xpailou",
        ]));
        set("objects", ([
                NPC_D("poorman") : 1,
        ]));

        set("incity",1);
	setup();
}

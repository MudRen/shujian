// /d/xiangyang/bcx4.c ������
// Lklv 2001.9.22

inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
������������ͨ�����ŵ�һ��С���Ϊ�ش������Ǳ����������ǰ�����
�����������������С���Ͼ�Ŀ��ȥ�����������Ǹ�ʽ�����ĵ��̣�������
�����������֡������мҵ��̿����ţ��Ǹ�С�Եꡣ
LONG
        );
        set("outdoors", "����");
        set("xyjob", 1);
        set("exits", ([
                "west" : __DIR__"xiaocd",
                "north" : __DIR__"bcx3",
                "south" : __DIR__"bhmnj",
        ]));

        set("objects", ([
		NPC_D("poorman") : 1,
                __DIR__"npc/gongzi" : 1,
        ]));
        set("incity",1);
	setup();
}

// /d/xiangyang/bcx3.c ������
// Lklv 2001.9.22

inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
������������ͨ�����ŵ�һ��С���Ϊ�ش������Ǳ����������ǰ�����
�����������������С���Ͼ�Ŀ��ȥ�����������Ǹ�ʽ�����ĵ��̣�������
�����������֡�������һ�ҿ�ջ�������мҵ��̣��ſڹ���һ�����ӣ����滭
��һ���㡣
LONG
        );
        set("outdoors", "����");
        set("xyjob", 1);
        set("exits", ([
                "west" : __DIR__"xyudian",
                "north" : __DIR__"jianghukz",
                "south" : __DIR__"bcx4",
                "east" : __DIR__"bcx2",
        ]));

        set("objects", ([
		NPC_D("girl") : 1,
        ]));
        set("incity",1);
	setup();
}

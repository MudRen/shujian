// /d/xiangyang/bcx2.c ������
// Lklv 2001.9.22

inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
������������ͨ�����ŵ�һ��С���Ϊ�ش������Ǳ����������ǰ�����
�����������������С���Ͼ�Ŀ��ȥ�����������Ǹ�ʽ�����ĵ��̣�������
�����������֡�����ı�����һ���������ӣ������Ǹ�С�㳡���㳡��������
�У�ԶԶ��ȥ���Կ���һ����̨��
LONG
        );
        set("outdoors", "����");
        set("xyjob", 1);
        set("exits", ([
                "south" : __DIR__"guangc",
                "north" : __DIR__"zrdian",
                "west" : __DIR__"bcx3",
                "east" : __DIR__"bcx1",
        ]));

        set("objects", ([
		__DIR__"npc/wudunru" : 1,
        ]));
        set("incity",1);
	setup();
}

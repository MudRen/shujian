// /d/xiangyang/bcx1.c ������
// Lklv 2001.9.24

inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
������������ͨ�����ŵ�һ��С���Ϊ�ش������Ǳ����������ǰ�����
�����������������С���Ͼ�Ŀ��ȥ�����������Ǹ�ʽ�����ĵ��̣�������
�����������֡�
LONG
        );
        set("outdoors", "����");
        set("xyjob", 1);
        set("exits", ([
                "west" : __DIR__"bcx2",
                "east" : __DIR__"bjie1",
        ]));

        set("incity",1);
	setup();
}

// /d/xiangyang/xjie.c ����
// Lklv 2001.9.24

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���������������ڵ�һ���ֵ���·�ϵ����˺ܶࡣ��Ŀ��ȥ�����ԵĽ���
�ƺ����ܵͰ����ң������·����н��˿�ȥ��ȴ�·�һ��������ֱ��£���
�����������������ϣ������ܻ᲻ʱ����һ�����������ӵ�������
LONG
        );
        set("outdoors", "����");
        set("xyjob", 1);
        set("exits", ([
                "west" : __DIR__"bhmnj",
                "east" : __DIR__"cross1",
        ]));

        set("incity",1);
	setup();
}

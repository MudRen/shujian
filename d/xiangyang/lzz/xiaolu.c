// Room: xiaolu.c С·
// Looklove y2k/4/26

inherit ROOM;

void create()
{
        set("short","С·");
        set("long", @LONG
����ͨ���������һ��С·�����˲��Ǻܶࡣ·��ż���ܿ���������ѹ��
�ĺۼ���·���Գ����˵Ͱ��Ĺ�ľ�������ﲻʱ����һ������С�����������
�����������ˡ�
LONG
        );
        set("outdoors", "����");
        set("exits", ([
                "south" : "/d/xiangyang/xiaolu1",
                "north" : __DIR__"liuzz",
        ]));

	setup();
}

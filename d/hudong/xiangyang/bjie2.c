// /d/xiangyang/bjie2.c ����
// Lklv 2001.9.24

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
��������������ͨ�������ĵĽֵ���·��ܿ����������������ֵ�����
���������������֡�������һ�����ֺŵĲ�¥���ſڸ߸�Ʈ�ŶԻ��ӣ�¥����
�����ӣ��������ƺ����ⲻ�������������ĺ���������¥ȥ��
LONG
        );
        set("outdoors", "����");
        set("xyjob", 1);
        set("exits", ([
                "south" : __DIR__"bjie3",
                "north" : __DIR__"bjie1",
                "east" : __DIR__"chalou",
        ]));
        set("objects", ([
		CLASS_D("gaibang/yelvqi") : 1,
        ]));
        set("incity",1);
	setup();
}

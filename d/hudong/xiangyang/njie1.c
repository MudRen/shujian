// /d/xiangyang/njie1.c �Ͻ�
// Lklv 2001.9.24

inherit ROOM;
void create()
{
        set("short", "�Ͻ�");
        set("long", @LONG
����������������ͨ�����ŵ�һ����֣�·��ܿ����������������д�
�Ĵ��������˺ܶ࣬���ϵ���Ⱥ�У�ż�����Կ�����������Ӣ���Ĺ��Ӹ�����
���ű�������ҡ���С������жԺ�ľ���ţ���ǰ���Ұ���һ��ʯʨ�ӡ�������
�������õ����ڡ�
LONG
        );
        set("outdoors", "����");
        set("xyjob", 1);
        set("exits", ([
                "south" : __DIR__"njie2",
                "north" : __DIR__"xpailou",
                "west" : __DIR__"yamen",
                "east" : __DIR__"cross2",
        ]));

        set("incity",1);
	setup();
}

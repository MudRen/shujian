// room: /d/xingxiu/store.c
// Modify by Lklv 2001.10.16

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����������������, ����ά����������Ϊ����������������������
����Է��������챦������������Ʒ�Ȼ���಻ʤ��������������������
�ڵ��ϵ�̺���ϣ��Ա߶������Ļ���ǽ���и����ӣ��Ǹ���Ŀ��(sign)��
LONG);
	set("exits", ([
		"east" : __DIR__"yili2",
	]));
        set("objects", ([
		__DIR__"../npc/maimaiti": 1,
		__DIR__"../npc/shangren": 1
        ]));
        set("item_desc", ([
		"sign" : "������д������ԭǮ��ͨ�á�\n"
	]));
	setup();
}


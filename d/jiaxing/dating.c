// /d/jiaxing/dating.c ����

inherit ROOM;
void create()
{
        set("short", "����");
	set("long", @LONG
����½��ׯ�ڵ�һ�����������ڹ�ɫ���㣬���Ϸ�����ྫ���ĹŶ�����
���ǽ���Ϲ������ֻ���һ��ǽ���оŸ�Ѫ���ܵ���ӡ������ׯ��½�������
�������������ϣ�����Ѫ��ӡ�����س���
LONG
	);

	set("exits", ([
                "south" : __DIR__"houyuan",
                "east" : __DIR__"tianjing",
	]));

        set("objects", ([
                 __DIR__"npc/lu-liding" : 1,
        ]));
	setup();
}

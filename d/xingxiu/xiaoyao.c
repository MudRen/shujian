// Xiaoyao.c:  the sleeping room for Xingxiu
// Modify by Lklv 2001.10.16

inherit ROOM;

void create()
{
	set("short", "��ң��");
	set("long", @LONG
����������޵�������֮����ԭ��������һ�ֲڵ�ʯ�������������޵���
�������ɣ����˷�԰������������������ߡ���֪�ж��ٿ���������Ů�ڴ˶�
���˰������յ�����������(wall)����Щ�ּ���
LONG);

        set("no_get_from", 1);
        set("no_fight", "1");
        set("sleep_room", "1");

        set("exits", ([
                "out" : __DIR__"xx3",
        ]));

        set("item_desc", ([
		"wall" : "���������棡�������治�ú�����\n",
        ]));
        setup();
}

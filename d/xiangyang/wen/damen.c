// Room: damen.c
// Lklv Modify 2001.9.21

inherit ROOM;
void create()
{
	set("short", "�¸�����");
	set("long", @LONG
���ߵ�һ����լ��Ժ���ſڣ����ų������ſ�վ�������Ҷ���һ��������
���ǣ�һ��Ҫ�����鷳�����ӡ���ǰ����������ʯʨ�ӣ����弶��ʯ̨������
���ȶ���ͭ���Ĵ��š����ó������ǵ��ش����ס����
LONG
        );
        set("objects", ([
                __DIR__"npc/jiading":2,
        ]));

        set("exits", ([
                "south": __DIR__"shidetang",
                "north": "/d/xiangyang/ncx3",
        ]) );
	set("incity",1);
	setup();
}

// Write By Yanyang@SJ 2001.9.27
// Room: /d/changan/huadian.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǳ�����Ψһ�Ļ��ꡣ�߽�������粽���˻������磬�ӷ�������
�涼��������ɫ���ʻ������µĻ����������ԡ����и�������������Ŀ������
�������֡����Ͳ��ָߵ͹�����������������Ц����ӭ��
LONG
        );
        set("exits", ([
                "north"   : __DIR__"eastjie3",
        ]));
        set("objects", ([
                NPC_D("flowergirl") : 1,
        ]));
        set("incity",1);
	setup();
}

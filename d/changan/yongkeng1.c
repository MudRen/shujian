// Write By Yanyang@SJ 2001.10.3
// Room: /d/changan/yongkeng.c

inherit ROOM;

void create()
{
        set("short", "����ٸ��");
        set("long", @LONG
������һ���޴�ı���ٸ���У���ǧ���������ٸ���гɼ�ʮ·�ݶӣ���
����ٸ�����ٸ��ս��ٸ������ٸ������ٸ������ٸ������ٸ�ȵȣ�ٸ������
������������̬�����ɫ�������������·����ڴ�����˷���Х�������㲻��
�������ΰ�ĳ��澪����
LONG
        );
        set("exits", ([
                "south" : __DIR__"shihuangling",
        ]));

        setup();
}

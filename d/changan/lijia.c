// Write By Yanyang@SJ 2001.10.1
// Room: /d/changan/lijia.c

inherit ROOM;

void create()
{
        set("short", "��Ҵ�Ժ");
        set("long", @LONG
������ǳ������׸���Ա���˽լ��ӭ����һ����ɽˮ�أ����ϰ���һ��
���ι�״��ʯͷ����˵�ǵ��껨ʯ�ٵ���ʯ��ˮ�ص����������˻��ݡ�������
һ�û����������дУ��ڸ��˴���Ժ�ӡ�����Ժ�������������ġ������Ҷ�
����ʰ��Ժ�ӡ�
LONG
        );
        set("exits", ([
                "east"  : __DIR__"neijie7",
                "west"  : __DIR__"ljzhengting",
                "north" : __DIR__"ljzhangfang",
        ]));

        set("objects", ([
                __DIR__"npc/jiading" : 2,
        ]));

        set("incity",1);
	setup();
}

// Write By Yanyang@SJ 2001.10.1
// Room: /d/changan/jjfxf.c

inherit ROOM;

void create()
{
        set("short", "�᷿");
        set("long", @LONG
�����ǳ����ǽ������е��᷿����ר��Ϊ����׼���ġ��������ú�����
������һ��СС�辰�����ⰻȻ��ת�����磬ӭ��ֻ��һ��д��ɽˮ��������
�ᡣ�Ա߾�����齣�����ˮ��ɴ�ʣ�����Щ����
LONG
        );
        set("exits", ([
                "east" : __DIR__"jiangjunfu",
        ]));

        set("incity",1);
	setup();
}

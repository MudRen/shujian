// Write By Yanyang@SJ 2001.9.29
// Room: /d/changan/bingqipu.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����һ���ɳ��л����ھֿ���ı����̡����ﵽ�����������������ۻ���
�ҡ��������ϰ��Ÿ��ֱ�����ʮ�˰�������Ӧ�о��У�������ȫ����̨����վ
��һλ��̬�����׳������˵�����ھ������ֲ�����һλ��ʦ�����ڻ���һ��
��Ҫ���ڶ���ʧ�֣�������ͷ�ܻ����⵽���������˱�����
LONG
        );
        set("exits", ([
                "west" : __DIR__"southjie2",
        ]));

        set("objects", ([
                __DIR__"npc/daobazhang" : 1,
        ]));

        set("incity",1);
	setup();
}

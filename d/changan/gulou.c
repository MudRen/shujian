// Write By Yanyang@SJ 2001.9.20
// Room: /d/changan/gulou.c

inherit ROOM;

void create()
{
        set("short", "��¥");
        set("long", @LONG
�����ǳ����ǵĹ�¥��¥����һ��ģ����ı�ʱ���ʳƹ�¥���붫�Ϸ���
����¥ң���Ӧ������ĺ�ģ���ʾ��͡���ש���ߵĹ�¥���ܶ������ܶ����ʣ�
����΢�̣�����ׯ�ϣ������ܽ�����ӳ�����Ե�ʮ����ΰׯ�ϡ�
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "southeast": __DIR__"zhonglou",
                "south" : __DIR__"westjie1",
        ]));

        set("incity",1);
	setup();
}
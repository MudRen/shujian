// Write By Yanyang@SJ 2001.10.2
// Room: /d/changan/xiaoyanta3.c

inherit ROOM;

void create()
{
        set("short", "С��������");
        set("long", @LONG
С������һ�����͵�����ʽש�������������������ӵ������Ͽ�ȥ��ׯ��
�����磬�����ܽ��ܲ���һ����ʮ���֮�ߣ��붫�ߵĴ�����ңң����������
���վ������أ�������Щ�谵���ʡ�����ǽ��������յ��ƣ���Χ���в�ɫ��
����������¥�ݹ������£��������Ŵ�������ĿԶ����
LONG
        );
        set("exits", ([
                   "up"  : __DIR__"xiaoyanta4",
                   "down": __DIR__"xiaoyanta2",
        ]));

        set("incity",1);
	setup();
}
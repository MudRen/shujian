// Write By Yanyang@SJ 2001.10.2
// Room: /d/changan/xiaoyanta11.c

inherit ROOM;

void create()
{
        set("short", "С����ʮһ��");
        set("long", @LONG
С������һ�����͵�����ʽש�������������������ӵ������Ͽ�ȥ��ׯ��
�����磬�����ܽ��ܲ���һ����ʮ���֮�ߣ��붫�ߵĴ�����ңң����������
���վ������أ�������Щ�谵���ʡ�����ǽ��������յ��ƣ���Χ���в�ɫ��
����������¥�ݹ������£��������Ŵ�������ĿԶ����
LONG
        );
        set("exits", ([
                   "up"  : __DIR__"xiaoyanta12",
                   "down": __DIR__"xiaoyanta10",
        ]));

        set("incity",1);
	setup();
}
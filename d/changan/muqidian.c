// Write By Yanyang@SJ 2001.9.30
// Room: /d/changan/muqidian.c

inherit ROOM;

void create()
{
        set("short", "ľ����");
        set("long", @LONG
�����ǳ����ǵ�ľ���ꡣ�ϰ��Ǵ��Ϸ������ģ��ٻ��ܲ�����������
�Ⲣ���ܺá�������һյ��Ҳû�У�������ġ���������Ϊ���ⲻ����������
���ϰ徭��ȥ�ƹ����ƽ�������ȵ���������Ż�����
LONG
        );

        set("exits", ([
                "west" : __DIR__"northjie2",
        ]));

        setup();
}
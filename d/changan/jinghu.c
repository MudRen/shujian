// Write By Yanyang@SJ 2001.10.2
// Room: /d/changan/jinghu.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������ǳ����ǵľ����ˡ���������������Ǻܴ󣬵�̨ͤ¥�󣬼�ɽ��
��ȴҲ���еġ����������ؼ򵥣������ݻ�����ˮ�������˵��������˵ķ���
�������ƺ�����ʧ�ˡ�Ϧ������ʱ���е��������ǵ�����ɢ��������С��
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "east"   : __DIR__"southjie3",
                "west"   : __DIR__"jiashan",
        ]));

        set("incity",1);
	setup();
}
// Write By Yanyang@SJ 2001.9.29
// Room: /d/changan/houdian.c

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
�����������µĺ�����ľ�����϶����С��޷����򡱡��������޶ԡ���
���󱻲��������Ҷ���ڵĵ�����Ρ����ݻ���װ�ζ��ɰ��������׵���ɡ�
����Ͳ���߸Ƕ������Ͼ�Ϊ���񻨲����Ρ�
LONG
        );

        set("exits", ([
                "south" : __DIR__"dadian",
        ]));

        set("incity",1);
	setup();
}
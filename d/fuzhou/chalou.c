// Room: d/fuzhou/chalou.c
// Lklv 2001.9.8

inherit ROOM;

void create()
{
        set("short", "��¥");
        set("long", @LONG
���Ǹ��������һ�Ҳ�¥��ֻ�����ڼ��ų������ſ����Աߵ�����������
��ͣ������̸Ц����ͷ�Ӷ������Ը��صĿ���������һ��������������
���������֡�����Ʈɢ��һ�ɵ����Ĳ��㣬���Ÿ��������
LONG
        );
        set("resource/water", 1);

        set("exits", ([
                "east" : __DIR__"xixiang4",
                "up" : __DIR__"chalou2",
        ]));

        set("item_desc", ([
                "up" : "¥�ϵ��˺ܶ࣬�����￴�������\n"
        ]));
        set("objects", ([
                __DIR__"npc/chaboshi" : 1,
        ]));
	setup();
}

// Room: d/fuzhou/chalou2.c
// Lklv 2001.9.10

inherit ROOM;

void create()
{
        set("short", "��¥");
        set("long", @LONG
���ǲ�¥�Ķ�¥�����ڰ��ż��ų��������Աߵ��������˼�λ��ͣ����
��̸Ц����ͷ�Ӷ������Ը��صĿ���������һ���������������֡�����Ʈ
ɢ��һ�ɵ����Ĳ��㡣��������λ������������������λ˵��������
LONG
        );
        set("resource/water", 1);

        set("exits", ([
                "down" : __DIR__"chalou",
        ]));
        set("objects", ([
                "/d/city/npc/shuren" : 1,
        ]));
	setup();
}

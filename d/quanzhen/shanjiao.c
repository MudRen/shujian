inherit ROOM;

void create()
{
        set("short", "����ɽ��");
        set("long", @LONG
����������ɽ��ɽ�ţ�����ɽ�ų������ĵ�һɽ����ɽ��
����������������ơ������ɽ�ƻ���ƽ����һ��ʯ������ͨ
��ɽ�ϡ���ǰ��һ����ɽ����ͬ����һ���������գ����Թ�
�˵�ʫ�����С�����һ������˵����
LONG);
        set("outdoors", "quanzhen");
        set("exits", ([
                "northeast"    : "/d/gumu/shanlu1",
                "northup" : "d/quanzhen/shijie1",
        ]));
        set("objects",([
                __DIR__"npc/youke" : 1,
                __DIR__"npc/xiangke" : 2,
        ]));

        setup();
        replace_program(ROOM);
}

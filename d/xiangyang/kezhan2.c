// Room: /d/fuzhou/kezhan2.c ��ջ��¥

inherit ROOM;

void create()
{
        set("short", "��ջ��¥");
        set("long", @LONG
����һ��ܴ�Ŀͷ�������ʮ�ּ�ª����ǽ����ʮ����Сľ�������ٿ���
�����¶��ԣ������Ӷ��Ǻ����Ĵ������������Ŵ��ǿյģ���������ŵ���
�˹�ȥ��
LONG
        );
        set("xyjob", 1);
        set("sleep_room", 1);
        set("no_fight", 1);
        set("hotel",1);

        set("exits", ([
                "down" : __DIR__"jianghukz",
        ]));

        setup();
}
int valid_leave(object me, string dir)
{
        if ( dir == "down" ) me->delete_temp("rent_paid");
        return ::valid_leave(me, dir);
}

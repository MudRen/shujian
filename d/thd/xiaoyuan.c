// Room: /u/jpei/thd/xiaoyuan.c

inherit ROOM;

void create()
{
        set("short", "СԺ");
        set("long", @LONG
û���뵽���ﾹȻ������ô���ŵ�СԺ����ɽ���ȣ������辰����һ��
�Ƿ��õü�Ϊ���ʣ���Ȼ��������˷ǳ���Ϥ���ã�����ϵ��������������
����һ������������ͨ�������С��仯����֮��������һ��Сͤ�ӡ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "east" : __DIR__"bagua1",
                "west" : __DIR__"bagua0",
                "south" : __DIR__"taohua1",
                "north" : __DIR__"jicui",
        ]) );
        set("no_clean_up", 0);
        set("outdoors","�һ���");
        set("objects",([
                __DIR__"obj/shizi" : 1,
        ]));  

        setup();
}

int valid_leave(object me, string dir)
{
        if ((dir == "west" || dir == "east") && !me->query_temp("bagua_1") && me->query_skill("qimen-bagua", 1) < 90) 
                return notify_fail("��о�����һ����а��ذ��ԣ����������������������˻�����\n");
        
        return ::valid_leave(me, dir);
}


// Room: /u/jpei/thd/xiaoyuan.c
// Modified by Numa 19980830

inherit ROOM;

void create()
{
        set("short", "ɽ��");
/*        set("long", @LONG
û���뵽���ﾹȻ������ô���ŵ�СԺ����ɽ���ȣ������辰����һ��
�Ƿ��õü�Ϊ���ʣ���Ȼ��������˷ǳ���Ϥ���ã�����ϵ��������������
����һ������������ͨ�������С��仯����֮��������һ��Сͤ�ӡ�
LONG
        );*/
        set("long",@LONG
������һ����ͺͺ��ɽ�ԣ���ʯ���������ƺ�ÿһ��ʯͷ�����˾��Ĳ��ù�
�Ƶģ��Ͷ���������������һ��������һ�����壬������ϵ�������ͨ��
�����С��仯����֮��������һƬ�ݵء�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "east" : __DIR__"bagua1",
                "west" : __DIR__"bagua0",
                "south" : __DIR__"taohua1",
                "north" : __DIR__"caodi",
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
        object *ob, *deep_ob;
        int i, j, drop_flag;

        if (dir == "west" || dir == "east") {
                if (!me->query_temp("bagua_1") && me->query_skill("qimen-bagua", 1) < 90)
                        return notify_fail("��о�����һ����а��ذ��ԣ����������������������˻�����\n");
                ob = all_inventory(me);
                drop_flag = 0;
                for(i = 0; i < sizeof(ob); i++) {
                        if (userp(ob[i])) {
                                if (!drop_flag) {
                                        message_vision("$N���˿���ǰ��������ޱȵİ����󣬾������°�������װ����\n", me);
                                        drop_flag = 1;
                                }
                                message_vision("$N��$n�ӱ��Ϸ������������ڵ��ϡ�\n", me, ob[i]);
                                ob[i]->move(this_object());
                        }
                        else {
                                deep_ob = deep_inventory(ob[i]);
                                for(j = 0; j < sizeof(deep_ob); j++) {
                                        if (userp(deep_ob[j])) {
                                                if (!drop_flag) {
                                                        message_vision("$N���˿���ǰ��������ޱȵİ����󣬾������°�������װ����\n", me);
                                                        drop_flag = 1;
                                                }
                                                message_vision(sprintf("$N����һ%s$n��\n", ob[i]->query("unit")), me, ob[i]);
                                                ob[i]->move(this_object());
                                                break;
                                        }
                                }
                        }
                }
        }

        return ::valid_leave(me, dir);
}

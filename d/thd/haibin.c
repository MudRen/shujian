// Room: /u/jpei/thd/haibin.c
// Modified by Numa 19990906

#include <ansi.h>

inherit ROOM;

int do_jump(string arg);
int do_look(string arg);
int do_use(string arg);
int prevent_get();

void create()
{
        set("short", "����");
        set("long", @LONG
������Ǯ�������뺣�ڡ�������ӿ��������Ϣ������(tide)���ϵ������
�������ڰ��ߣ������ˮ���ڰ�շ��裬�����ѩ�׷�һ����
LONG
        );
        set("no_clean_up", 0);
        set("outdoors","ţ�Ҵ�");

        set("exits", ([
        "west": __DIR__"niujia/jiangpan3",
        ]) );

        set("item_desc", ([
                "tide" : "���������������ƺ����������û��\n",
        ]) );   

        setup();
}

void init()
{
        add_action("do_jump", ({"jump", "tiao"}));
        add_action("do_use", "use");
        add_action("do_look", "look");
        add_action("prevent_get", "get");
}

int do_use(string arg)
{
        object me = this_player();
        object *ob;
        int i;
        ob = all_inventory(me);
	if (me->query_condition("killer"))
		return notify_fail("�㻹���˽��꽭����Թ��˵�ɡ�\n");
        if (me->is_busy()) return notify_fail("����æ���أ�\n");
        for(i = 0; i < sizeof(ob); i++) {
               if (userp(ob[i])) {
                     return notify_fail("������С���������Ϊ�������޷�ƽ�⣬��ˤ�ذ��ϡ�\n"); }
        }
        if ((arg == "boat" || arg == "chuan") && me->query_temp("thd_boat")) {
                me->delete_temp("thd_boat");
                write("������С�������������һ�����\n");
//                write("��������˳�磬������ƣ������ڱ㵽���ˡ�\n");
                call_out("do_arrive",4,me);
                return 1;
        }
        return 0;
}

void do_arrive(object me)
{
        if (!me) return;
        message_vision("���������������ŵ������м����˱ǻ��㡣\n",me);
        message_vision(HIW"��ԶԶ��ȥ�����������дУ�һ���̡�һ�ź졢һ�Żơ�һ���ϣ��˵��Ƿ����ƽ���\n"NOR, me);
        message_vision("�����ۡ���һ��ײ���˰��ߣ��㼱æ���������˰���\n",me);
        me->move(__DIR__"shore");
        tell_room(environment(me), "һ�Һ���ͣ��������" + me->query("name") + "���������������ڰ��ϡ�\n", ({me}));
}
        
int do_jump(string arg)
{
        object me = this_player();

        if (me->is_busy()) return notify_fail("����æ���أ�\n");
        if (arg == "boat" || arg == "chuan")
                return do_use(arg);

        if (arg != "chao" && arg != "tide")
                return notify_fail("��Ҫ����������\n");

           if (me->query_dex() < 99)
                return notify_fail("����ͼ���������ȴ�ܾ����������ġ�\n");
        if (me->query_skill("dodge") < 80)
                return notify_fail("����ͼ���������ȴ�����Լ����Ṧ��Ϊ��û�дﵽ��ô�ߵľ��硣\n");
        message_vision("$N����һԾ�������˺����У�\n", me);
//        me->move(__DIR__"niujia/tide");
        return 1;
}

int do_look(string arg)
{
        object me = this_player();

        if (me->query("family/family_name") != "�һ���" && me->query_skill("qimen-bagua", 1) < 50) {
                set("long", @LONG
������Ǯ�������뺣�ڡ�������ӿ��������Ϣ������(tide)���ϵ������
�������ڰ��ߣ������ˮ���ڰ�շ��裬�����ѩ�׷�һ����
LONG
);
                me->look(arg);
        }
        else {
                if (!arg) {
                        set("long", @LONG
������Ǯ�������뺣�ڡ�������ӿ��������Ϣ������(tide)���ϵ������
�������ڰ��ߣ������ˮ���ڰ�շ��裬�����ѩ�׷�һ����Զ����һ�����
(rock)�������ƺ�������ʲô��
LONG
);
                        me->look(arg);
                }
                else if (arg == "rock" || arg == "yanshi" || arg == "juyan") {
                        write("һ����ң�������Լ¶��һ����(boat)�Ĵ�������\n");
                        me->set_temp("thd_boat", 1);
                        return 1;
                }
                else if ((arg == "boat" || arg == "chuan") && me->query_temp("thd_boat")) {
                        write("һ�����ŵ�С��������ͨ���Ű����Ǻ��ѷ��ֵġ�\n");
                        return 1;
                }
        }
}

int prevent_get()
{
     write("�����Ц�ˡ�\n");
     return 1;
}

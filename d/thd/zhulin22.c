// ROOM : /u/numa/thd/zhulin1.c
// Created by Numa 19990828

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������һƬ�����де������֣����ƺ���ʧ�˷�����ûͷ��Ӭ�㵽���Ҵ���
LONG
        );
        set("exits", ([
                "south" :  __DIR__"zhulin23",
                "north" : __DIR__"zhulin"+(random(5)+20),
                "west" : __DIR__"zhulin"+(random(5)+20),
                "east" : __DIR__"zhulin"+(random(5)+20),
        ]));
        set("outdoors", "�һ���");

        setup();
}

void init()
{
        object ob=this_player();

        if (ob->query_skill("qimen-bagua", 1) > 80)
        {
                write("������ƽʱ��������Щ���׵��󷨣����Բ���ϸ�룬�Ų����߳������֣�\n");
                ob->move(__DIR__"caodi", 1);
                tell_room(environment(ob), "����ͻȻһ��������" + ob->name() + "�������˳�����\n", ({ob}));
                return;
        }
        if (ob->query_temp("step_count") > 99) {
                ob->delete_temp("step_count");
                write("�����������۵þ�ƣ����������������֧�����˹�ȥ��\n");
                write("���Ժ������ƺ����˰���̧�������֣��·��и����ϵ������ȵ������ӵ�����ȥ����\n");
                ob->unconcious();
                ob->move(__DIR__"haibin", 1);
                message("vision", "��Ȼһ����ӿ�˹�������һ����ˮ�ݵð����ļһ�嵽�˰��ߡ�\n", environment(ob), ob);
                return;
        }
        ob->add_temp("step_count", 1);
}


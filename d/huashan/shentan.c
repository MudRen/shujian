// Room: /d/huashan/shentan.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
���ǻ�ɽ���һ��ɽ�����Ա������������ɽȪ�������³���γɵ�һ��
�����ˮ̶��������Χ�����˹�ľ�������ķ����ƺ����߹�ȥ��
LONG    );
        set("exits", ([ 
        "northeast" :   __DIR__"v-road-1"
        ]));
        set("outdoors", "��ɽ");
        set("coor/x",30);
  set("coor/y",70);
   set("coor/z",-10);
   setup();
}

//int init()
//{
//        add_action("do_jump","jump");
//}


int do_jump(string arg)
{
        object me = this_player();
        int add_neili = me->query("neili");
        if ( arg != "up") return 0;
        if ( add_neili < 300 )
        {
                write("�����������һ����������������������һԾ�������ڿ쵽�������ʱ���ֵ���������\n");
                add_neili = 0 - add_neili;
                me->add("neili",  add_neili);
                return 1;
        }
        me->add("neili", -300);
        tell_object(me, "�����������һ����������������������һԾ���ɹ�������������\n");
        message("vision", "ֻ��" + me->query("name") + "��������һԾ���·������ȥ��\n", environment(me), me);
        me->move(__DIR__"pubu");
        return 1;
}

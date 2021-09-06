// Code of ShenZhou
// road: /zhongnan/milin4.c

inherit ROOM;

void create()
{

        set("short","����");

        set("long",@LONG
�������У���ֻ����������һ�ɵ������̣����ż���Ļ��㣬����
���������һȺ���ɫ���۷��������Է�����ȥ���������Ĩ��߾���ï
�ܵ����֡�������һ�Ż���(flowers)��
LONG);

        set("item_desc",([
                "flowers" : "�⻨�Լ������ܣ������ȥ�����������ף�������Щ��϶���ƺ�������Щ�����ڴ���������ȥ��\n",
        ]));

        set("exits",([ 
                "west" : __DIR__"shulin6",
        ]));

        set("cost",2);
        set("outdoors", "quanzhen");
        setup();

}

void init()
{               
        add_action("do_push", "push");
        add_action("do_push", "tui");
        add_action("do_push", "zuan");
}

int do_push(){

        object room;
        object me=this_player();
        
        if (me->is_busy())
                return notify_fail("��������æ���ģ�\n");

        if (this_object()->query("hide_person"))
                return notify_fail("�㿴��������Ӱ�ӻζ������ǲ���ĺã�����ʲô���ޡ�\n");

        tell_object(me, "��������ƿ���ľ���������˽�ȥ��\n");
        
        room = load_object("/d/quanzhen/flowers");
        
        this_object()->set("hide_person",1);
        
        me->move(room);
        return 1;

}

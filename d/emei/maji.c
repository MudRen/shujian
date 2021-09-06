// Room: /d/emei/maji.c

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
����һ����ǣ����깩Ӧ���ʲ��ϡ��˵���紾�ӣ�����ǰ���ǣ�����
�����տ���������ι�����㣬��ϴˢ�ø�Ǭ������һֱ�ź򵽿��������·��
����жѷ������Ѳ��ϣ�������һ�����(gancao)��
LONG
        );
        set("outdoors", "��üɽ");
        set("item_desc", ([ 
            "gancao" : "    ����һ����ۣ�����ʹ�㾢���԰�(move)����\n",
]));
        set("exits", ([
  "south" : __DIR__"huayanding",
]));
//        set("no_clean_up", 0);

        setup();
}

void init()
{
    add_action("do_xian", ({"xian", "move"}));
    add_action("do_zuan", ({"zuan", "enter"}));
}             

int do_xian(string arg)
{
    object me = this_player();
    if (me->query_temp("marks/zuan"))
	return notify_fail("��Ա��˳ŵģ���۲����ƿ�����\n");
    if (!arg) return 0;
    if (arg != "���" && arg != "gancao" )
	return 0;
    message_vision("$N�ƿ�����ۣ�Ū�ñ����ˮ��\n", me);
    tell_object(me, "�㷢�����������һ�����ڿ������ȥ��\n");
    me->set_temp("marks/zuan", 1);
    return 1;
}

int do_zuan(string arg)
{
    object me = this_player();
    if (!arg) return 0;
    if ( arg != "hole" && arg != "��" && arg != "dong" && arg != "����" && arg != "dongkou")
	return 0;
    if (!me->query_temp("marks/zuan"))
	return 0;
    message_vision("$Nһͷ�������۵Ķ��ڡ�\n", me);
    me->delete_temp("marks/zuan");
    me->move(__DIR__"houshanxl");
    return 1;
}


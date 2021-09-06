// Room: /d/tianshan/jiashan.c
// By Linux

inherit ROOM;

void create()
{
	set("short", "��ɽ");
	set("long", @LONG
�����Ƕ�ˮ�ž�ͷ�ļ�ɽ�����ܵ�Ұ��Ұ���ں��������ɳ�������������
ɢ��������Ķ��ص�ζ�����㿴�ſ��ţ�Խ������ط��ĹŹ֡���ʲôԭ����
��˵��������
LONG);
	 set("exits", ([
                "west" : __DIR__"dsqiao",
        ]));       
	set("outdoors", "��ɽ");
	setup();
}

void init()
{
	add_action("do_push", ({"push", "tui"}));             
}

int do_push(string arg)
{
        int str;
        object me;
        str = this_player()->query_str();
        me = this_player();

	if( !arg ) return 0;
	if (arg == "jiashan" ) {
		if(me->query("tonglao/ok")) {
			message_vision("$N�������ӣ��ó��̵������Ѽ�ɽŲ��,ֻ������¶��һ���󶴡�\n", me);
			message_vision("��ɽ��ͻȻ¶��һ���󶴣�$Nһû������˽�ȥ����ɽͻȻ�ֻص���ԭ�������ӡ�\n", me);
			me->add("neili", -100);
			me->add("jingli", -50);
			me->move(__DIR__"shiku");
			return 1;
		}
		if (str < 21 )
			return notify_fail("��ʹ���˳��̵��������ɾ����Ʋ�����ɽ��\n");
		if (str > 20){  
			message_vision("$Nʹ��ȫ�����������ɽ���ɼ�ɽ�������˸��Ƶģ�˿��������\n", me);
			me->add("neili", -300);
			me->add("jingli", -200);
			return 1;
		}       
	}
	return 1;        
}

// /d/mingjiao/bidao4.c
// Jay 4/3/97 -qingyun
// Modify By River@SJ 99.06


inherit ROOM;
void check_trigger();
void close_passage();

void create()
{
        set("short","�ص�");
        set("long", @LONG
�����Ѿ����ص��ľ�ͷ��խխ�ģ�ֻ������һ�����Ͽ���һ�ھ�������
����ʯ��(wall)�������������ϵ��ص������ӳ��ڡ�
LONG
     );

	set("exits", ([
		"south" : __DIR__"bidao3",
                "westup"  : __DIR__"bidao17",
	]));
       	set("item_desc", ([
               "wall" : "���ܽ�Ϊʯ�ڣ���ż���м����ɶ�֮�����ƺ������ƶ�����\n"
        ]));

        setup();
}

void check_trigger()
{
	if( (int)query("right_trigger")==2){
		message("vision", "\nʯ�ڻ����˺�ȴ��һ�¼��񣬼��ޣ����ؼ�ʵ��ʯ�š�\n", this_object());
		set("exits/enter", __DIR__"bidao5");
		delete("right_trigger");
		remove_call_out("close_passage");
		call_out("close_passage", 10);
        }
}

void close_passage()
{
        if( !query("exits/enter") ) return;
        message("vision", "\nʯ�ŷ�������������������ڴ���ס�ˡ�\n", this_object());
        delete("exits/enter");
}

void init()
{
	add_action("do_push",({"push", "tui"}));
}

int do_push(string arg)
{
	object me = this_player();

	if (!arg || arg=="" ) return 0;
	if (me->query_skill("force", 1) < 120)
		return notify_fail("����������˿������������ƣ���������������ȷʵ�Ʋ�����\n");
	if (arg=="wall")
		return notify_fail("������һ��������������ʯ��һ�ƣ�������춯����\n");
	if (arg=="ʯ��")
		return notify_fail("������һ��������������ʯ��һ�ƣ�������춯����\n");
	if (arg=="wall left")
		return notify_fail("������һ��������������ʯ������һ�ƣ�������춯����\n");
	if (arg=="wall right"){
		message_vision("$N���˿�������ʯ�������ƣ�ʯ�ڶ��˶������ƻ�ԭλ��\n",me);
		add("right_trigger", 1);
    		check_trigger();
		return 1;
	}else{
	     write("��Ҫ��ʯ�������Ǹ�����\n");
             return 1;
        }
}

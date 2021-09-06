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
�����Ѿ����ص�����һ�ߣ�խխ�ģ�ֻ������һ�����Ͽ���һ�ھ�����
�ܶ���ʯ��(wall)���򱱲�֪����ͨ�����
LONG
     );

	set("exits", ([
		"northdown" : __DIR__"bidao6",
	]));
       	set("item_desc", ([
               "wall" : "���ܶ���ʯ�ڣ���ż���м����ɶ�֮�����ƺ�����������\n"
        ]));
        setup();
}

void check_trigger()
{
	if((int)query("left_trigger")==2){
		message("vision", "\nʯ�ڻ�����ǰ��ȴ��һ�¼��񣬼��ޣ����ؼ�ʵ��ʯ�š�\n", this_object() );
		set("exits/out", __DIR__"bidao4");
		delete("left_trigger");
		remove_call_out("close_passage");
		call_out("close_passage", 10);
	}
}

void close_passage()
{
	if( !query("exits/out")) return;
	message("vision", "\nʯ�ŷ��������������������ڴ���ס�ˡ�\n", this_object() );
	delete("exits/out");
}

void init()
{
	add_action("do_pull",({"pull", "la"}));
}

int do_pull(string arg)
{
	object me = this_player();

	if (!arg || arg=="") return 0;
	if ( me->query_skill("force", 1) < 120 )
		return notify_fail("����������˿������������ƣ���������������ȷʵ�Ʋ�����\n");
	if (arg=="wall")
		return notify_fail("������һ��������������ʯ��һ����������춯����\n");
	if (arg=="ʯ��")
		return notify_fail("������һ��������������ʯ��һ����������춯����\n");
        if (arg=="wall right")
		return notify_fail("������һ��������������ʯ������һ����������춯����\n");
        if (arg=="wall left"){
		message_vision("$N���˿�������ʯ����������ʯ�ڶ��˶������ƻ�ԭλ��\n", me);
		add("left_trigger", 1);
    		check_trigger();
		return 1;
	}
        else{
              write("��Ҫ��ʯ�������Ǹ�����\n");
              return 1;
        }
}

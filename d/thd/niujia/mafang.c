// mafang.c

inherit ROOM;

string look_daocao();

void create()
{
	set("short", "��");
	set("long", @LONG
���������ļҵĺ�Ժ���������ǰ���и��ܴ��ˮ�ס�
�����߶����˺ܶൾ�ݣ�ƽʱ�ѵĺ����룬���첻֪����
ô�ˣ�����(Daocao)�ѵ����߰���ġ�
LONG
	);

	set("exits", ([
		"south" : __DIR__"houyuan.c",
	]));
            set("objects",([
              // __DIR__"npc/wanyan": 1,
               	
            ]));
            
       set("item_desc",([
		"daocao"		:	(: look_daocao :),
	]));
		set_temp("available",1);
	setup();
}

void init()
{
	add_action("do_move", "move");
}

int do_move(string arg)
{
//	string dir;
	object me,ob;

	if( !arg || arg=="" || !query_temp("available") ) return 0;

	if( arg=="daocao" && query_temp("available")) {
		write("�������ѵ��������ƿ���ͻȻ�����������Ÿ��������˵����� !\n\n");
	        delete_temp("available");
	}


	me = new(__DIR__"npc/wanyan",1);
	me->move(__DIR__"mafang");

	ob = this_player();	

	me->unconcious();

	remove_call_out("fainting");
	call_out("fainting", 100, me, ob);

	return 1;
}

void fainting(object me, object ob)
{

		message_vision("���պ��һ��������˹�����˵��: �ȡ����ҡ���\n",ob);
		me->dest(ob);
	

	return;
}

string look_daocao()
{
	return "����һ��ѵ��ݣ�����ǽ�űߣ���֪����ʲ���ó���\n";
}


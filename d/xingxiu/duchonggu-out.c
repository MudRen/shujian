//caiji@SJ 8/24/2000

inherit ROOM;

void create ()
{
	set ("short", "�����");
	set ("long", @LONG
һƬƽ̹�ȵأ������Ǵ�ɽ���ơ������������ģ�����ʮ�ֲֿ�������
�������𣬸��ֶ���������������¶��ǳ��긯�ݰ�Ҷ�óɵ����ࡣ����
��ɽ��ͨ���йν����������㼡���������ۡ�
LONG);

	set("exits", 
	([
		"northwest" : __DIR__"duchonggu"+random(5)*10,
	]));
	
	set("outdoors", "xingxiuhai");
	set("coor/x",-290);
        set("coor/y",190);
        set("coor/z",0);
	setup();
}

void init()
{
	add_action("do_yell", "yell");
	add_action("do_yell", "han");
}

int do_yell(string arg)
{
	object me;
	
	me=this_player();

	if( !arg || (arg != "�����" && arg != "open" && arg != "�쿪��" && arg != "����"&&arg!="����"&&arg!="close") )
		return notify_fail("��Ҫ��ʲô��\n");       

	if(arg == "open" || arg == "�쿪��" || arg == "����")call_out("open_out", 1);
	else call_out("close_out",1);
	return 1; 
}

void open_out()
{
	object uproom; 

	if( uproom = find_object(__DIR__"rukou") ) 
	{
		set("exits/south", __DIR__"rukou");
		uproom->set("exits/north", __FILE__);
		message("vision", "���ŷ��������������������򿪣������ڿ��Խ�ȥ�ˡ�\n", uproom );
		message("vision", "���ŷ��������������������򿪣������ڿ��Գ�ȥ�ˡ�\n", this_object() );
	}

	call_out("close_out", 20);
}

void close_out()
{
	object uproom;

	if( !query("exits/south") ) return;

	message("vision", "���ŷ��������������������ֹ����ˡ�\n", this_object() );

	if( uproom = find_object(__DIR__"rukou") ) 
	{
		message("vision", "���ŷ��������������������ֹ����ˡ�\n", uproom );
		uproom->delete("exits/north");
	}

	delete("exits/south");
}

int valid_leave(object me, string dir)
{
	int time;
	if(dir == "northwest"){

        if (me->query("combat_exp")<3000)
        return notify_fail("������̫Σ�գ��㻹�ǲ�Ҫ��ȥ�ˡ�\n");
        
        time = 10+random(10);
        me->apply_condition("xx_catch",time);
        me->set_temp("xx/catch_time",time);
        me->delete_temp("xx_zuji");
        }
//      if(dir == "south")
//	me->clear_condition("xx_catch");

        return ::valid_leave(me, dir);
}
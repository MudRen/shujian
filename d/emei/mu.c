// mu.c 
// ����Ĺ

inherit ROOM;
#include <ansi.h>
void check_trigger(object);
void close_passage(object);
void reset();
int do_dig(string arg);
void create()
{
	set("short", "����֮Ĺ");
	set("long",@long
������һ����ģ�����Ĺ��Ĺ���Ͽ��ż������֣���������ʦ����֮Ĺ��
ԭ�����Ƕ����ɴ�����ʦ�����Ĺ����Ů�����Ǵ���������СŮ����������
�ڶ���ɽ���ӣ������˶����ɣ�������ҵ��ӽ��������ڴ˴��������ļ���
���������ʻ�ʢ����ʮ���ľ���
long);
	set("outdoors", "��üɽ");
	set("exits",([
		"south" : __DIR__"caodi",
		"east" : __DIR__"xiaojing2",
	]));
	set("objects", ([
		__DIR__"npc/shanyang" : 1,
	]));
	setup();
}

void init()
{
	add_action("do_wa", "wa");
}

void check_trigger(object me)
{
	object room;
	if( (int)query("dig_trigger")==15
	 && !query("exits/down")) {
		message("vision", "Ĺ�����汻�򿪸��󶴣���ǰ������һ��ʯ�š�\n", this_object() );
		set("exits/down", __DIR__"mu2");
		if( room = find_object(__DIR__"mu2") ) {
			room->set("exits/up", __FILE__);
			message("vision", "Ĺ�Ѿ����ˣ�һ����ʯ�ź��ڵ��ϡ�\n",room );
		}
		delete("dig_trigger");
		remove_call_out("close_passage");
		call_out("close_passage", 20, me);
	}
}

void close_passage(object me)
{
	object room;
	if( !query("exits/down") ) return;
	message("vision", "��Ȼ�����Ե����������������Ѿ򿪵�ʯ�Ÿ���ס�ˡ�\n", this_object() );
	if( room = find_object(__DIR__"mu2") ) {
		room->delete("exits/up");
		message("vision", "��Ȼ�����Ե����������������Ѿ򿪵�ʯ�Ÿ���ס�ˡ�\n", room );
	}
	delete("exits/down");
	me->delete_temp("dig_mu");
}

int do_wa(string arg)
{
	object me, ob;
	me = this_player();

	if(! (me->query_temp("sao_mu")))
		return notify_fail("��Ҫ��ʲô��\n");

        if (me->is_busy() || me->is_fighting())
        	return notify_fail("����æ���ģ�\n");

	if(!(present("tie qiao", me)))
		return notify_fail("��Ҫ��ʲô��\n");

	if( !arg || arg == "" || arg != "mu")
		return notify_fail("��Ҫ��ʲô��\n");
	
	if( arg == "mu" ) {
		if( (int)me->query_temp("dig_mu", 1) == 1 ) {
			if(! present("shoumu dizi", environment(me))) {
				ob=new("/d/emei/npc/shoumu");
				message_vision(HIC"��Ȼ��һ������Ů���ɲ�������������������󵨵���������һ����\n", me);
				message_vision(HIC"��һ��������ɱ��������ɱ����ڣ�\n"NOR, me);
				ob->move(this_object());  
			}
		} 
		message_vision("$N�����������£��ԳԿԳԵ�����Ĺ����\n", me);
		me->add_busy(1);
		me->add_temp("dig_mu", 1);
		add("dig_trigger", 1);
		check_trigger(me);
		return 1; 
	}
}

void reset()
{
	::reset();
	delete("dig_trigger");
}

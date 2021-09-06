// /d/hmy/zhulou.c

#define SHIP __DIR__"zhulou"

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "��¨");
	set("long", @LONG
������¨���У��ۼ����̱��������Ʈ������ͷ���ľ������ȥ��������
��������¥����ҫ�۵Ĺ�â��
LONG
	);
        set("no_fight", "1");
        set("no_sleep_room", 1); 
        set("side", "ryping");

	set("outdoors", "��ľ��");
	setup();
}

int arrive(string arg)
{
	object room, ob;
     
	ob = this_object();

	if(!ob->query("start")) ob->set("start", 1);
	if(!(string)ob->query("side")) set("side", "yading");
	if(stringp(arg)) set("side", arg);
	if(!(room = find_object(__DIR__+ob->query("side"))))
		room = load_object(__DIR__+ob->query("side"));
	if(room = find_object(__DIR__+ob->query("side"))){
		ob->set("exits/out", __DIR__+ob->query("side"));
		room->set("exits/enter", SHIP);
		message("vision", "\n��¨���˼��£���һ��ʯ��֮��ͣ��������\n", ob);        
		message("vision", "\nһ������¨�����ؽ���������ͣ�������ǰ������������Կ����¨(enter)��\n", room);
		remove_call_out("on_board");
		call_out("on_board", 20);
	}
	return 1;
}

void flying1()
{
	object room;

	if( room = find_object(__DIR__"zhulou")) {
		if( this_object()->query("side") == "yading")
			message("vision", HIC"\n��ҹ֮�У��Կɼ���һƬƬ���ƴ�ͷ��Ʈ����\n"
					HIB"\n�ٹ�һ�ᣬ������������¨�ף������ڳ�����һƬ�����ƻ�Ҳ�������ˡ���\n"NOR,room);
		else
			message("vision", HIY"\n��¨�����½�����ͷ������ͷ��������ǣ�ң���ɼ���\n"NOR,room);
	}
    	remove_call_out("arrive");
    	call_out("arrive", 10+random(10));
}

void flying()
{
	object room;
    
	if( room = find_object(__DIR__"zhulou")) {
		if( this_object()->query("side") == "yading")
			message("vision", HIY"\n��¨������������ͷ������ͷ��������ǣ�ң���ɼ���\n"NOR,room);
		else
			message("vision", HIC"\n��ҹ֮�У��Կɼ���һƬƬ���ƴ�ͷ��Ʈ����\n"
					HIB"\n�ٹ�һ�ᣬ������������¨�ף������ڳ�����һƬ�����ƻ�Ҳ�������ˡ���\n"NOR,room);
	}
	remove_call_out("flying1");
	call_out("flying1", 10+random(10));
}

void on_board()
{
	object room, *obj, ob;
	int i;
        
	ob = this_object();
        
	if( !query("exits/out") ) return;

	if( room = find_object(__DIR__+ob->query("side")) ){
		obj = all_inventory(ob);
		for(i = 0; i < sizeof(obj); i++) {
			if (userp(obj[i]) && obj[i]->query_temp("side") != ob->query("side")) {
				if (!living(obj[i])) message_vision("���ڰ�$Ņ������¨��\n", obj[i]);
				obj[i]->move(room);
				obj[i]->delete_temp("side");
				if (!living(obj[i])) tell_room(room, obj[i]->name() + "��̧������¨��\n", ({obj[i]}));
				else tell_room(room, obj[i]->name() + "�������¨��\n", ({obj[i]}));
			}
		}
		room->delete("exits/enter");
		message("vision", "\nͭ�����죬�¶��Ľ��̿�ʼת������¨�����ƶ���\n", this_object());
		message("vision", "\n���½��ں���һ��������ඡ������̿�ʼת������¨�����ƶ���\n", room);
	}
	delete("exits/out");
	if(ob->query("side") == "yading") ob->set("side", "ryping");
	else ob->set("side", "yading");
	remove_call_out("flying");
	call_out("flying", 10+random(10));
}

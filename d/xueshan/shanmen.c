// Room: shanmen.c

inherit ROOM;
#include <wanted.h>
#include <ansi.h>

void create()
{
	set("short", "������ɽ��");
	set("long", @LONG
���ݾ��������ߴ����Ľ������������Ƕͭ���Ĵ���(gate)�����ϵİ�
��ͭ���������������ġ���Լʮ���ɵ���¥��ɽ�������Ϊ�������ɣ����о�
���ĸ����м���Һڵ׽�������
                        ������������������
                        ��  ��  ��  ��  ��
                        ������������������                
�����֣��Ե����ɷǷ��������Ը���һֻ�������š�Զ����Լ����ɽ����
��������ֻ��ѻ�����Ҽ�׷ɣ������������׵ĸо���
LONG
	);

	set("exits", ([
		"southeast" : __DIR__"shanlu7",
	]));
        set("item_desc", ([
                "gate": "һ�Ⱥ������������������������ҫ�¸���ҫ�ۡ��ƺ�����(knock)���š�\n",
                "��": "һ�Ⱥ������������������������ҫ�¸���ҫ�ۡ��ƺ�����(knock)���š�\n",
        ]) );

        set("outdoors", "ѩɽ");

	set("coor/x",-280);
  set("coor/y",170);
   set("coor/z",30);
   setup();	

}
void init()
{
       	add_action("do_knock", "knock");
}

void wantopen(object me)
{
	object	waiter;
	object	room;

	seteuid(geteuid());
	room = find_object(__DIR__"guangchang");
	waiter = new(__DIR__"npc/fanseng");
	message_vision(HIY"֨��һ���������￪�ˡ�\n\n"NOR,me);
       	message_vision(HIY+waiter->query("name")+ "���˳�����\n"NOR,me);
	if( room )  tell_room(room,HIY+waiter->query("name")+"��æ��ǰ֨��һ�����Ŵ򿪣�ӭ�˳�ȥ��\n"NOR);
	waiter->move(this_object());
	message_vision(HIY+waiter->query("name")+"˵������λ"+RANK_D->query_respect(me) + "���ٴ�����,���������\n"NOR,me);
	call_out("closedoor", 10, me);
}



int do_knock(string arg)
{
	object room, me, troom ,obj;
	troom = this_object();
	obj = present("hufa lama", troom);
	me = this_player();        

	if( arg=="gate" || arg == "��") {
		if(query("exits/northup")) {
		if(obj) {
			message_vision(HIY+obj->query("name")+"������һ�۵��������Ѿ������㻹�ã�\n"NOR, me);
			return 1;
		}
		else {	message_vision(HIY"��ͻȻ����ԭ�����ǿ��ŵģ�ֱ�ӽ�ȥ�����ˡ�\n"NOR, me);
			return 1;
		}
	}
		message_vision(HIY "$N�ߵ���ǰ������ؿ��������Ż���\n" NOR, me);
		set("long", @LONG
���ݾ��������ߴ�����ɽ�ţ�һ�����Ƕͭ���Ĵ��ų����ţ����ϵİ�
��ͭ���������������ġ���Լʮ���ɵ���¥��ɽ�������Ϊ�������ɣ����о�
���ĸ����м�����Ͻ�����


                        ������������������
                        ��  ��  ��  ��  ��
                        ������������������                

�����֣��Ե����ɷǷ��������Ը���һֻ�������š�Զ����Լ����ɽ����
��������ֻ��ѻ�����Ҽ�׷ɣ������������׵ĸо���
LONG
	);
		set("exits/northup", __DIR__"guangchang");
	        if( room = find_object(__DIR__"guangchang") ) {
			tell_room(room,HIY "�����������������������������š�\n" NOR);
			room->set("exits/southdown", __FILE__);
			room->set("item_desc", ([
                		"gate": "���Ⱥ���Ĵ��������೨���š�\n",
                		"��": "���Ⱥ���Ĵ��������೨���š�\n",
        		]) );
		}
		me->start_busy(1);
		call_out("wantopen", 2, me);
		
        }
	else {
		write("��Ҫ��ʲô��\n");
	}
                return 1;
}

void closedoor(object me)
{
	object obj, room, troom;

	troom = this_object();
if(!me) return;
	if(environment(me) != troom) {
	        room = find_object(__DIR__"guangchang");
		obj = present("hufa lama", troom);
		if(obj) {
			tell_room(troom,HIY+obj->name() + "�߽������£�����ذ��Ź����ˡ�\n"NOR);
			destruct(obj);
			delete("exits/northup");
			if(room) {
				room->delete("exits/southdown");
				room->set("item_desc", ([
                	"gate": "ͭ���Ĵ��ţ����ǹ��ŵģ��������(pull)�š�\n",
                	"��": "ͭ���Ĵ��ţ����ǹ��ŵģ��������(pull)�š�\n",
        			]) );
			}
	set("long", @LONG
���ݾ��������ߴ�����ɽ�ţ�һ�����Ƕͭ���Ĵ��ų����ţ����ϵİ�
��ͭ���������������ġ���Լʮ���ɵ���¥��ɽ�������Ϊ�������ɣ����о�
���ĸ����м�����Ͻ�����


                        ������������������
                        ��  ��  ��  ��  ��
                        ������������������                

�����֣��Ե����ɷǷ��������Ը���һֻ�������š�Զ����Լ����ɽ����
��������ֻ��ѻ�����Ҽ�׷ɣ������������׵ĸо���
LONG
	);
		}
	}
	else
		call_out("closedoor", 15, me);
}

int valid_leave(object me, string dir)
{
	if (dir == "northup" && is_wanted(me))
		return 0;
	return ::valid_leave(me, dir);
}

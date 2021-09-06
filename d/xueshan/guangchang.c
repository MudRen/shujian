 // guangchang.c  ��ǰ�㳡
 // by dubei

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short","��ǰ�㳡");
        set("long",@LONG 
���Ǵ��ǰ�Ĺ㳡����Բһ�ٶ��ɣ�һɫ����ʯ�����أ��������µ���
������ææµµ�Ĵ���ͣ�������������������һ��һ��ͷ�ĿĽ����ȥ��
����ﴫ���������Ͼ��ͷ����ô��������һ��Ũ�������ζ��Ʈɢ�ڿ��С�
LONG);
	set("exits", ([ 
  		"northup" : __DIR__"dadian",
		"west" :__DIR__"huilang1",
		"east" :__DIR__"huilang2"
              ]));

        set("objects", ([__DIR__"npc/heilinbofu" : 1,
                         __DIR__"npc/fanseng" : 1,
                         __DIR__"npc/xiangke" : 1,]));

        "/clone/board/xueshan_b"->foo();

        set("outdoors", "ѩɽ");
 
	setup();

}
void init()
{
        if(query("exits/southdown")) {
        set("item_desc", ([
                "gate": "���Ⱥ���Ĵ��������೨���š�\n",
                "��": "���Ⱥ���Ĵ��������೨���š�\n",
        ]) );
        add_action("do_pull", "pull");
	}
	else {
        set("item_desc", ([
                "gate": "���Ⱥ���Ĵ��Ž����ر��ţ��������(pull)�š�\n",
                "��": "���Ⱥ���Ĵ��Ž����ر��ţ��������(pull)�š�\n",
        ]) );
        add_action("do_pull", "pull");
	}
}

int do_pull(string arg)
{
        object room, me;

        if( arg=="gate" || arg == "��") {
                me = this_player();
                if(query("exits/southdown")) {
                        write("���Ѿ��ǿ��ŵģ�\n");
		}
		else {
                set("exits/southdown", __DIR__"shanmen");
	        set("item_desc", ([
       	         "gate": "���Ⱥ���Ĵ��������೨���š�\n",
       	         "��": "���Ⱥ���Ĵ��������೨���š�\n",
       		 ]) );
                message_vision(HIY"$N������������\n"NOR, me);
                if( room = find_object(__DIR__"shanmen") ) {
                        tell_room(room,HIY"���Ŵ�������˿�����\n"NOR);
	                room->set("exits/northup", __FILE__);
			call_out("closedoor", 15, room);
                }
		}
	}
	else {
                 write("��Ҫ��ʲô��\n");
	}
	return 1;
}

int closedoor(object room)
{
	tell_room(room,HIY"����������ǰ�Ѵ��Ź����ˡ�\n"NOR);
        set("item_desc", ([
                "gate": "���Ⱥ���Ĵ��Ž����ر��ţ��������(pull)�š�\n",
                "��": "���Ⱥ���Ĵ��Ž����ر��ţ��������(pull)�š�\n",
        ]) );
	room->delete("exits/northup");
	delete("exits/southdown");
}
// cool 980725
// Modify By River 98/12
//COOL@SJ,9908
//tangfeng@SJ,2004

#include <ansi.h>
#include <room.h>
inherit ROOM;
#define QUESTDIR1 "quest/�����˲�/�貨΢��ƪ/"
void create()
{
        set("short", "ʯ����");
        set("long", @LONG
������ʯ�����ˣ����������ģ�ʲôҲ������������ⶼ���ſڵ�һ��
����ʯ��ס�ˣ�ֻ��͸������ʯ����͸���������⣬�������������ӡ�
LONG
        );

        set("item_desc", ([
              "yan" : "һ�����ʯ�����������ƿ�!��\n",
        ]));
        setup();
}

void init()
{   
       object ob,obj;
       ob=this_player();

       if (interactive(ob)
        && !present("qingnian nanzi", this_object())
        && !present("duan yu",this_object())
        && ob->query_temp(QUESTDIR1+"kill_duan")
        && ob->query(QUESTDIR1+"pass_shanlu")
        && !ob->query(QUESTDIR1+"over")){
		     obj=new(__DIR__"npc/dy");
         obj->move(this_object());
       }
       if (userp(ob)) {
	        remove_call_out("close");
          call_out("close", 2, this_object());
          }
	  add_action("do_tui", "tui");
    add_action("do_tui", "push");
}

int do_tui(string arg)
{
       int i;
        i = this_player()->query("neili");
       if( !arg || arg!="yan" ) 
         return notify_fail("��Ҫ��ʲô��\n");
        message_vision(HIY"$Nվ���ź󣬰�˫�Ʒ������ϣ����������һ������˫��һ���������һ����������\n"NOR, this_player());
       if ( i >=800 ){
        message_vision(RED"$Nֻ��һ����죬��ʯ�������ƿ��ˣ�\n"NOR, this_player());
        set("exits/out", __DIR__"muwu2");
        this_player()->add("neili",-800);
        remove_call_out("close");
        call_out("close", 5, this_object());
        }
       else {
        message_vision("$Nȴ����ʯ��˿����������$N��������������\n", this_player());
        this_player()->set("neili",0);
        }
    return 1;
}

void close(object room)
{
      message("vision",YEL"��ʯ�����ƶ�����ʯ���ٴη�ס�ˡ�\n"NOR, room);
      room->delete("exits/out");
}

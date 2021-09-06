// jiashan1.c

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIM"��ɽ"NOR);
         set("long",@LONG
�����ܾ�û�˵��������ˣ���Χ�Ӳݴ�������ľ��������ͷ������ղ���
�����Ĵ��϶��feng�����Ҳ���ľ������һ������ʯ�飬����һ��⻬�Ĵ�ʯ
ͷ��shi���ر�����עĿ��
LONG
    );
	 set("outdoors","���");
		 
         set("item_desc", ([
             "shi" : "����ʯͷ���������ʲô��������֪�ܲ����ƿ�(move)����\n",
	     "feng" :BLU"һ���ں����ķ�϶����������꣨zuan����ȥ��\n"NOR,
	 ]));

	 setup();
}

void init()
{
    add_action("do_move", "move");
    add_action("do_move", "tui");
    add_action("do_zuan", "zuan");
}

int do_move(string arg)
{
        int j,exp;
        exp = this_player()->query("combat_exp");
	j=this_player()->query("jing");
        if( !arg || arg!="shi" ) {
                write("����Ҫ��ʲô��\n");
                return 1;
        }
        message_vision(YEL"$N��������˿����������ƶ���ʯͷ��\n\n"NOR, this_player());
        if ( exp > 1000 && j >= 90) {
          message_vision(HIG"ֻ����ʯͷ������ǰ�ƣ�$N�Ѵ�ʯͷ�ƿ��ˣ�����һ���ں����Ķ��ڡ�\n"NOR, this_player());
          set("exits/enter", __DIR__"mishi");
          this_player()->set("jing",j-30);
          remove_call_out("close");
          call_out("close", 5, this_object());
        }
        else {
          message_vision(HIG"$N�۵��������������Ǵ�ʯͷ����û�ж���\n"NOR, this_player());
          this_player()->set("jing",10);
        }
        return 1;
}

void close(object room)
{
        message("vision",HIY"��ʯͷ������ԭλ���ֵ�ס�˶��ڡ�\n"NOR, room);
        room->delete("exits/enter");
}

int do_zuan(string arg)
{
        object me;
        me = this_player();

        if (arg !="feng") 
        return notify_fail("���������갡��\n");
        if( arg=="feng"){            
            write(HIG"��ת������������϶���꣬�����ش����˷�϶��\n\n"NOR);
            me->start_busy(2);
            me->move(__DIR__"jiashan");
        }
        return 1;
}

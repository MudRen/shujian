// Room: hubian.c ����

#include <ansi.h>

#define SHIP_TO __DIR__"jiaopan"

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�ߵ����С·�Ѿ����˾�ͷ��һ�������Ƶ��ͱ�(qiaobi)������ǰ��̧ͷ
��ȥ���ͱڼ��������ƣ�ʯ�ڹ⻬���޿���Ե֮��������ֻ�ܻ�ͷ�ˡ�
LONG
        );

        set("exits", ([
                "south" : __DIR__"xiaolu3",
        ]));

        set("item_desc", ([
                "qiaobi" : "����ͱڰεض��𣬼�ʹ��Գ�����Ҳ������ȥ��\n",
        ]));

        set("outdoors", "ѩɽ");
        set("coor/x",-240);
  set("coor/y",130);
   set("coor/z",0);
   setup();
}

void init()
{
        add_action("do_yell", "yell");
}

void check_trigger(object me)
{
        object room;
        object thisroom = this_object();

        if(!query("exits/enter") ) {
                if( !(room = find_object(__DIR__"tengkuang")) )
                        room = load_object(__DIR__"tengkuang");
                if( room = find_object(__DIR__"tengkuang") ) {
                        if((int)room->query("yell_trigger")==0 ) {
                                room->set("yell_trigger", 1);
                                set("exits/enter", __DIR__"tengkuang");
                                room->set("exits/out", __FILE__);
                                message("vision", "һ���ִ������׹�Ÿ����ٿ��������л��������������������ڵ��ϡ�\n", thisroom);
                                message("vision", "һ���ִ������׹�Ÿ����ٿ��������л��������������������ڵ��ϡ�\n", room);
                                remove_call_out("on_board");
                                call_out("on_board", 15, me);
                        }
                        else
                                message("vision", "ֻ���ͱ������и�ɳ�Ƶ�ɤ�Ӻ������ȡ�����������̫Զ���������\n", thisroom);
                }
                else
                        message("vision", "ERROR: Tengkuang Not Found\n", thisroom);
        }
        else 
                message("vision", "���˰���û����������ŷ�����ǰ����һ���ϴ���ٿ�\n", thisroom);
}

void on_board(object me)
{
        object room;

        if( !me || !query("exits/enter") ) return;

        message("vision", "����һ�����ٿ�����ҡ�����˼��£�ȽȽ��������������\n", this_object());

        if( room = find_object(__DIR__"tengkuang") )
        {
                room->delete("exits/out");
                message("vision", "����һ�����ٿ�����ҡ�����˼��£�ȽȽ��������������\n", room);
        }
        delete("exits/enter");
        remove_call_out("no_board_two");
        call_out("on_board_two", 10, me);
}

void on_board_two(object me)
{
	if (!me) return;
           message_vision("���⸩�����Ѿ��������С���ӡ�һ��ɽ�紵���ٿ��ڿ���ҡ��������\n"+
                          "$N��æץ���ٿ���ɫ�ŵò԰ס�\n",me);
           remove_call_out("arrive");
           call_out("arrive", 10);
}

void arrive()
{
        object room;

        if( room = find_object(__DIR__"tengkuang") )
        {
                room->set("exits/out", SHIP_TO);
                message("vision", "һ����ɮ��ɳ�Ƶ����������������µ����������ɡ���������δ�䣬�ٿ��Ѿ������ȵ�ͣס�ˡ�\n", room);
        }
        remove_call_out("close_passage");
        call_out("close_passage", 20);
}

void close_passage()
{
        object room, *ob;
        int i;

        if( room = find_object(__DIR__"tengkuang") ) {
                room->delete("exits/out");

                tell_room(room, "��ɮ���ͷ��ĵ������������ɣ���ɵ�˶�������������\n", ({}));
                ob = all_inventory(room);
                for(i = 0; i < sizeof(ob); i++) {
                        if (userp(ob[i])) {
                                if (!living(ob[i])) tell_room(room, "��ɮ��$Ņ�����ٿ�\n", ob[i]);
                                else tell_room(room, "$N˫�Ȳ���������ʹ��������ɮ�ܳ����ٿ�\n", ({ob[i]}));
                                ob[i]->move(SHIP_TO);
                                if (!living(ob[i])) tell_room(SHIP_TO, ob[i]->name() + "��̧�����ٿ�\n", ({ob[i]}));
                                else tell_room(SHIP_TO, ob[i]->name() + "��ɫ�԰ף�˫��������������ɮһ��һ�Ҽܳ����ٿ�\n", ({ob[i]}));
                        }
                }
                message("vision", "�ٿ�ɿ�Ľ�����ȥ��һ�����ʧ�����С�\n", room);
                room->delete("yell_trigger"); 
        }
}

int do_yell(string arg)
{
        object me = this_player();

        if (!arg) return 0;

        if (arg == "tengkuang")arg = "�ٿ�";
	if (arg != "�ٿ�") arg = "��";

        if (me->query("age") < 16  )        
                message_vision("$Nʹ�����̵���������һ����������" + arg + "��\n", me);
        else if (me->query("neili") > 500)
                message_vision("$N���˿�����һ��������" + arg + "������������ƽ�͵�ԶԶ���˳�ȥ��\n", me);
        else
                message_vision("$N������������Хһ����������" + arg + "����\n", me);
        if (arg == "�ٿ�")
        {
                check_trigger(me);
                return 1;
        }
        else
                message_vision("ɽ�ȼ�ԶԶ����һ���������" + arg + "��������\n", me);
        return 1;
}


void reset()
{
        object room;

        ::reset();
        if (room = find_object(__DIR__"tengkuang"))
                room->delete("yell_trigger"); 
}

int valid_leave(object me, string dir)
{
        if( dir =="enter" ){
        if( me->query("can_ride")){
          return 0;
          }       
        if(me->query_temp("ride_horse"))
        return notify_fail("��Ҫ�������ٿ𣬲��·��ˣ�\n");
        }
        return ::valid_leave(me, dir);
}


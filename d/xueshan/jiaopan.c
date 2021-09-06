// Room: jiaopan.c ����

#include <ansi.h>

#define SHIP_TO __DIR__"hubian"

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��ǰ�Ǹ���Բ��ʮ�ɵ�ƽ̨���ǽ���ɽ�ƣ������˹�������ɵġ�ƽ̨��
������һ������̣���������һ�����Ÿ��޴���ٿ�(tengkuang)�� һ���ߴ�
�ķ�ɮ(fanseng)������ȥ��ָ�������ˡ�
LONG
        );

        set("exits", ([
                "northwest" : __DIR__"houzidong",
        ]));

        set("item_desc", ([
          "tengkuang" : "����޴���ٿ�����ȥ�ġ�����˲������⣬���ⱻ���۴ֵ�����������ס��\n",
          "fanseng" : "���������⣬��Ϊ����紵��ɹ����ɫ����͸�ڡ������������ں����ɽ����ȴ�Եĺ����ں���\n" +
                      "��������к�(zhaohu)�Ϳ��԰�������ɽ��\n"
        ]));

        set("outdoors", "ѩɽ");
        set("coor/x",-250);
  set("coor/y",150);
   set("coor/z",20);
   setup();
}

void init()
{
        add_action("do_zhaohu", "zhaohu");
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
                                message("vision", "��ɮ��������˳�����ٿ���Ⱥ�ߵ�����������ȥ�ɡ�\n", thisroom);
                                message("vision", "��ɮ��������˳�����ٿ���Ⱥ�ߵ�����������ȥ�ɡ�\n", room);
                                remove_call_out("on_board");
                                call_out("on_board", 15, me);
                        }
                        else
                                message("vision", "��ɮ���˵�ͷ˵���������������ˣ������һ���ɡ�\n", thisroom);
                }
                else
                        message("vision", "ERROR: Tengkuang Not Found\n", thisroom);
        }
        else 
                message("vision", "��ɮ���˵�ͷ�������ã�����Ҫ����ȥ������ȥ�ɡ�\n", thisroom);
}

void on_board(object me)
{
        object room;

        if( !me || !query("exits/enter") ) return;

        message("vision", "��ɮ����һ�ƣ����ٿ�����ƽ̨�����̸����������ɣ��ٿ�һ����������ȥ��\n", this_object());

        if( room = find_object(__DIR__"tengkuang") )
        {
                room->delete("exits/out");
                message("vision", "��ɮ����һ�ƣ����ٿ�����ƽ̨�����̸����������ɣ��ٿ�һ����������ȥ��\n", room);
        }
        delete("exits/enter");
        remove_call_out("no_board_two");
        call_out("on_board_two", 10, me);
}

void on_board_two(object me)
{
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
                message("vision", "�ٿ������Խ��Խ���������ڵ�һ�����˵أ����˶����˿ڳ��������ŵ���Ҳ��֮����������\n", room);
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

                tell_room(room, "�ٿ�һ�ᣬ�ƺ�Ҫ�����������æ���ٿ��д��˳�����\n", ({}));
                ob = all_inventory(room);
                for(i = 0; i < sizeof(ob); i++) {
                        if (userp(ob[i])) {
                                if (!living(ob[i])) tell_room(room, "$N����б���ٿ��й��˳�ȥ��\n", ob[i]);
                                else tell_room(room, "$N��æ���ٿ��д��˳�ȥ��\n", ({ob[i]}));
                                ob[i]->move(SHIP_TO);
                                if (!living(ob[i])) tell_room(SHIP_TO, ob[i]->name() + "����б���ٿ��й��˳�����\n", ({ob[i]}));
                                else tell_room(SHIP_TO, ob[i]->name() + "��ææ���ٿ��д��˳�����\n", ({ob[i]}));
                        }
                }
                message("vision", "�ٿ�ɿ������������һ�����ʧ�����С�\n", room);
                room->delete("yell_trigger"); 
        }
}

int do_zhaohu(string arg)
{
        object me = this_player();

        if (!arg) return 0;

        if (arg == "fanseng") 
        {
                message_vision("$N��ǰ���������ĺͷ�ɮ���˸��к���\n", me);
                check_trigger(me);
                return 1;
        }
        else {
                message_vision("$N�������������֣���ι�����Ƕ��������������˶�û��ǡ�\n", me);
        }
        me->start_busy(1);
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


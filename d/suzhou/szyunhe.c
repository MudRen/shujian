#include <ansi.h>
string look_sign();
int do_go(string);
void check_trigger();
void on_board();
void arrive();
void close_passage();
int do_yell(string);
void reset();
inherit ROOM;

mapping *sign=({
/*    ([  "name":"����",
        "id":"bj",
        "file":__FILE__,
        "value":10000,
	"time":20
    ]),*/
    ([  "name":"����",
        "id":"yz",
        "file":__DIR__"yzyunhe",
"value":2500,
	"time":10
    ])
});

void create()
{	set("short", "�˺�");
	set("long", @long
�����ǹ��ϵ��˺ӵ���ͷ�ߣ�ֻ�������˺��������ʣ������ݳ��ﴩ����
�˺ӵ������������ݵ�Ѱ�����ռң������ݵĳ��������õĽ�ͨ���߾���
���ˡ�ֻ��������һλ�ϴ��򣬼����߹�������������ӭ����(sign)��
long);
    set("exits",([
    "southeast" : __DIR__"xidajie1",
    ]));
    set("item_desc", ([
        "river" : "��������һҶС�ۣ�Ҳ��(yell)һ�����Ҿ���������\n",
        "sign" : (: look_sign :)
    ]));

    set("outdoors", "suzhou");
    setup();
}

void init()
{
    add_action("do_yell", "yell");
//     add_action("do_go", "qu");
}

string look_sign()
{
    string str="";
    int i=sizeof(sign);

    while (i--) {
        str += sign[i]["name"];
        str += "(" + sign[i]["id"] + ") ";
        str += MONEY_D->price_str(sign[i]["value"]) + "\n";
    }

    return str;
}

void do_move(object ob, int i)
{
    ob->enable_player();
    ob->delete_temp("block_msg/all");
    write("�յ�վ���ˡ�\n");
    ob->move(sign[i]["file"]);
    tell_room(environment(ob), ob->name() + "�Ӵ�������������\n", ({ob}));
}

int do_go(string arg)
{
    object ob=this_player();
    int i=sizeof(sign);

    if (!arg) return 0;
    if (ob->is_busy() || ob->is_fighting())
        return notify_fail("����æ���أ�\n");
    while(i--) {
        if (arg == sign[i]["id"]) {
            switch (MONEY_D->player_pay(ob, sign[i]["value"])) {
                case 0:
                    return notify_fail("��⵰��һ�ߴ���ȥ��\n");
                case 2:
                    return notify_fail("����Ǯ��\n");
            }
	    message_vision("$N������ȥ" + sign[i]["name"] + "�Ĵ���\n", ob);
	    ob->disable_player("<��;��>");
	    ob->set_temp("block_msg/all", 1);
	    ob->move(__DIR__"onroad");
            call_out("do_move", sign[i]["time"], ob, i);
            return 1;
        }
    }
    return notify_fail("��Ҫȥ���\n");
}

void check_trigger()
{
    object room;

    if(!query("exits/enter") ) {
        if( !(room = find_object(__DIR__"duchuan")) )
            room = load_object(__DIR__"duchuan");
        if( room = find_object(__DIR__"duchuan") ) {
            if((int)room->query("yell_trigger")==0 ) {
                room->set("yell_trigger", 1);
                set("exits/enter", __DIR__"duchuan");
                room->set("exits/out", __FILE__);
                message("vision", "һҶ���ۻ�����ʻ�˹�����������һ��̤��"
                    "����ϵ̰����Ա�˿�\n���¡�\n", this_object() );

                message("vision", "������һ��̤�Ű���ϵ̰����γ�һ������"
                    "�Ľ��ݡ�\n", room);
                remove_call_out("on_board");
                call_out("on_board", 15);
            }
            else
                message("vision", "ֻ���ú��治Զ�����������������"
                  "�����æ���š�����\n",this_object() );
        }
        else
            message("vision", "ERROR: boat not found\n", this_object() );
    }
    else 
        message("vision", "����һֻ�ɴ��ϵ�������˵�������������أ������ɡ�\n",
            this_object() );
}


void on_board()
{
    object room;

    if( !query("exits/enter") ) return;

    message("vision", "������̤�Ű��������������һ�㣬�������˺�ʻȥ��\n",
        this_object() );

    if( room = find_object(__DIR__"duchuan") )
    {
        room->delete("exits/out");
       message("vision", "������̤�Ű���������˵��һ��������ඡ���"
            "���һ�㣬������\n�˺�ʻȥ��\n", room );
    }
    delete("exits/enter");

    remove_call_out("arrive");
    call_out("arrive", 20);
}

void arrive()
{
    object room;
    if( room = find_object(__DIR__"duchuan") )
    {
        room->set("exits/out", __DIR__"huzhongdao");
        message("vision", "����˵���������ϰ��ɡ����漴��һ��̤�Ű�"
            "���ϵ̰���\n",room );
    }
    remove_call_out("close_passage");
    call_out("close_passage", 20);
}

void close_passage()
{
    object room;
    if( room = find_object(__DIR__"duchuan") ) {
        room->delete("exits/out");
        message("vision","������̤�Ű����������ѱ���ʻ���˺ӡ�\n", room);
        room->delete("yell_trigger"); 
    }
}

int do_yell(string arg)
{
// string dir;

    if( !arg || arg=="" ) return 0;

    if( arg=="boat" ) arg = "����";
	if (arg != "����") arg = "��";
    if( (int)this_player()->query("age") < 16 )
        message_vision("$Nʹ�����̵���������һ������" + arg + "��\n",
            this_player());
    else if( (int)this_player()->query("neili") > 500 )
        message_vision("$N���˿�����һ����" + arg + "������������ƽ�͵�ԶԶ��"
            "�˳�ȥ��\n", this_player());
    else
      message_vision("$N������������Хһ������" + arg + "����\n",
            this_player());
    if( arg=="����")
    {
        check_trigger();
        return 1;
    }
    else
        message_vision("������ԶԶ����һ���������" + arg +
            "��������\n", this_player());
    return 1;
}

void reset()
{
    object room;

    ::reset();
    if( room = find_object(__DIR__"duchuan") )
        room->delete("yell_trigger"); 
}


// /d/hmy/dadian.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
���ô�ֻ��������������ʮ���ߣ�����ȴ���������ߣ����˱˶˸�
��һ���Σ����������Ե��ƽ����Ƴɣ����ɫ˿�����˾��������������м�
һ���մӴ�֮�������̫�����Ǿ�������������צ�������������Χ׺��
�������顢��ʯ���������䱦ʯ�����þ�����ⱦ����
LONG
	);

	set("exits", ([ 
          "north" : __DIR__"cddian",
	  "west" : __DIR__"changlang",
	  "east" : __DIR__"changlang6",
	  "south" : __DIR__"changlang5", 
]));

	setup();
}

/*
void init()
{


    object book, me;
    me = this_player();
    add_action("do_move", "move");
    if ((objectp(book=present("dadian",me)))) {
        remove_call_out("buqun_rob");
        call_out("buqun_rob", 1, me, book);
    }
}

int do_move(string arg)
{
        int n;
        n = this_player()->query("neili");
        if( !arg || arg!="chair" ) {
                write("����Ϊ����԰�Ķ����Ŵ�������\n");
                return 1;
        }


        message_vision(
        "$N�����ھ���������������һ�ᡣ\n", this_player());

        if (n>=1000) {
        message_vision(
        "��Ȼ�ص�һ���죬��������ԭ���и��ص���\n", this_player());
        set("exits/down", __DIR__"dedao");
        this_player()->set("neili",n-200);
        remove_call_out("close");
        call_out("close", 5, this_object());
        }
        else {
        message_vision(
        "$N���һ����˫��ƴ���Ͱ�����Σ�������᲻��������$N����������ǿ��\n", this_player());
        this_player()->set("neili",0);
        }

        return 1;
}

void close(object room)
{
        message("vision","�����κ�Ȼ��λ���ֶ�ס�˵ص���\n", room);
        room->delete("exits/east");
}
*/

// Room : /d/wudang/clbinyuan1.c ���ֱ�Ե
// By lius 99/8

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","���ֱ�Ե");
        set("long", @LONG
ǰ������·��Ѱ��ֻ��һƬ�ޱ������ï�ܴ��֣��紵Ҷ�䡰����ɳɳ��
������ҡ��Ҹ����У�ż������һ��������Ұ���ײеĺ�Х������Ȼһ������
����Щ���������ˡ�
LONG                           
        );
        set("outdoors", "�䵱");

        set("exits", ([               
            "northwest" : __DIR__"gudi",
        ]));
        setup();

}

void init()
{
         add_action("do_tou", ({"tou","zuan"}));
}

int do_tou(string arg)
{
         object me;
         me = this_player(); 
         if ( arg != "conglin" ) return 0;
  
         message_vision("$N����һ����Ц������Ͷ����֣����˽�ȥ��\n", me);
         me->move(__DIR__"conglin"+(random(3)+1));
         tell_room(environment(me), me->name() + "�Ӵ��ֱ�Ե���˽�����\n", ({ me }));
         return 1;
}

